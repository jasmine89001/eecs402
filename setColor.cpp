#include <iostream>
using namespace std;

#include "setColor.h"
#include "constants.h"
#include "ColorClass.h"

//Programmer : Yingjie Cai
//Date: Mar 2017
//Purpose: Implement a global function to set color according to choice
bool isValidInt(istream &cin);


ColorClass setColor(int choiceOfItem)
{
    ColorClass inputColor;
    int choiceOfColor = LOWER_BOUND_OF_MENU - 1;
    while (choiceOfColor < CHOICE_FOR_RED || choiceOfColor > CHOICE_FOR_WHITE)
    {
        cout << "1. Red\n" << "2. Green\n" << "3. Blue\n"
            << "4. Black\n" << "5. White" << endl;
        if (choiceOfItem == CHOICE_FOR_RECTANGLE)
        {
            cout << "Enter int for rectangle color: ";
        }
        else if (choiceOfItem == CHOICE_FOR_INSERT_IMAGE)
        {
            cout << "Enter int for transparecy color: ";
        }
        else
        {
            cout << "Enter int for pattern color: ";
        }

        cin >> choiceOfColor;
        if (isValidInt(cin))
        {
            if (choiceOfColor == CHOICE_FOR_RED)
            {
                inputColor.setToRed();
            }
            else if (choiceOfColor == CHOICE_FOR_GREEN)
            {
                inputColor.setToGreen();
            }
            else if (choiceOfColor == CHOICE_FOR_BLUE)
            {
                inputColor.setToBlue();
            }
            else if (choiceOfColor == CHOICE_FOR_BLACK)
            {
                inputColor.setToBlack();
            }
            else if(choiceOfColor == CHOICE_FOR_WHITE)
            {
                inputColor.setToWhite();
            }
            else
            {
                cout << "ERROR! Input int is beyond range." << endl;
                cin.ignore(STREAM_SIZE, STREAM_IGNORE_SYMBOL);
            }
        }
    }
    return inputColor;
}


