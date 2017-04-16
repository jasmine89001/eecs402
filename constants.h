#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

#include <string>
using namespace std;
//information for each priority of riders
const int KIND_OF_PRIORITY = 3; //Now we have SFP/FP/STD
const int SUPER_FAST_PASS = 0;
const int FAST_PASS = 1;
const int STANDARD_PASS = 2;
const string PRIORITY_STRING[3] = {" SFP ", " FP  ", " STD "};

//information about event type
const int TRAIN_TYPE = 1;
const int RIDER_TYPE = 2;

//information about the attraction park
const int MAX_NUM_SEATS = 20;
const string ATTRACTION_NAME = "Space Mountain";

//information about handling file stream
const int IFSTREAM_IGNORED_NUMBER = 200;
const char IFSTREAM_IGNORED_SIGN = '\n';

//information about uniform distribution when generating priority
const int PERCENT_MIN = 1;
const int PERCENT_MAX = 100;

#endif // _CONSTANTS_H_
