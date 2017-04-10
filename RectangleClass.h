#ifndef _RECTANGLECLASS_H_
#define _RECTANGLECLASS_H_

#include "PixelLocationClass.h"

using namespace std;

//Programmer : Yingjie Cai
//Date: Mar 2017
//Purpose: Provide a class to describe a rectangle. For EECS402

class RectangleClass
{
private:
    PixelLocationClass upLeftRC;
    PixelLocationClass lowRightRC;

public:
    //Default ctor
    RectangleClass()
    {
        //Set upper both left and lower right location at origin.
        upLeftRC.setLocation(0, 0);
        lowRightRC.setLocation(0, 0);
    }

    //Value ctor
    RectangleClass(const PixelLocationClass &inUpLeft,
        const PixelLocationClass &inLoWRight)
    {
        upLeftRC.setLocation(inUpLeft);
        lowRightRC.setLocation(inLoWRight);
    }

    //Set arributes of rectangle from input. There are three methods.
    bool readFromKeyboard();

    //Get location of upper-left corner as object of PixelLocationClass
    PixelLocationClass getUpLeft()
    {
        return upLeftRC;
    }

    //Get location of lower-right corner as object of PixelLocationClass
    PixelLocationClass getLowRight()
    {
        return lowRightRC;
    }

    //To check if the input rectangle is valid.
    bool isValidRectangle();
};
#endif //_RECTANGLECLASS_H_
