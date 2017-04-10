#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#include "PixelLocationClass.h"
#include "PatternClass.h"

//Programmer : Yingjie Cai
//Date: Mar 2017
//Purpose: Implement methods of ColorImageClass. For EECS402

bool isValidFileStream(ifstream &inFile);
bool isValidInt(istream &cin);


 PatternClass::PatternClass()
{
    upLeftRC.setLocation(0, 0);
    numRows = 1;
    numCols = 1;
    pattern = new int*[numRows];
    pattern[0] = new int[numCols]; // equals to *(pixels + i)
    pattern[0][0] = 0;
}

PatternClass::PatternClass(const int inRows, const int inCols)
{
    upLeftRC.setLocation(0, 0);
    pattern = new int*[inRows];
    for (int r = 0; r < inRows; r++)
    {
        pattern[r] = new int[inCols]; // equals to *(pixel + i)
        for (int c = 0; c < inCols; c++)
        {
            pattern[r][c] = 0;
        }
    }
}


bool PatternClass::readFromFile()
{
    bool success = false;
    string nameOfFile;
    ifstream inFile;
    cout << "Enter string for file name containing pattern: ";
    cin >> nameOfFile;
    inFile.open(nameOfFile.c_str());

    if (!isValidFileStream(inFile))
    {
        return success;
    }
    else
    {
        inFile >> numCols >> numRows;
        pattern = new int*[numRows];
        for (int r = 0; r < numRows; r++)
        {
            pattern[r] = new int[numCols];
            for (int c = 0; c < numCols; c++)
            {
                if (inFile.eof())
                {
                    cout << "ERROR! EOF before finishing reading." << endl;
                    return success;
                }
                else
                {
                    inFile >> pattern[r][c];
                }
            }
        }

        //Check if the dimension of pattern values is matched
        if(inFile.eof())
        {
            cout << "ERROR! The number of pattern values is less than"
            << " the dimension of width and height." << endl;           
        }
        else
        {
            int endOfFile;
            inFile >> endOfFile;
            if(!inFile.eof())
            {
                cout << "ERROR! The number of pattern values is greater than"
                    << " the dimension of width and height." << endl;
            }
            else
            {
                success = true;
            }          
        }

        //Input the corner location
        if (success)
        {
            cout << "Enter upper left corner of pattern row and column: ";
            int r, c;
            cin >> r >> c;
            if (isValidInt(cin))
            {
                upLeftRC.setLocation(r, c);
            }
            else
            {
                success = false;
            }
        }
    }
    inFile.close(); 
    return success;
}



