#include <iostream>

using namespace std;

#include "promptMainMenu.h"
//Programmer : Yingjie Cai
//Date: Mar 2017
//Purpose: Prompt main menu and get choice from user


// Build the main interface to get usesr's choice
int promptMainMenu()
{
    // Build the main interface to get usesr's choice
    // Valid input are integers within [1,5], then returned to main
    int numOfChoice;
    bool validChoiceFound = false;  // Initialize in order to enter the loop
    while (!validChoiceFound)
    {
        cout << "1. Annotate image with rectangle\n"
            << "2. Annotate image with pattern from file\n"
            << "3. Insert another image\n"
            << "4. Write out current image\n"
            << "5. Exit the program\n"
            << "Enter int for main menu choice: ";
        cin >> numOfChoice;
        if(isValidInt(cin))
        {
            if(numOfChoice >= LOWER_BOUND_OF_MENU &&
            numOfChoice <= CHOICE_FOR_EXIT)
            {
                validChoiceFound = true;
            }
            else
            {
                cout <<"ERROR! Input integer is beyond valid range." << endl;
                cin.ignore(STREAM_SIZE, STREAM_IGNORE_SYMBOL);
            }
        }
    }

    return numOfChoice;
}