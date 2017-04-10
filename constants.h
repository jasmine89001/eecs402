#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

//Store all of needed global constants in this file
#include <string>

//Magic num for needed ppm file
const string PPM_MAGIC_NUM = "P3";

//Max valud of color
const int MAX_COLOR_VAL = 255;

//Provided choices in main menu
const int LOWER_BOUND_OF_MENU = 1;
const int CHOICE_FOR_RECTANGLE = 1;
const int CHOICE_FOR_PATTERN = 2;
const int CHOICE_FOR_INSERT_IMAGE = 3;
const int CHOICE_FOR_OUTPUT_IMAGE = 4;
const int CHOICE_FOR_EXIT = 5;

//Parameters when clear the stream
const int STREAM_SIZE = 100;
const char STREAM_IGNORE_SYMBOL = '\n';

//Porvided choices when choose color
const int CHOICE_FOR_RED = 1;
const int CHOICE_FOR_GREEN = 2;
const int CHOICE_FOR_BLUE = 3;
const int CHOICE_FOR_BLACK = 4;
const int CHOICE_FOR_WHITE = 5;

//Three methods when implementing a rectangle
const int CREATION_WITH_TWO_CORNERS = 1;
const int CREATION_WITH_ONE_CORNER = 2;
const int CREATION_WITH_CENTER = 3;

//Choices to determine whether to fill a rectangle or not
const int CHOICE_FOR_NO_FILL = 1;
const int CHOICE_FOR_FILL = 2;

#endif //  _CONSTANTS_H_

