#include <fstream>
#include <iostream>

#include "AttractionClass.h"
#include "random.h"

//Programmer: Yingjie Cai
//Date: April 2017
//Purpose: Implement member funcions of attraction class.

//Default ctor
AttractionClass::AttractionClass()
{
    attractionName = ATTRACTION_NAME;
    numOfSeats = MAX_NUM_SEATS;
  
    currTime = 0;
    totalRidersNum = 0;
    trainsNum = 0;   

    for (int i = 0; i < KIND_OF_PRIORITY; i++)
    {
        lineLength[i] = 0;
        totalWaitTime[i] = 0;
        ridersNum[i] = 0;
    }
}

//Value ctor
AttractionClass::AttractionClass(string &inName, int inNumOfSeats)
{
    attractionName = inName;
    numOfSeats =  inNumOfSeats;

    currTime = 0;
    totalRidersNum = 0;
    trainsNum = 0;   

    for (int i = 0; i < KIND_OF_PRIORITY; i++)
    {
        lineLength[i] = 0;
        totalWaitTime[i] = 0;
        ridersNum[i] = 0;
    }
}

//Read information about this attraction from file
bool AttractionClass::readFromFile(string &inFileName)
{
    bool success;
    ifstream inFile;
    success = true;
    
    inFile.open(inFileName.c_str());
    if (inFile.fail())
    {
        cout << "ERROR! Unable to open the file." << endl;
        inFile.clear();
        inFile.ignore(IFSTREAM_IGNORED_NUMBER, IFSTREAM_IGNORED_SIGN);
        success = false;
    }
    else
    {
        inFile >> closeTime >> riderArrivalMean >> riderArrivalStd >> 
        carArrivalMin >> carArrivalMax >> priorityPercent[SUPER_FAST_PASS] >>
        priorityPercent[FAST_PASS] >> idealNum[SUPER_FAST_PASS] >> 
        idealNum[FAST_PASS];

        //Calculate remaining variables
        idealNum[STANDARD_PASS] = numOfSeats - 
            idealNum[SUPER_FAST_PASS] - idealNum[FAST_PASS];
        priorityPercent[STANDARD_PASS] = PERCENT_MAX - 
            priorityPercent[SUPER_FAST_PASS] - priorityPercent[FAST_PASS];

    }
    inFile.close();
    return success;
}

//Check if the line is empty
bool AttractionClass::isEmptyLine()
{
    bool isEmpty = true;
    for (int i = 0; i < KIND_OF_PRIORITY; i++)
    {
        isEmpty = isEmpty && (line[i].getNumElems() <= 0);
    }
    //The bool variable will be false if one or more line is not empty
    return isEmpty;
}

//Generate different priority for each rider based on a random number.
int AttractionClass::generatePriority()
{
    int randVal = getUniform(PERCENT_MIN, PERCENT_MAX);
    int priority = 0;

    if (randVal < priorityPercent[SUPER_FAST_PASS])
    {
        priority = SUPER_FAST_PASS;
    }
    else if (randVal < (priorityPercent[SUPER_FAST_PASS] + 
        priorityPercent[FAST_PASS]))
    {
        priority = FAST_PASS;
    }
    else
    {
        priority = STANDARD_PASS;
    }

    return priority;
}

//Generate a rider event and add it to the event list
void AttractionClass::generateRiderEvent()
{
    int riderArrivalTime = getNormal(riderArrivalMean, riderArrivalStd);
    int time = currTime + riderArrivalTime;
    if (time < closeTime)
    {
        int priority = generatePriority();
        RiderClass rider(time, priority);
        EventClass riderEvent(rider);
        eventList.insertValue(riderEvent);
    }
}

//Generate a train event and add it to the event list
void AttractionClass::generateTrainEvent()
{
    int trainArrivalTime = getUniform(carArrivalMin, carArrivalMax);
    int time = currTime + trainArrivalTime;
    TrainClass train(time, numOfSeats);
    EventClass trainEvent(train);
    eventList.insertValue(trainEvent);
}

