#include <iostream>
using namespace std;
//------------------------------------------------------------------------
// File: project2.cpp
//
// Programmer: Yingjie Cai
//
// Date: 02/14/2017
//
// Motivation: This program is a practice of class operation in C++.
// Functions: Allow user to input values of sample sets,
// and then create historgrams that are also defined by user input.
//
// Environment: Linux
//------------------------------------------------------------------------

const int MAX_SIZE_OF_DATASET = 100;
const int MAX_NUMBER_OF_BINS = 100; // Total 102 bins including <min and >max
const int NUM_PER_LINE = 5;
const int INDICATOR_OF_END_INPUT = -99999;
const int PERCENTANGE_OF_BAR = 2;
const int CHOICE_FOR_INPUT_SAMPLE = 1;
const int CHOICE_FOR_PRINT_SAMPLE = 2;
const int CHOICE_FOR_SETUP_HISTOGRAM = 3;
const int CHOICE_FOR_ADD_DATA_TO_HISTOGRAM = 4;
const int CHOICE_FOR_PRINT_HISTOGRAM_COUNT = 5;
const int CHOICE_FOR_PRINT_HISTOGRAM_PERCENT = 6;
const int CHOICE_FOR_QUIT = 0;


int promptUserAndGetChoice(); // Build the main interface to get choice
void operateResult(bool condition); // Print messages on success or not
float calculatePercent(int count, int totalCount); // Compute percent
void showPercent(int count, int totalCount); // Display a bin's percent


class SamplingClass
{
public:
    SamplingClass();    // Default ctor
    SamplingClass(const char inIdChar, const int inNumSamples,
        const int inputSamples[]);  // Value ctor
    bool readFromKeyboard();    // Read attributes from standard input
    bool printToScreen();   // Print the current state of a class object
    int getNumSamples();    // Return the number of elements in a sample
    int getSamplesI(int i); // Return the ith element in a sample


private:
    char idChar;    // identifier
    int numSamples; // the number of elements in a sample
    int samples[MAX_SIZE_OF_DATASET];   // elements stored in array
};


class HistogramClass
{
public:
    HistogramClass();// Modified default ctor
    bool setupHistogram(); // Setup a histogram from standard inputs
    bool addDataToHistogram(SamplingClass &sampling);// Add counts to bins
    bool printHistogramCounts();    // Print out bin counts and percentages
    bool displayHistogram();    // Display counts in a graphed form

private:
    int minRange;   // The lower limit of bins' range
    int maxRange;   // The upper limit of bins' range
    int numOfBins;  // The number of envenly divided bins
    int binCounts[MAX_SIZE_OF_DATASET]; // Array of counter in each bin
};


#ifdef ANDREW_TEST
#include "andrewTest.h"
#else
int main()
{
    SamplingClass sampling;
    HistogramClass histogram;

    int choice = CHOICE_FOR_QUIT - 1;
    while (choice != CHOICE_FOR_QUIT) 
    {
        choice = promptUserAndGetChoice();
        if (choice == CHOICE_FOR_INPUT_SAMPLE)
        {
            operateResult(sampling.readFromKeyboard());
        }
        else if (choice == CHOICE_FOR_PRINT_SAMPLE)
        {
            operateResult(sampling.printToScreen());
        }
        else if (choice == CHOICE_FOR_SETUP_HISTOGRAM)
        {
            operateResult(histogram.setupHistogram());
        }
        else if (choice == CHOICE_FOR_ADD_DATA_TO_HISTOGRAM)
        {
            operateResult(histogram.addDataToHistogram(sampling));
        }
        else if (choice == CHOICE_FOR_PRINT_HISTOGRAM_COUNT)
        {
            operateResult(histogram.printHistogramCounts());
        }
        else if (choice == CHOICE_FOR_PRINT_HISTOGRAM_PERCENT)
        {
            operateResult(histogram.displayHistogram());
        }
    }
    cout << "Thanks for using the histogram generator!" << endl;
    cout << "Last Operation Successful: YES" << endl;
    return 0;
}
#endif

// Global functioin definitions
int promptUserAndGetChoice()
{
    // Build the main interface to get usesr's choice
    // Valid input are integers within [0,6], then returned to main
    int numOfChoice = CHOICE_FOR_QUIT - 1;   // Initialize in order to enter the while loop
    while (numOfChoice < CHOICE_FOR_QUIT || 
        numOfChoice > CHOICE_FOR_PRINT_HISTOGRAM_PERCENT)
    {
        cout << "\n1. Enter a sample set of data values\n"
        << "2. Print the contents of the current sample set\n"
        << "3. Reset / Provide values for setting up a histogram\n"
        << "4. Add the contents of current sample set to histogram\n"
        << "5. Print bin counts contained in histogram\n"
        << "6. View the histogram in graphical form\n"
        << "0: Exit the program\n"
        << "\nYour Choice: ";
        cin >> numOfChoice;
        if (numOfChoice < CHOICE_FOR_QUIT || 
        numOfChoice > CHOICE_FOR_PRINT_HISTOGRAM_PERCENT)  // If input is invalid
        {
            cout << "Sorry that is an invalid menu choice - try again!";
        }
    }
    return numOfChoice;
}


