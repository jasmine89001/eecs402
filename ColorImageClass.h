#include<string>

#ifndef _COLORIMAGECLASS_H_
#define _COLORIMAGECLASS_H_

using namespace std;

#include "PixelLocationClass.h"
#include "RectangleClass.h"
#include "PatternClass.h"
#include "ColorClass.h"

//Programmer : Yingjie Cai
//Date: Mar 2017
//Purpose: Provide a class to store a color image, containing an array
//         of pixels where each pixel is an RBG color. For EECS402

class ColorImageClass
{
private:
    int numRows;
    int numCols;
    ColorClass **pixels;
    string magicNum;

public:
    //Default ctor
    ColorImageClass();

    //Value ctor and set default pixel as black
    ColorImageClass(const int inRows, const int inCols);

    //Dtor to free the dynamic allocated memory
    ~ColorImageClass()
    {
        for (int i = 0; i < numRows; i++)
        {
            delete [] pixels[i];
        }
        delete [] pixels;
    }

    //Initialize all pixelx from input
    void initializeTo(const ColorClass &inColor)
    {
        {
            for (int r = 0; r < numRows; r++)
            {
                for (int c = 0; c < numCols; c++)
                {
                    pixels[r][c].setTo(inColor);
                }
            }
        }
    }

    //Set a certain pixel, return false if location is invalid
    bool setColorAtLocation(PixelLocationClass inLocation,
        const ColorClass &inColor);

    //Get a certain pixel
    ColorClass getColorAtLocation(PixelLocationClass inLocation);

    //Read pixel values from a ppm file, return false if fail
    bool readFromFile(const string &inFileName);

    //Write modifies pixels into a file, return false if fail
    bool writeToFile(const string &outFileName) const;

    //Check if the location is beyond bound when inserting another item
    bool checkLocationValid(PixelLocationClass inLocation);

    //Draw rectangle in the back ground image.
    //Return false if input rectangle is invalid.
    bool drawRectangle(RectangleClass inRec);

    //Insert a new image and set tranparecy color
    bool insertImage(const ColorImageClass &newImage);

    //Draw a pattern on the image and set tranparecy color
    bool drawPattern(PatternClass &pattern);

    //Get the number of rows
    int getNumRows() const
    {
        return numRows;
    }

    //Get the number of columns
    int getNumCols() const
    {
        return numCols;
    }
};
#endif //_COLORIMAGECLASS_H_
