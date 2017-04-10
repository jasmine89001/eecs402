#include <iostream>

using namespace std;

const int MAX_SIZE_OF_DATASET = 100;
const int MAX_NUMBER_OF_BINS = 100;
const int NUM_PER_LINE = 5;
const int INDICATOR_OF_END_INPUT = -99999;


int promptUserAndGetChoice();

int main()
{
    SamplingClass sampleSet();
    int choice = -1;
    while (choice != 0) {
        choice = promptUserAndGetChoice();
        switch (choice)
        {
        case 1:

        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        }
    }
   
  //  cin >> inIdChar;

    
    return 0;
}

int promptUserAndGetChoice()
{
    int numOfChoice = -1;
    while (numOfChoice < 0 || numOfChoice > 6)
    {
        cout << "1. Enter a sample set of data values\n"
            << "2. Print the contents of the current sample set\n"
            << "3. Reset / Provide values for setting up a histogram\n"
            << "4. Add the contents of current sample set to histogram\n"
            << "5. Print bin counts contained in histogram\n"
            << "6. View the histogram in graphical form\n"
            << "0: Exit the program\n"
            << "Your Choice :";
        cin >> numOfChoice;
        if (numOfChoice < 0 || numOfChoice > 6)
        {
            cout << "ERROR: the input number must be an integer between 0 to 6!" << endl;
        }
    }
    return numOfChoice;
}

class SamplingClass
{
    private:
        char idChar;
        int numSamples;
        int samples[];

    public:
        SamplingClass() 
            // default ctor
        {
            //idChar = '0';
            numSamples = 0;
           // samples[numSamples] = { INDICATOR_OF_END_INPUT };
            cout << "ERROR!Using default class" << endl;
        }

        SamplingClass(const char inIdChar, const int inNumSamples, const int inputSamples[])
            // value ctor
        {
            idChar = inIdChar;
            numSamples = inNumSamples;
            for (int i = 0; i < numSamples; i++) {
                samples[i] = inputSamples[i];
            }
        }


        bool readFromKeyboard()
        {
            // This function reads attributes of SamplingClass object from standard input
            // If fail, an informative error message is displayed, and return false;otherwise, return true

            cout << "Enter character identifier for this sampling:";
            cin >> idChar;
            cout << "Enter all samples, then enter -99999 to end:"<< endl;
            int i = 0, currentNum;
            cin >> currentNum;
            while (currentNum != INDICATOR_OF_END_INPUT && i < MAX_SIZE_OF_DATASET)
            {
                samples[i] = currentNum;
                cin >> currentNum;
                i++;
            }

            if (i == MAX_SIZE_OF_DATASET) {
                cout << "ERROR! The number of input integers are beyond the set upper bound:"
                    << MAX_SIZE_OF_DATASET << endl;
                return false;
            }
            else {
                numSamples = i;
                cout <<"Last Operation Successful: YES" << endl;
                return true;
            }
        }


        bool printToScreen()
        {
            if (readFromKeyboard) {
                cout << "Data stored for sampling with identifier" << idChar << ":"<< endl;
                cout << "  Samples (" << NUM_PER_LINE << " samples per line):";

                for (int i = 0; i < numSamples; i++) {
                    if (i % NUM_PER_LINE == 0) {
                        cout << "\n ";
                    }
                    cout << "   " << "samples[i]";
                }

                cout << "\nLast Operation Successful: YES" << endl;
                return true;
            }
            else {
                cout << "ERROR: Can not print uninitialized sampling!" << endl;
                return false;
            }
        }

};

class HistogramClass
{

};