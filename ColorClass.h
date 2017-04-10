using namespace std;

#ifndef _COLORCLASS_H_
#define _COLORCLASS_H_

//Programmer : Yingjie Cai
//Date: Mar 2017
//Purpose: Provide a class to represent color in RBG. For EECS402

class ColorClass
{
private:
    int redVal;
    int greenVal;
    int blueVal;

public:
    //Default ctor. Set default color as black
    ColorClass() : redVal(0), greenVal(0), blueVal(0)
    {
    }

    //Value ctor  
    ColorClass(const int inRed, const int inGreen, const int inBlue)
    {
        setTo(inRed, inGreen, inBlue);
    }

    //Set color to red
    void setToRed();

    //Set color to green
    void setToGreen();

    //Set color to blue
    void setToBlue();

    //Set color to black
    void setToBlack();

    //Set color to white
    void setToWhite();

    //Set color to RGB value as inputs
    void setTo(const int inRed, const int inGreen, const int inBlue);

    //Set color as input color object
    void setTo(const ColorClass &inColor);

    //Read attributes of a color object from input stream.
    //Return false if stream in fail state or color value beyond range.
    //Otherwise return ture.
    bool readFromStream(ifstream &inFile);

    //Write color attributes to an .ppm file.
    //Return false if stream in fail state. Return ture, otherwise.
    bool writeToStream(ofstream &outFile) const;

    //Judge whether the input color is the same another color.
    bool isSameColor(const ColorClass &inColor);
};

#endif //_COLORCLASS_H_