void operateResult(bool condition)
{
    // Print informative messages to show whether the operation succed or not
    // The condition comes from member funtions typed bool
    if (condition)
    {
        cout << "Last Operation Successful: YES" << endl;
    }
    else
    {
        cout << "Last Operation Successful: NO" << endl;
    }
}

float calculatePercent(int count, int totalCount)
{
    // Given count in a bin and total count, calculate percentage
    return (100 * static_cast<float> (count) / totalCount); // Cast
}


void showPercent(int count, int totalCount)
{
    // Given count in a bin and total count, calculate the number of "="
    int numOfGragh = static_cast<int> (calculatePercent(count, totalCount)
        / PERCENTANGE_OF_BAR);
    for (int i = 0; i < numOfGragh; i++) 
    {
        cout << "=";
    }
    cout << "\n";
}


// Class member function definitions
SamplingClass::SamplingClass()
{
    // Default ctor
    idChar = '\0';  // Later will be recognized uninitialzed by this idChar
    numSamples = 0;
}


SamplingClass::SamplingClass(const char inIdChar, const int inNumSamples,
    const int inputSamples[])
{
    // Value ctor
    if(inNumSamples > MAX_SIZE_OF_DATASET)
    {
        idChar = '\0';  // If fails, set as default ctor
        cout << "ERROR: number of elements in a sample should be within "
        << MAX_SIZE_OF_DATASET << "." << endl;
    }
    else
    {
        idChar = inIdChar;
        numSamples = inNumSamples;
        for (int i = 0; i < inNumSamples; i++) 
        {
            samples[i] = inputSamples[i];
        }
    }

}


int SamplingClass::getNumSamples()
{
    // Get the number of elements in a SamplingClass ojbect
    return numSamples;
}


int SamplingClass::getSamplesI(int i)
{
    // Get the ith element in a SamplingClass object
    return samples[i];
}


bool SamplingClass::readFromKeyboard()
{
    // Read attributes of SamplingClass object from standard input
    // Execute when select 1
    // Return true on success, false otherwise
    cout << "Enter character identifier for this sampling: ";
    cin >> idChar;
    cout << "Enter all samples, then enter -99999 to end:" << endl;
    int i = 0, currentNum;
    cin >> currentNum;
    while (currentNum != INDICATOR_OF_END_INPUT && i < MAX_SIZE_OF_DATASET)
    {
        samples[i] = currentNum;
        cin >> currentNum;
        i++;
    }
    numSamples = i;
    if (numSamples == MAX_SIZE_OF_DATASET)  // Bound check
    {
        idChar = '\0';  // If fails, set as default ctor
        cout << "ERROR: number of elements in a sample should be within "
        << MAX_SIZE_OF_DATASET << "." << endl;
        return false;
    }
    else
    {
        return true;
    }
}


bool SamplingClass::printToScreen()
{
    // Print the current state of a sampling class object
    // Execute when select 2
    // Return true on success, false otherwise
    if (idChar == '\0')         // Return false if object uninitialized
    {
        cout << "ERROR: Can not print uninitialized sampling!" << endl;
        return false;
    }
    else                        // Print out if object initialized
    {
        cout << "Data stored for sampling with identifier "
        << idChar << ":" << endl;
        cout << " Total Samples: " << numSamples << endl;
        cout << "  Samples (" << NUM_PER_LINE << " samples per line):";

        for (int i = 0; i < numSamples; i++)
        {
            if (i % NUM_PER_LINE == 0) 
            {
                cout << "\n ";
            }
            cout << "   " << samples[i];
        }
        cout << "\n";
        return true;
    }
}


HistogramClass::HistogramClass()
{
    // Default ctor
    minRange = 0;
    maxRange = 0;       // Later will be recognized by this pair of 0s
    for (int i = 0;i < MAX_NUMBER_OF_BINS + 2; i++)
    {
       binCounts[i] = 0;    // Set all counts are 0s if uninitialized
    }

}


