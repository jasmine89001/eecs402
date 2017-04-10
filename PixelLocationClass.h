#ifndef _PIXELLOCATIONCLASS_H_
#define _PIXELLOCATIONCLASS_H_

using namespace std;

//Programmer: Yingjie Cai
//Date: Mar 2017
//Purpose: Provide a class to refer to a specific pixel within a image.

class PixelLocationClass
{
private:
    int rowIndex;
    int colIndex;

public:
    //Default ctor
    PixelLocationClass();

    //Value ctor
    PixelLocationClass(int inRow, int inCol);

    //Set row index and column index from integers
    void setLocation(int inRow, int inCol);

    //Set row index and column index from a PixelLocationClass object
    void setLocation(const PixelLocationClass &inLocation);

    //Get row index
    int getRow();

    //Get column index
    int getCol();
};
#endif //_PIXELLOCATIONCLASS_H_