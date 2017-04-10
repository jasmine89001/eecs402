#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "PixelLocationClass.h"
#include "ColorImageClass.h"
#include "constants.h"

//Programmer : Yingjie Cai
//Date: Mar 2017
//Purpose: Implement methods of ColorImageClass. For EECS402

bool isValidFileStream(ifstream &inFile);
bool isValidInt(istream &cin);
ColorClass setColor(int choiceOfItem);

ColorImageClass::ColorImageClass()
{
    numCols = 1;
    numRows = 1;
    pixels = new ColorClass*[numRows];
    pixels[0] = new ColorClass[numCols]; // equals to *(pixels + i)
    pixels[0][0].setToBlack();
}

ColorImageClass::ColorImageClass(const int inRows, const int inCols)
{
    ColorClass bgColor;

    // Allocate pixels
    pixels = new ColorClass*[inRows];
    for (int r = 0; r < inRows; r++)
    {
        pixels[r] = new ColorClass[inCols]; // equals to *(pixel + i)
    }

    bgColor.setToBlack();

    numRows = inRows;
    numCols = inCols;
    initializeTo(bgColor);
}


//Check if the location is beyond bound when inserting another item
bool ColorImageClass::checkLocationValid(PixelLocationClass inLocation)
{
    if (inLocation.getRow() < 0 || inLocation.getRow() >= numRows
        || inLocation.getCol() < 0 || inLocation.getCol() >= numCols)
    {
        cout << "ERROR!The location is beyond the range of image." << endl;
        return false;
    }
    else
    {
        return true;
    }
}


//Set a certain pixel
bool ColorImageClass::setColorAtLocation(
    PixelLocationClass inLocation, const ColorClass &inColor)
{
    bool validLocation;
    validLocation = checkLocationValid(inLocation);
    if (validLocation)
    {
        pixels[inLocation.getRow()][inLocation.getCol()].setTo(inColor);
    }
    return validLocation;
}


//Get a certain pixel, return false if location is invalid
ColorClass ColorImageClass::getColorAtLocation(PixelLocationClass inLocation)
{
 //   bool validLocation;
    ColorClass outColor;
    bool validLocation = checkLocationValid(inLocation);
    if (validLocation)
    {
        outColor = pixels[inLocation.getRow()][inLocation.getCol()];
    }
    return outColor;
}


//Read pixel values from a ppm file, return false if fail
bool ColorImageClass::readFromFile(const string &inFileName)
{
    bool success = false;
    ifstream inFile;
    inFile.open(inFileName.c_str());

    if (isValidFileStream(inFile))
    {
        //Read the header of PPM file and check
        int maxColorVal, inNumCols, inNumRows;
        inFile >> magicNum >> inNumCols >> inNumRows >> maxColorVal;
        if (inFile.eof())
        {
            cout << "ERROR! EOF before finishing reading." << endl;
        }
        else if (magicNum != PPM_MAGIC_NUM)
        {
            cout << "Error found when reading magic number - expected "
                << PPM_MAGIC_NUM << " but found " << magicNum << endl;
        }
        else if (MAX_COLOR_VAL != maxColorVal)
        {
            cout <<"Error found when reading max color value - "
            <<"expected " << MAX_COLOR_VAL << " but found " << 
            maxColorVal << endl;
        }
        else
        {
            //Delete existing pixels in case of memory leak
            for (int r = 0; r < numRows; r++)
            {
                delete [] pixels[r];
            }
            delete [] pixels;

            //Read pixel values
            success = true;
            numCols = inNumCols, numRows = inNumRows;
            pixels = new ColorClass*[numRows];
            for (int r = 0; r < numRows && success; r++)
            {
                pixels[r] = new ColorClass[numCols];
                for (int c = 0; c < numCols && success; c++)
                {
                    success = pixels[r][c].readFromStream(inFile);
                }
            }

            //Check if there are redundant pixel values
            if (success)
            {
                int garbage;
                inFile >> garbage;
                if (!inFile.eof())
                {
                    cout << "ERROR! The number of pixel values is greater than"
                        << " the dimension of width and height." << endl;
                    success = false;
                }
            }
        }
    }
    inFile.close();
    return success;
}


//Write modifies pixels into a file, return false if fail
bool ColorImageClass::writeToFile(const string &outFileName) const
{
    bool success;
    ofstream outFile;

    success = true; //Assume good so far
    outFile.open(outFileName.c_str());
    if (!outFile)
    {
        cout << "ERROR: Unable to write to output file: "
            << outFileName << endl;
        success = false;
    }

    //Write the header of PPM file
    outFile << PPM_MAGIC_NUM << endl;
    outFile << numCols << " " << numRows << endl;
    outFile << MAX_COLOR_VAL << endl;

    //Write pixel values
    for (int r = 0; r < numRows && success; r++)
    {
        for (int c = 0; c < numCols && success; c++)
        {
            success = pixels[r][c].writeToStream(outFile);
            if (c < numCols - 1)
            {
                outFile << " ";
            }
        }
        outFile << endl;
    }
    outFile.close();
    return success;
}