//Handle an event of rider and add it to simulation 
void AttractionClass::handleRiderEvent(const EventClass &inEvent)
{
    RiderClass rider = inEvent.getRider();
    int priority = rider.getPriority();

    line[priority].enqueue(rider);
    ridersNum[priority]++;

    cout << "A rider arrived" << PRIORITY_STRING[priority] << "line at time " 
    << inEvent.getEventTime() << ". There are " << line[priority].getNumElems()
    << " riders in" << PRIORITY_STRING[priority] << "line." << endl;

    //Calculate the longest length in the line
    if (line[priority].getNumElems() > lineLength[priority])
    {
        lineLength[priority] = line[priority].getNumElems();
    }

    //Chcek close time to determine if add another rider or not
    if (currTime <= closeTime)
    {
        generateRiderEvent();
    }
}

//Handle an event of train and remove some rides in line
void AttractionClass::handleTrainEvent(const EventClass &inEvent)
{
    int ridersOnTrain[KIND_OF_PRIORITY];
    int numFilledSeats = 0;
    RiderClass firstInLine;
    int trainArrivalTime = inEvent.getEventTime();

    cout << "A train arrived at time " << inEvent.getEventTime() 
        << " with:"<< endl;

    //Set up the initial values of rides on train to 0s.
    for (int i = 0; i < KIND_OF_PRIORITY; i++)
    {
        ridersOnTrain[i] = 0;
    }

    //Let riders in each line get on when a train arriving
    for (int i = 0; i < KIND_OF_PRIORITY; i++)
    {
        while (ridersOnTrain[i] < idealNum[i] && line[i].dequeue(firstInLine))
        {
            firstInLine.setWaitTime(trainArrivalTime);
            cout << "Rider with" << PRIORITY_STRING[i] << "got on train, " <<
                "with wait time " << firstInLine.getWaitTime() << endl;
            totalWaitTime[i] += firstInLine.getWaitTime();
            numFilledSeats++;
            ridersOnTrain[i]++;
        }
    }
    
    //To fill up the train when lines are short or empty
    for (int i = 0; i < KIND_OF_PRIORITY && numFilledSeats < numOfSeats; i++)
    {
        while (numFilledSeats < numOfSeats && line[i].dequeue(firstInLine))
        {
            firstInLine.setWaitTime(trainArrivalTime);
            totalWaitTime[i] += firstInLine.getWaitTime();
            numFilledSeats++;
            ridersOnTrain[i]++;

            cout << "Rider with" << PRIORITY_STRING[i] << "got on train, " <<
            "with wait time " << firstInLine.getWaitTime() << endl;
        }
    }
    
    cout << "The number of filled seats is " << numFilledSeats << "\n\n";
    generateTrainEvent();
}

//Seed the simulation with a few events to start.
//For rider event, add it to a proper line.
//For train event, remove proper nums of riders away from lines.
void AttractionClass::runSimulation()
{
    EventClass currEvent;
    generateRiderEvent();
    generateTrainEvent();

    
    while (eventList.removeFront(currEvent) &&
        (currTime <= closeTime || !isEmptyLine()))
    {
        currTime = currEvent.getEventTime();
        if (currEvent.getEventType() == TRAIN_TYPE)
        {
            ++trainsNum;
            handleTrainEvent(currEvent);
        }
        else
        {
            totalRidersNum++;
            handleRiderEvent(currEvent);
        }
    }

    showResults();
}

//Print out statistics results.
void AttractionClass::showResults()
{
    //Show the numbers of trains and riders
    cout << "Total number of trains operated today is " << trainsNum << endl;
    cout << "Total number of Riders visited the attraction " << attractionName
        << " today is " << totalRidersNum << endl;
    for (int i = 0; i < KIND_OF_PRIORITY; i++)
    {
        cout << ridersNum[i] << " with" << PRIORITY_STRING[i] << endl;
    }

    //Show averate wait time
    for (int i = 0; i < KIND_OF_PRIORITY; i++)
    {
        cout << "Teh average wait time for" << PRIORITY_STRING[i] << "was ";
        if (ridersNum[i] != 0)
        {
            cout << totalWaitTime[i] / ridersNum[i] << endl;
        }
        else
        {
            cout << "N/A" << endl;
        }
    }


    //Show what was the longest length of each line
    for (int i = 0; i < KIND_OF_PRIORITY; i++)
    {
        cout << "The longest length of" << PRIORITY_STRING[i] <<
             "was " << lineLength[i] <<endl;
    }
}