bool HistogramClass::setupHistogram()
{
    // Set up a histogram by min, max value and num of bins
    // Execute when select 3
    // Return true on success, false otherwise
    int inputMin, inputMax, inputNum;
    cout << "Enter minimum value: ";
    cin >> inputMin;
    cout << "Enter maximum value: ";
    cin >> inputMax;

    if (inputMin >= inputMax)          // Return false if unvalid inputs
    {
        cout << "ERROR: max value must be greater than min value!" << endl;
        minRange = 0;
        maxRange = 0;
        return false;
    }

    cout << "Enter number of bins: ";
    cin >> inputNum;
    if (inputNum > MAX_NUMBER_OF_BINS) // Bound check
    {
        minRange = 0;
        maxRange = 0; // If fails, set as default ctor
        cout << "ERROR: number of bins should be within "
        << MAX_NUMBER_OF_BINS << "." << endl;
        return false;
    }
    else if ((inputMax + 1 - inputMin) % inputNum != 0) 
    {
        cout << "ERROR: Num bins must evenly divide spedified range." << endl;
        minRange = 0;
        maxRange = 0;
        return false;                  // Return false if unvalid inputs
    }
    else 
    {
        minRange = inputMin;  // If valid, assign them to class distributes
        maxRange = inputMax;
        numOfBins = inputNum;
        for(int i = 0; i < numOfBins + 2; i++)  // Re-initialize when reset
        {
            binCounts[i] = 0;
        }
        return true;
    }
}


bool HistogramClass::addDataToHistogram(SamplingClass &sampling)
{
    // Add counts to the previously set-up histogram's bins
    // Execute when select 4
    // Return true on success, false otherwise
    if (minRange == 0 && maxRange == 0) 
    {
        cout << "ERROR: Can not add to uninitialized histogram!" << endl;
        return false;       // Return false if bins are uninitialized
    }
    else {
        int numSamples = sampling.getNumSamples();
        int currentSample;
        int elementsNum = (maxRange + 1 - minRange) / numOfBins;

        for (int i = 0; i < numSamples; i++)
        {
            // Assign elements in sample into proper bins iteratively
            currentSample = sampling.getSamplesI(i);
            if (currentSample < minRange)
            {
                binCounts[0]++;
            }
            else if (currentSample > maxRange)
            {
                binCounts[numOfBins + 1]++;
            }
            else
            {
                binCounts[(currentSample - minRange) / elementsNum + 1]++;
            }
        }
        return true;
    }
}


bool HistogramClass::printHistogramCounts()
{
    // Print out the bin counts and percentage(as float type)
    // Execute when select 5
    // Return true on success, false otherwise
    int sumCounts = 0;
    for (int i = 0; i < numOfBins + 2; i++)
    {
        sumCounts += binCounts[i];  // Calculate whole number of counts
    }

    if (minRange == 0 && maxRange == 0)
    {
        cout << "ERROR: Can not display uninitialized histogram!" << endl;
        return false;       // Return false if bins are uninitialized
    }
    
    for (int i = 0; i < numOfBins + 2; i++)
        {
            // Calculate percentage and  show results
            if (i == 0)
            {
                cout << "Bin <min: ";
            }
            else if (i == numOfBins + 1)
            {
                cout << "Bin >max: ";
            }
            else
            {
                cout << "Bin    " << i << ": ";
            }

            if (sumCounts != 0)
            {
                cout << binCounts[i] << "  ("
                << calculatePercent(binCounts[i], sumCounts) 
                << "%)" << endl;
            }
            else
            {
                cout << binCounts[i] << "  ("
                << calculatePercent(binCounts[i], 1) << "%)" << endl;
            }

        }
    return true;
}


bool HistogramClass::displayHistogram()
{
    // Display a graph-like representation of the histogram contents
    // Execute when select 6
    // Return true on success, false otherwise
    int sumCounts = 0;
    for (int i = 0; i < numOfBins + 2; i++)
    {
        sumCounts += binCounts[i];
    }

    if (minRange == 0 && maxRange == 0) 
    {
        cout << "ERROR: Can not display uninitialized histogram!" << endl;
        return false;             // Return false with uninitialized bins
    }

    else
    {
        for (int i = 0; i < numOfBins + 2; i++)
        {
            // Show all results
            if (i == 0)
            {
                cout << "Bin <min: ";
            }
            else if (i == numOfBins + 1)
            {
                cout << "Bin >max: ";
            }
            else
            {
                cout << "Bin    " << i << ": ";
            }
            if (sumCounts == 0) // If not data added, pass sumCounts by 1
            {                   // since 0 cannot be divided by 0 
                showPercent(binCounts[i], 1);
            }
            else
            {
                showPercent(binCounts[i], sumCounts);
            }
        }
    }
    return true;
}
