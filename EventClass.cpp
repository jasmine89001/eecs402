#include <iostream>
#include <sstream>
#include <string>

#include "EventClass.h"
#include "constants.h"

//Programmer: Yingjie Cai
//Date: April 2017
//Purpose: Provide a single class to simulate events in a theme park.
//         Contain an event for riders and an event for trains.

using namespace std;

//Default ctor
EventClass::EventClass()
{
    RiderClass rider;
    riderEvent = rider;
    TrainClass train;
    trainEvent = train;
    eventType = 0;
    eventTime = 0;
}

//Value ctor
EventClass::EventClass(RiderClass inRider)
{
    riderEvent = inRider;
    eventType = RIDER_TYPE;
    eventTime = inRider.getArrivalTime();

}
EventClass::EventClass(TrainClass inTrain)
{
    trainEvent = inTrain;
    eventType = TRAIN_TYPE;
    eventTime = inTrain.getArrivalTime();
}

//Get the rider event
RiderClass EventClass::getRider() const
{
    return riderEvent;
}

//Get the train event
TrainClass EventClass::getTrain() const
{
    return trainEvent;
}

//Get the event type
int EventClass::getEventType() const
{
    return eventType;
}

//Get the event time
int EventClass::getEventTime() const
{
    if (eventType == TRAIN_TYPE)
    {
        return trainEvent.getArrivalTime();
    }
    else
    {
        return riderEvent.getArrivalTime();
    }
}

//Print out the event's details
void EventClass::printEvent()
{
    if (eventType == TRAIN_TYPE)
    {
        cout << "A train will arrive at time " << 
            trainEvent.getArrivalTime() << endl;
    }
    else
    {
        string priorityStr = "";

        if (riderEvent.getPriority() == STANDARD_PASS)
        {
            priorityStr = "Standard";
        }
        else if (riderEvent.getPriority() == FAST_PASS)
        {
            priorityStr = "Fast Pass";
        }
        else
        {
            priorityStr = "Super Fast Pass";
        }
        cout << "A rider will arrive at time " << riderEvent.getArrivalTime()
            << "with priority " << priorityStr << endl;
    }
}

//Overload operator< in terms of eventTime
bool EventClass::operator<(const EventClass &inEvent) const
{
    return (eventTime < inEvent.eventTime);
}

//Overlaod operator>= in terms of eventTime
bool EventClass::operator>=(const EventClass &inEvent) const
{
    return (eventTime >= inEvent.eventTime);
}

//Convert attributes to string to print out event class objects
void EventClass::toString(string &outStr) const
{
    string type = "";
    if (eventType == RIDER_TYPE)
    {
        type = "Rider Event";
    }
    else
    {
        type = "Train Event";
    }
    ostringstream oss;
    oss << "Time of event is " << eventTime << ". Type of Event is " 
        << type << endl;
    outStr = oss.str();
}

//Overload operator insertion
ostream& operator<<(ostream &os, const EventClass &inEvent)
{
    string outStr;
    inEvent.toString(outStr);
    os << outStr;
    return os;
}

