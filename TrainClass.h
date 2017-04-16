#ifndef _TRAINCLASS_H_
#define _TRAINCLASS_H_

//Programmer: Yingjie Cai
//Date: April 2017
//Purpose: Provide a class to simulate the train of cars in a theme park.

class TrainClass
{
private:
    int arrivalTime; //arrival time of the upcoming train
    int seatNum; //the total number of seats in the train

public:
    //Default ctor
    TrainClass();

    //Value ctor
    TrainClass(int inArrivalTime, int inSeatNum);

    //Get the arrival time of the upcoming train
    int getArrivalTime() const;
};
#endif //  _TRAINCLASS_H_