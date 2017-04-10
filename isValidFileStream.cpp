#include <iostream>
using namespace std;

#include "constants.h"
#include "isValidFileStream.h"

//Programmer : Yingjie Cai
//Date: Mar 2017
//Purpose: Check whether the file stream is in good status or not

bool isValidFileStream(ifstream &inFile)
{
    bool isValidStream = true;
    if (inFile.fail())
    {
        inFile.clear();
        inFile.ignore(STREAM_SIZE, STREAM_IGNORE_SYMBOL);
        cout << "ERROR! File stream was in the fail state - " <<
        "File does not exist or incorrect data type in it." << endl;
        isValidStream = false;
    }
    return isValidStream;
}
