#include <iostream>
#include <fstream>
#include <string>

#include "random.h"
#include "AttractionClass.h"
using namespace std;

//Programmer: Yingjie Cai
//Date: April 2017
//Purpose: Provide main function to simulate events in a theme park.
//
//Comments 04/16: According to GSI's feedback, it would be better to:
//(1) Implement inheritance into RiderEvent/TrainEvent in EventClass.
//(2) Add more line breaks when printing out results.
//(3) Note a special case - EMPTY list in linked list.
// Got 96/100 grades.


int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "ERROR! Unable to get a file to get parameters." << endl;
    }
    else
    {
        string fileName = argv[1];
        int seedValue;
        AttractionClass attraction;
        if(attraction.readFromFile(fileName))
        {
            cout << "Input a seed value: ";
            cin >> seedValue;
            setSeed(seedValue);
            attraction.runSimulation();
        }
    }
    cout << "Thanks for using this program." <<endl;
    return 0;
}