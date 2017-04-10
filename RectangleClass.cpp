#include <iostream>

using namespace std;

#include "constants.h"
#include "RectangleClass.h"

//Programmer : Yingjie Cai
//Date: Mar 2017
//Purpose: Implement methods of RectangleClass. For EECS402

bool isValidInt(istream &cin);


bool RectangleClass::readFromKeyboard()
{
    //Set arributes of rectangle from input. There are three methods.
    int creationMethod;
    int recParameter[4];    //Four inputs can define a rectangle
    bool validInputFound = false;

    if (!validInputFound)
    {
        cout << "1. Specify upper left and lower right corners of rectangle\n"
            << "2. Specify upper left corner and dimensions of rectangle\n"
            << "3. Specify extent from center of rectangle\n"
            << "Enter int for rectangle specification method: ";
        cin >> creationMethod;
        if (isValidInt(cin))
        {
            if (creationMethod < CREATION_WITH_TWO_CORNERS ||
                creationMethod > CREATION_WITH_CENTER)
            {
                cout << "ERROR! Entered int is beyond valid range." << endl;
            }
            else if (creationMethod == CREATION_WITH_TWO_CORNERS)//1
            {
                cout << "Enter upper left corner row and column: ";
                cin >> recParameter[0];
                cin >> recParameter[1];
                cout << "Enter lower right corner row and colomn: ";
                cin >> recParameter[2];
                cin >> recParameter[3];

                if (isValidInt(cin))
                {
                    upLeftRC.setLocation(recParameter[0], recParameter[1]);
                    lowRightRC.setLocation(recParameter[2], recParameter[3]);
                    validInputFound = isValidRectangle();
                }
            }

            else if (creationMethod == CREATION_WITH_ONE_CORNER)//2
            {
                cout << "Enter rectangle upper-left row and column: ";
                cin >> recParameter[0];
                cin >> recParameter[1];
                cout << "Enter int for number of rows: ";
                cin >> recParameter[2];
                cout << "Enter int for number of columns: ";
                cin >> recParameter[3];

                if (isValidInt(cin))
                {
                    upLeftRC.setLocation(recParameter[0], recParameter[1]);
                    lowRightRC.setLocation(recParameter[0] + recParameter[2],
                        recParameter[1] + recParameter[3]);
                    validInputFound = isValidRectangle();
                }
            }

            else //3
            {
                cout << "Enter rectangle center row and column: ";
                cin >> recParameter[0];
                cin >> recParameter[1];
                cout << "Enter int for half number of rows: ";
                cin >> recParameter[2];
                cout << "Enter int for half number of columns: ";
                cin >> recParameter[3];

                if (isValidInt(cin))
                {
                    upLeftRC.setLocation(recParameter[0] - recParameter[2],
                        recParameter[1] - recParameter[3]);
                    lowRightRC.setLocation(recParameter[0] + recParameter[2],
                        recParameter[1] + recParameter[3]);
                    validInputFound = isValidRectangle();
                }
            }
        }
    }
    return validInputFound;
}


bool RectangleClass::isValidRectangle()
{
    if (upLeftRC.getCol() >= lowRightRC.getCol() ||
        upLeftRC.getRow() >= lowRightRC.getRow())
    {
        cout << "ERROR! Input rectangle is invalid." << endl;
        return false;
    }
    else
    {
        return true;
    }
}
