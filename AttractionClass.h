#ifndef _ATTRACTIONCLASS_H_
#define _ATTRACTIONCLASS_H_

#include <string>

#include "FIFOQueueClass.h"
#include "SortedListClass.h"
#include "RiderClass.h"
#include "TrainClass.h"
#include "EventClass.h"
#include "constants.h"

using namespace std;

//Programmer: Yingjie Cai
//Date: April 2017
//Purpose: Provide a class to simulation an attraction in a theme park.

class AttractionClass
{
private:
    //Attributes about the attraction
    string attractionName;
    int numOfSeats;

    //Attribute about riders in different lines
    //Since the specs says that we may want to introduce additional priority
    //levels in the future, I use array to represent different lines in order
    //to allow this change to be relatively straightforward.
    FIFOQueueClass< RiderClass > line[KIND_OF_PRIORITY]; //three lines
    int lineLength[KIND_OF_PRIORITY]; //max numbers of riders in each line
    int totalWaitTime[KIND_OF_PRIORITY]; //total wait times for each line
    int ridersNum[KIND_OF_PRIORITY]; //total riders for each line

    //Attributes about events
    SortedListClass< EventClass > eventList;

    //Attributes about statistics of this park
    int currTime; //track the time in the simulaiton  
    int totalRidersNum;
    int trainsNum;

    //Attributes that need to be read from file
    int closeTime; //attraction's closing time
    double riderArrivalMean; //rider arrival rate normal distribution mean
    double riderArrivalStd; //rider arrival rate normal distribution std
    int carArrivalMin; //car arrival rate uniform distribution minimum value
    int carArrivalMax; //car arrival rate uniform distribution maximum value
    int priorityPercent[KIND_OF_PRIORITY]; //percentage of riders in a park
    int idealNum[KIND_OF_PRIORITY]; //ideal num of riders admitted on a train

public:
    //Default ctor
    AttractionClass();

    //Value ctor
    AttractionClass(string &inName, int inNumOfSeats);

    //Read information about this attraction from file
    bool readFromFile(string &inFileName);

    //Check if the line is empty
    bool isEmptyLine();

    //Generate different priority for each rider based on unifrom distribution.
    int generatePriority();

    //Generate a rider event and add it to the event list
    void generateRiderEvent();

    //Generate a train event and add it to the event list
    void generateTrainEvent();

    //Handle an event of rider and add it to simulation 
    void handleRiderEvent(const EventClass &inEvent);

    //Handle an event of train and remove some rides in line
    void handleTrainEvent(const EventClass &inEvent);

    //Seed the simulation with a few events to start.
    //For rider event, add it to a proper line.
    //For train event, remove proper nums of riders away from lines.
    void runSimulation();

    //Print out statistics results.
    void showResults();

};

#endif
