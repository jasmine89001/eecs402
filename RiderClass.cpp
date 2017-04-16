#include <iostream>
#include "RiderClass.h"

//Programmer: Yingjie Cai
//Date: April 2017
//Purpose: Implement functions the class of RiderClass.

//Default ctor
RiderClass::RiderClass()
{
    arrivalTime = 0;
    priority = 0;
    waitTime = 0;
}

////Value ctor
RiderClass::RiderClass(int inArrivalTime, int inPriority)
{

    arrivalTime = inArrivalTime;
    priority = inPriority;
    waitTime = 0;
}

//Get the arrival time for each rider
int RiderClass::getArrivalTime() const
{
    return arrivalTime;
}

//Get the priority of each rider
int RiderClass::getPriority() const
{
    return priority;
}

//Set the wait time of each rider
void RiderClass::setWaitTime(int trainArrivalTime)
{
    waitTime = trainArrivalTime - arrivalTime;
}

//Get the wait time of each rider
int RiderClass::getWaitTime() const
{
    return waitTime;
}
