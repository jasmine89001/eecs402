#ifndef _PATTERNCLASS_H_
#define _PATTERNCLASS_H_

#include "PixelLocationClass.h"

using namespace std;

//Programmer : Yingjie Cai
//Date: Mar 2017
//Purpose: Provide a class to describe a pattern. For EECS402


class PatternClass
{
private:
    PixelLocationClass upLeftRC;
    int numRows;
    int numCols;
    int **pattern;

public:
    //Default ctor
    PatternClass();

    //Value ctor and set default pattern as 0
    PatternClass(const int inRows, const int inCols);

    //Dtor to free the dynamic allocated memory
    ~PatternClass()
    {
        for (int r = 0; r < numRows; r++)
        {
            delete [] pattern[r];
        }
        delete [] pattern;
    }

    //Set start location
    void setStartLocation(const PixelLocationClass &inLocation)
    {
        upLeftRC.setLocation(inLocation);
    }

    //Read pattern values from txt file
    bool readFromFile();

    //Get location of start point
    PixelLocationClass getUpLeftRC() const
    {
        return upLeftRC;
    }

    //Get number of rows
    int getNumRows() const
    {
        return numRows;
    }

    //Get number of columns
    int getNumCols() const
    {
        return numCols;
    }

    //Get specific pattern value in certain row and column index
    int getPatternAtLocation(int r, int c)
    {
        return pattern[r][c];
    }
};
#endif //_PATTERNCLASS_H_

