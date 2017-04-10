#include <iostream>
#include <fstream>
using namespace std;

#include "constants.h"
#include "ColorClass.h"

//Programmer : Yingjie Cai
//Date: Mar 2017
//Purpose: Implement methods of ColorClass. For EECS402

bool isValidFileStream(ifstream &inFile);

void ColorClass::setToRed()
{
    //Set color to red
    redVal = MAX_COLOR_VAL;
    greenVal = 0;
    blueVal = 0;
}


void ColorClass::setToGreen()
{
    //Set color to green
    redVal = 0;
    greenVal = MAX_COLOR_VAL;
    blueVal = 0;
}


void ColorClass::setToBlue()
{
    //Set color to blue
    redVal = 0;
    greenVal = 0;
    blueVal = MAX_COLOR_VAL;
}


void ColorClass::setToBlack()
{
    //Set color to black
    redVal = greenVal = blueVal = 0;
}


void ColorClass::setToWhite()
{
    //Set color to white
    redVal = greenVal = blueVal = MAX_COLOR_VAL;
}


void ColorClass::setTo(const int inRed, const int inGreen, const int inBlue)
{
    //Set color to RGB value as inputs
    redVal = inRed;
    greenVal = inGreen;
    blueVal = inBlue;
}


void ColorClass::setTo(const ColorClass &inColor)
{
    //Set color as input color object
    setTo(inColor.redVal, inColor.greenVal, inColor.blueVal);
}


bool ColorClass::readFromStream(ifstream &inFile)
{
    //Read attributes of a color object from input stream
    bool success = true;
    int currColor[3];

    for (int i = 0; i < 3 && success; i++)
    {
        inFile >> currColor[i];
        
        if (inFile.eof())
        {
            //Error messange if reach end of file
            success = false;
            cout << "ERROR! EOF before finishing reading." << endl;
        }
        else
        {
            //Fail if an invalid character in data
            success = isValidFileStream(inFile);
            if (success && currColor[i] > MAX_COLOR_VAL)
            {
                //Error message when values exceeds 255
                success = false;
                cout << "ERROR! Input image has values exceed " <<
                    MAX_COLOR_VAL << endl;
            }
        }
    }

    //Assign obtained values to color variables if succeed reading
    if (success)
    {
        redVal = currColor[0];
        greenVal = currColor[1];
        blueVal = currColor[2];
    }

    return success;
}


bool ColorClass::writeToStream(ofstream &outFile) const
{
    //Write color attributes to a ppm file
    bool success;
    outFile << redVal << " " << greenVal << " " << blueVal;
    if (outFile)
    {
        success = true;
    }
    else
    {
        success = false;
    }
    return success;
}


bool ColorClass::isSameColor(const ColorClass &inColor)
{
    if (redVal == inColor.redVal && greenVal == inColor.greenVal
        && blueVal == inColor.blueVal)
    {
        return true;
    }
    else
    {
        return false;
    }
}

