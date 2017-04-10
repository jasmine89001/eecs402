#include <iostream>
using namespace std;

#include "constants.h"
#include "isValidInt.h"

//Programmer : Yingjie Cai
//Date: Mar 2017
//Purpose: Check whether the cin stream is in good status or not

bool isValidInt(istream &cin)
{
    bool isValidInput = true;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(STREAM_SIZE, STREAM_IGNORE_SYMBOL);
        
        cout << "ERROR! The input type should be interger." << endl;
        isValidInput = false;
    }
    return isValidInput;
}