//Draw rectangle in the back ground image.
//Return false if input rectangle is invalid.
bool ColorImageClass::drawRectangle(RectangleClass inRec)
{
    bool success = true;   //Mark the status of drawing
    PixelLocationClass startLoc = inRec.getUpLeft();
    PixelLocationClass endLoc = inRec.getLowRight();

    if (!checkLocationValid(startLoc) || !checkLocationValid(endLoc))
    {
        success = false;
    }
    else
    {
        //Prompt and get edge or filled color
        ColorClass inColor = setColor(CHOICE_FOR_RECTANGLE);

        //Prompt and get choice to fill or not
        int choiceOfFill;
        bool getValidInput = false;
        while (!getValidInput)
        {
            cout << "1. No\n2. Yes\nEnter int for rectangle fill option: ";
            cin >> choiceOfFill;
            if (isValidInt(cin))
            {
                getValidInput = true;
                //When choosing to fill the rectangle
                if (choiceOfFill == CHOICE_FOR_FILL)
                {
                    for (int r = startLoc.getRow(); r <= endLoc.getRow(); r++)
                    {
                        for (int c = startLoc.getCol();
                            c <= endLoc.getCol(); c++)
                        {
                            PixelLocationClass currLoc(r, c);
                            setColorAtLocation(currLoc, inColor);
                        }
                    }
                }
                //When choosing to not fill the rectangle
                else if (choiceOfFill == CHOICE_FOR_NO_FILL)
                {
                    for (int c = startLoc.getCol(); c <= endLoc.getCol(); c++)
                    {
                        setColorAtLocation(
                            PixelLocationClass(startLoc.getRow(), c), inColor);
                        setColorAtLocation(
                            PixelLocationClass(endLoc.getRow(), c), inColor);
                    }
                    for (int r = startLoc.getRow(); r <= endLoc.getRow(); r++)
                    {
                        setColorAtLocation(
                            PixelLocationClass(r, startLoc.getCol()), inColor);
                        setColorAtLocation(
                            PixelLocationClass(r, endLoc.getCol()), inColor);
                    }
                }
                //When choosing some invalid choice
                else
                {
                    getValidInput = false;
                    cout << "ERROR !The input integer is beyond menu range."
                        << "Try again!" << endl;
                }
            }
        }
    }
    return success;
}


//Insert a new image and set tranparecy color
bool ColorImageClass::insertImage(const ColorImageClass &newImage)
{
    bool success = true; 
    int startRow, startCol;

    //Get the upper-left position of new image 
    cout << "Enter upper left corner to insert image row and column: ";
    cin >> startRow >> startCol;
    if (isValidInt(cin))
    {
        PixelLocationClass startLoc(startRow, startCol);
        PixelLocationClass endLoc(startRow + newImage.getNumRows(),
            startCol + newImage.getNumCols());
        if (!checkLocationValid(startLoc) || !checkLocationValid(endLoc))
        {
            success = false;
        }
        else
        {
            //Get color need to be transparency
            ColorClass transColor = setColor(CHOICE_FOR_INSERT_IMAGE);

            //Set pixels of background image according to new image
            for (int r = 0; r < newImage.getNumRows(); r++)
            {
                for (int c = 0; c < newImage.getNumCols(); c++)
                {
                    //PixelLocationClass foreLoc(r, c);
                    ColorClass currPixel = 
                        newImage.pixels[r][c];//getColorAtLocation(foreLoc);
                    if (!currPixel.isSameColor(transColor))
                    {
                        PixelLocationClass backLoc(r + startRow, c + startCol);
                        setColorAtLocation(backLoc, currPixel);
                    }
                }
            }
        }
    }
    return success;
}


bool ColorImageClass::drawPattern(PatternClass &pattern)
{
    bool success = true;
    PixelLocationClass startLoc = pattern.getUpLeftRC();
    PixelLocationClass endLoc(startLoc.getRow() + pattern.getNumRows(),
        startLoc.getRow() + pattern.getNumCols());

    //Check whether the pattern is beyond the range of image.
    if (!checkLocationValid(startLoc) || !checkLocationValid(endLoc))
    {
        success = false;
    }
    else
    {
        success = true;

        //Prompt and get filled color
        ColorClass inColor = setColor(CHOICE_FOR_PATTERN);

        for (int r = 0; r < pattern.getNumRows(); r++)
        {
            for (int c = 0; c < pattern.getNumCols(); c++)
            {
                if (pattern.getPatternAtLocation(r, c))
                {
                    PixelLocationClass currPixel(
                        startLoc.getRow() + r, startLoc.getCol() + c);
                    setColorAtLocation(currPixel, inColor);
                }
            }
        }
    }
    return success;
}

