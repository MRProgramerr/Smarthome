#include "csvfile.h"
#include <sstream>

using namespace data;

// creates 2d vector
std::vector<std::vector<std::string>> vec;

CsvFile::CsvFile(std::istream &input)
{
  // initialises content of csv input into the 2d vector

  // while there is input
  while(input){
        // creates a string
        std::string str;
        // if string is not found in the input
        if(!getline(input,str))
        {
            // break the loop
            break;
        }
        // creates a string stream
        std::istringstream istr(str);
        // creates a second vector to hold the values from the csv
        std::vector<std::string> vec2;

        // while there is a string stream
        while(istr){
            // if there is not a comma seperated string value in the input
            if(!getline(istr, str, ','))
            {
                // break the loop
                break;
            }
            // push the value string from the input into the vector
            vec2.push_back(str);
        }
        // push the contents of vector 2 into the 2d vector
        vec.push_back(vec2);
    }
}

int CsvFile::numberOfColumns() const
{
    // vector.size shows the number of columns in a 2d vector
    int col = vec.size();
    // if the amount of columns is zero, this means the csv file failed to load
    if(col == 0)
    {
        return(-10);
    }
    // if the csv file did not fail to load, it has a number of columns to return
    else
    {
       return(col);
    }
}

int CsvFile::numberOfRows() const
{
    // vector[0].size shows the number of rows in a 2d vector
    int row = vec[0].size();
    // if the amount of row is zero, this means the csv file failed to load
    if(row == 0)
    {
        return(-10);
    }
    // if the csv file did not fail to load, it has a number of rows to return
    else
    {
       return(row);
    }
}

std::string CsvFile::at(int row, int column) const
{
    // checks if vector is empty to see if the input failed to load
    if(vec.size() == 0)
    {
        return("");
    }
    // checks if the input row and columns are greater than the max row and columns in the vector
    // if they are greater, then the input number is out of bound
    // since vector index start at 0 but the user input index starts at 1, 1 is taken away from the user input to match the vector index
    if(row -1 > vec[0].size() || column -1 > vec.size())
    {
        return("");
    }
    // if the input row and columns are not out of bound and the input csv file did not fail to load
    else
    {
        // return the string at the inputted column and row
        return(vec[row-1][column-1]);
    }
}

std::string CsvFile::headerAt(int column) const
{
    // checks if vector is empty to see if the input failed to load
    if(vec.size() == 0)
    {
        return("");
    }
    // checks if the input columns are greater than the max columns in the vector
    // since vector index start at 0 but the user input index starts at 1, 1 is taken away from the user input to match the vector index
    if(column -1 > vec.size())
    {
        return("");
    }
    // if the input row and columns are not out of bound and the input csv file did not fail to load
    else
    {
        // returns the first value in the desired column
        // first value in desired column is the header of that column
        return(vec[column-1][0]);
    }
}

int CsvFile::columnIndexOf(const std::string &columnName) const
{

  // gets the amount of columns
  int col = vec.size();

  // if CSV file failed to load
  if(col == 0)
  {
      return(-1);
  }
  else
  {
    // loops through all columns in the vector
    for (int i = 0; i < col-1; i++)
    {
        // if the header of a column is equal to the columnName
        if(vec[0][i] == columnName)
        {
              // return the index
             return(i);
        }
     }
    // if the columnName was not found in any of the headers
    return(0);
  }


}
