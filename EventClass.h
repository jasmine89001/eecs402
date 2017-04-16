#ifndef _EVENTCLASS_H_
#define _EVENTCLASS_H_

#include <string>

#include "RiderClass.h"
#include "TrainClass.h"

//Programmer: Yingjie Cai
//Date: April 2017
//Purpose: Provide a single class to simulate events in a theme park.
//         Contain an event for riders and an event for trains.
using namespace std;

class EventClass
{
private:
    int eventType; //numerical value for event type
    int eventTime; //time of each event
    TrainClass trainEvent;
    RiderClass riderEvent;

public:
    //Default ctor
    EventClass();

    //Value ctor
    EventClass(RiderClass inRider);
    EventClass(TrainClass inTrain);

    //Get the rider event
    RiderClass getRider() const;

    //Get the train event
    TrainClass getTrain() const;

    //Get the event type
    int getEventType() const;

    //Get the event time
    int getEventTime() const;

    //Print out the event's details
    void printEvent();

    //Overload operator< in terms of eventTime
    bool operator<(const EventClass &inEvent) const;

    //Overload operator>=
    bool operator>=(const EventClass &inEvent) const;

    //Convert attributes to string to print out event class objects
    void toString(string &outStr) const;
};
//Overload operator insertion, used by EventClass
ostream& operator<<(ostream &os, const EventClass &inEvent);
#endif // _EVENTCLASS_H_
