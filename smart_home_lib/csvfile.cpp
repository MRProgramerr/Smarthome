#include "csvfile.h"
#include <sstream>
#include <algorithm>
using namespace data;



CsvFile::CsvFile(std::istream &input)
{
    // checks if input stream is empty
    if (input.peek() == -1)
    {
        isEmpty = true;
    }


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

        // while there is a string stream
        while(istr){

            bool quoted = false;

            int length = str2.length();

            // new string to hold double quote string
            std::string newstring = "";

            if(str2.at(0) == '"')
            {
                for (int i = 0; i < length; i++)
                {
                    if(str2.at(i) == '"')
                    {
                        if(quoted == true)
                        {
                            newstring += '"';
                            i = i + 2;
                            std::string str3 = str2;
                            str2 = "";
                            for(; i< length; i++)
                            {
                                str2 += str3.at(i);
                            }
                            break;
                        }
                    }
                    quoted = true;
                    newstring += str2.at(i);
                }
            }

            // extracts string from input until a comma is found
          if(!getline(istr, str, ',')) break;

            if(quoted == false)
            {
                // push the string from the input without the comma into the vector
                vec2.push_back(str);
            }
            if(quoted == true)
            {
               vec2.push_back(newstring);
               if(!getline(istr, str, ',')) break;
            }
        }
        // push the contents of vector 2 into the 2d vector
        vec.push_back(vec2);
    }

}

int CsvFile::numberOfColumns() const
{
    if(isEmpty == true)
    {
        return(-1);
    }

    // if the csv file is not empty
    else
    {
        //
       int col = vec[0].size();
       return(col);
    }
}

int CsvFile::numberOfRows() const
{
    //
    if(isEmpty == true)
    {
        return(-1);
    }
    // if the csv file is not empty
    else
    {
       //
       int row = vec.size() - 1;
       return(row);
    }
}

std::string CsvFile::at(int row, int column) const
{
    //
    if(isEmpty == true)
    {
        return("");
    }
    // checks if the input row and columns are greater than the max row and columns in the vector
    //
    if(row  > vec.size() - 1 || column > vec[0].size() + 1 || vec[row][column-1] == "")
    {
        return("");
    }
    // if the input row and columns are not out of bound and the input csv file did not fail to load
    else
    {
        // return the string at the inputted column and row
        return(vec[row][column-1]);
    }
}

std::string CsvFile::headerAt(int column) const
{
    //
    if(isEmpty == true)
    {
        return("");
    }
    // checks if the input columns are greater than the max columns in the vector
    // since vector index start at 0 but the user input index starts at 1, 1 is taken away from the user input to match the vector index
    if(column -1 > vec[0].size())
    {
        return("");
    }
    // if the input row and columns are not out of bound and the input csv file did not fail to load
    else
    {
        // returns the first value in the desired column
        // first value in desired column is the header of that column
        return(vec[0][column - 1]);
    }
}

int CsvFile::columnIndexOf(const std::string &columnName) const
{

  // if CSV file failed to load
  if(isEmpty == true)
  {
      return(-1);
  }
  else
  {
      // gets the amount of columns
      int col = vec.size();

    // loops through all columns in the vector
    for (int i = 0; i < col; i++)
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
