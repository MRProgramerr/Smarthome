#include "csvfile.h"
#include <sstream>
#include <algorithm>
using namespace data;



CsvFile::CsvFile(std::istream &input)
{
    // checks if input stream is empty
    if (input.peek() == -1)
    {
        loadFail = true;
    }

    bool endComma = false;

    // initialises content of csv input into the 2d vector
    // while there is input
    while(input){

        // creates a string
        std::string str;
        // extracts string from input
        if(!getline(input,str))break;
        // creates a string stream
        std::istringstream istr(str);
        // creates a second vector to hold the values from the csv
        std::vector<std::string> vec2;
        // a second string for comparison
        std::string str2 = str;

        // finds if there is a comma at the end of the line
        int length = str.length();
        if(str.at(length -1) == ',')
         {
              endComma = true;
         }

        // checks if the last input value is quoted
        // last value is a special case since is ends with a newline and not a commma
        bool lastQuoted = false;
        if(str.at(length-1) == '"')
        {
            lastQuoted = true;
        }


        // while there is a string stream
        while(istr)
        {

            bool quoted = false;

            int length = str2.length();

            // new string to hold double quote string
            std::string newstring = "";

            // if the first character in the csv string are quotes
            if(str2.at(0) == '"')
            {
                // loop through the string
                for (int i = 0; i < length; i++)
                {
                    // whenever quotes are found
                    if(str2.at(i) == '"')
                    {
                        // if these are internal quotes
                        if(i != length-1 && str2.at(i+1) == '"')
                        {
                            // they are not the end quotes
                            quoted = false;
                            // adds internal quotes to string
                            newstring += '"';
                            // skips next quote
                            i = i + 2;
                        }
                        // if these are the end quotes
                        if(quoted == true)
                        {
                            // checks if there is an empty white space after the quote
                            if(i != length -1 && str2.at(i+1) == ' ')
                            {
                                loadFail = true;
                            }
                            // left over characters (",) in the string are skipped
                            if(i != length-1)
                            {
                                 i = i + 2;
                            }
                            // the left over characters in the string are skipped
                            std::string str3 = str2;
                            // second string is set to be empty
                            str2 = "";
                            // adds all content of the string with the quoted csv removed from str2
                            for(; i< length; i++)
                            {
                                // adds everything from str3 but the quoted csv
                                str2 += str3.at(i);
                            }
                            // str2 will now be sent through the process again with the next csv at the front
                            break;
                        }
                    }

                    // the starter double quotes have gone through
                    quoted = true;
                    // leaves out the double quote
                    if(str2.at(i) != '"')
                    {
                        // checks for new line black slashes
                        if(str2.at(i) == '\\' && str2.at(i -1) != '\\' && str2.at(i +1) != '\\' && str2.at(i +1) == 'n')
                        {
                            newstring += '\n';
                            i = i + 2;
                        }

                        // adds the double quoted csv to a newstring with double quotes removed
                         newstring += str2.at(i);
                    }
                }
            }

            // if the first character csv string are not quotes
            else
            {
                // if the first character csv string is a white space
                if(str2.at(0) == ' ')
                {
                    // if the character after it is a quote
                    if(str2.at(1) == '"')
                    {
                        // there is a whitespace before a quote
                        loadFail = true;
                    }
                }
                // loop through string
                 for (int i = 0; i < length; i++)
                 {
                     // until it finds the seperation comma
                     if(str2.at(i) == ',' && endComma == false)
                     {
                         // new string to copy current string
                         std::string str3 = str2;
                         // current string is made empty
                         str2 = "";
                         // the comma is taken out
                         i = i + 1;
                        // removes the first csv value from the front of the string
                         for(; i< length; i++)
                         {
                             str2 += str3.at(i);

                         }
                         break;
                     }

                 }

            }



            // extracts string from input where a comma is found
          if(!getline(istr, str, ',')) break;

          if(quoted == false)
          {
              // push the string from the input without the comma into the vector
              vec2.push_back(str);
          }
          if(quoted == true)
          {

              // the new line containing the double quoted text is pushed to the vector
              // the str with the incorrect syntax gets skipped
             vec2.push_back(newstring);

              int strLength = str.length();
              bool comma = false;

              // If the value does not end with a '"' that mean there is a comma inside the quote that is part of the string
              if(str.at(strLength-1) != '"')
              {
                   comma = true;
              }

              // If there was a comma as part of the string, the getline would've seperated it (e.g. "header,1" = becomes ("header) (1"))
              // If it is the last value then it is seperated by newline instead of new comma, found by checking if the last value was quoted
              if(comma == true || lastQuoted == true)
              {
                  // the string splits again, skipping over the seperated value
                   if(!getline(istr, str, ',')) break;
              }
          }
        }
        // push the contents of vector 2 into the 2d vector
        vec.push_back(vec2);
    }

    // checks if there are rows with extra columns
    for (int i = 0; i < vec.size(); i++)
    {
        if(vec[i].size() > vec[0].size())
        {
            loadFail = true;
        }
    }

    // checks if there are rows with missing columns
    for (int i = 0; i < vec.size(); i++)
    {
        // also checks if there was a comma at the end of the line, indicating empty field at end of line
        if(vec[i].size() < vec[0].size() &&  endComma == false)
        {
            loadFail = true;
        }
    }
}

int CsvFile::numberOfColumns() const
{
    if(loadFail == true)
    {
        return(-1);
    }

    int col = vec[0].size();

    return(col);

}

int CsvFile::numberOfRows() const
{
    //
    if(loadFail == true)
    {
        return(-1);
    }
    else
    {

       int row = vec.size() - 1;

       int length = vec[row][0].length();
       // checks if its last row is crlf
       if(vec[row][0].at(0) == ' ')
          {
            // if the first character in the last row is a white space
            bool crlf {true};

            // makes sure that it found an empty row and not a value starting with white spaces
            for (int i = 0; i < length; i++)
            {
                // when it finds a character in the value that is not a white space
                if(vec[row][0].at(i) != ' ')
                {
                    // last row is not crlf
                    crlf = false;
                }
            }
            // if last row is crlf
            if(crlf == true)
            {
                // the size of the row is lowered to become accurate
                row --;
            }

        }

       return(row);
    }
}

std::string CsvFile::at(int row, int column) const
{
    if(loadFail == true)
    {
        return("");
    }
    // checks if the input row and columns are greater than the max row and columns in the vector
    // or if they are zero
    if(row  > numberOfRows() || column > numberOfColumns() || row == 0 || column == 0)
    {
        return("");
    }

    // checks for an empty column
    // checks if the amount of columns in the specified row is less than the specified amount of column
    if(vec[row].size() < column)
    {
        return("");
    }

    else
    {
        // return the string at the desired column and row
        return(vec[row][column-1]);
    }
}

std::string CsvFile::headerAt(int column) const
{
    if(loadFail == true)
    {
        return("");
    }
    // checks if the input columns are greater than the max columns in the vector
    if(column  > numberOfColumns() || column == 0)
    {
        return("");
    }
    else
    {
        // returns the first value in the desired column
        return(vec[0][column - 1]);
    }
}

int CsvFile::columnIndexOf(const std::string &columnName) const
{

  if(loadFail == true)
  {
      return(-1);
  }
  else
  {

    // loops through all columns in the vector
    for (int i = 0; i < numberOfColumns(); i++)
    {
        // if the header of a column is equal to the columnName
        if(vec[0][i] == columnName)
        {
              // return the index
             return(i + 1);
        }
     }
    // if the columnName was not found in any of the headers
    return(0);
  }


}
