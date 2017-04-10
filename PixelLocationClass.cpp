#include <iostream>

using namespace std;

#include "PixelLocationClass.h"

//Programmer: Yingjie Cai
//Date: Mar 2017
//Purpose: Implement methods of PixelLocationClass. For EECS402.

PixelLocationClass::PixelLocationClass()
//PixelLocationClass(): rowIndex (0), colIndex (0) {}
{
    //Default ctor
    rowIndex = 0;
    colIndex = 0;
}


PixelLocationClass::PixelLocationClass(int inRow, int inCol)
{
    //Value ctor
    rowIndex = inRow;
    colIndex = inCol;
}


void PixelLocationClass::setLocation(int inRow, int inCol)
{
    //Set row index and column index
    rowIndex = inRow;
    colIndex = inCol;
}


void PixelLocationClass::setLocation(const PixelLocationClass &inLocation)
{
    //Set row index and column index from a PixelLocationClass object
    setLocation(inLocation.rowIndex, inLocation.colIndex);
}


int PixelLocationClass::getRow()
{
    //Get row index
    return rowIndex;
}


int PixelLocationClass::getCol()
{
    //Get column index
    return colIndex;
}
