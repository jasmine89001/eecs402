#ifndef _RIDERCLASS_H_
#define _RIDERCLASS_H_

//Programmer: Yingjie Cai
//Date: April 2017
//Purpose: Provide a class to simulate riders with different priorities 
//         in a theme park.

class RiderClass
{
private:
    int arrivalTime; //arrival time of each rider
    int waitTime;  //wait time for each rider in the line
    int priority;  //priority of each rider

public:
    //Default ctor
    RiderClass();

    //Value ctor
    RiderClass(int inArrivalTime, int inPriority);

    //Get the arrival time for each rider
    int getArrivalTime() const;

    //Get the priority of each rider
    int getPriority() const;

    //Set the wait time of each rider
    void setWaitTime(int trainArrivalTime);

    //Get the wait time of each rider
    int getWaitTime() const;
};
#endif // _RIDERCLASS_H_
