#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#include "constants.h"
#include "RectangleClass.h"
#include "PatternClass.h"
#include "ColorClass.h"
#include "ColorImageClass.h"
#include "PixelLocationClass.h"

//Programmer : Yingjie Cai
//Date: Mar 2017
//Purpose: Practice dynamic allocation of arrays and file i/o. For EECS402.
//         Allow user to modify an user in a few specific ways.

//Prompt main menu and get choice from user
int promptMainMenu();

//Check whether the file stream is in good status or not
bool isValidFileStream(ifstream &inFile);

//Check whether the cin stream is in good status or not
bool isValidInt(istream &cin);



int main()
{
    bool gotImage;
    int choice = LOWER_BOUND_OF_MENU - 1; // Initialize to enter the loop

    //Load image file
    string inFileName;
    ColorImageClass backImage;
    cout << "Enter string for PPM image file name to load: ";
    cin >> inFileName;
    gotImage = backImage.readFromFile(inFileName);

    //End the program if image didn't load
    while (gotImage && choice != CHOICE_FOR_EXIT)
    {
        choice = promptMainMenu();
        if (choice == CHOICE_FOR_RECTANGLE)     // 1
        {
            RectangleClass rectangle;
            if (rectangle.readFromKeyboard())
            {
                backImage.drawRectangle(rectangle);
            }
        }

        else if (choice == CHOICE_FOR_PATTERN)   // 2
        {
            PatternClass pattern;
            if (pattern.readFromFile())
            {
                backImage.drawPattern(pattern);
            }
        }

        else if (choice == CHOICE_FOR_INSERT_IMAGE)   // 3
        {
            ColorImageClass foreImage; //foreground image
            string nameOfImage;
            cout << "Enter string for file name of PPM image to insert: ";
            cin >> nameOfImage;
            if (foreImage.readFromFile(nameOfImage))
            {
                backImage.insertImage(foreImage);
            }
        }

        else if (choice == CHOICE_FOR_OUTPUT_IMAGE)   // 4
        {
            string nameOfFile;
            cout << "Enter string for PPM file name to output: ";
            cin >> nameOfFile;
            backImage.writeToFile(nameOfFile);
        }
    }
    cout << "Thank you for using this program" << endl;
    return 0;
}
