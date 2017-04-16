#include "TrainClass.h"

//Programmer: Yingjie Cai
//Date: April 2017
//Purpose: Implement a class to simulate the train of cars in a theme park.

//Default ctor
TrainClass::TrainClass()
{
    arrivalTime = 0;
    seatNum = 0;
}

//Value ctor
TrainClass::TrainClass(int inArrivalTime, int inSeatNum)
{
    arrivalTime = inArrivalTime;
    seatNum = inSeatNum;
}

//Get the arrival time of the upcoming train
int TrainClass::getArrivalTime() const
{
    return arrivalTime;
}