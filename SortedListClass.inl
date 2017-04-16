#include <iostream>

#include "LinkedNodeClass.h"
using namespace std;

//Programmer: Yingjie Cai
//Date: April 2017
//Purpose: Provide a class to provide a sorted list class.

//Copy constructor. Will make a complete copy of the list.
template< class T >
SortedListClass< T >::SortedListClass(const SortedListClass< T > &rhs)
{
    head = tail = NULL;
    LinkedNodeClass< T > *currNode;
    currNode = rhs.head;

    while (currNode != NULL)
    {
        this->insertValue(currNode->getValue());
        currNode = currNode->getNext();
    }
}

//Clears the list to an empty state without memory leaks.
template< class T >
void SortedListClass< T >::clear()
{
    T currVal;
    int numElems = this->getNumElems();
    for (int i = 0; i < numElems; i++)
    {
        this->removeFront(currVal);
    }
    head = tail = NULL;
}

//Allows the user to insert a value into the list. 
template< class T >
void SortedListClass< T >::insertValue(const T &valToInsert)
{
    LinkedNodeClass< T > *newNode;
    LinkedNodeClass< T > *currNode;

    //Find the correct position to insert
    if (head == NULL)  //if the list is empty
    {
        newNode = new LinkedNodeClass< T >(NULL, valToInsert, NULL);
        head = newNode;
        tail = newNode;
    }
    else //if the list is not empty
    {
        currNode = head;
        while (currNode != NULL && valToInsert >= currNode->getValue())
        {
            currNode = currNode->getNext();
        } //currNode now points to the node AFTER the correct position

        //Set pointers and val of newNode
        if (currNode == head)
        {
            newNode = new LinkedNodeClass< T >(NULL, valToInsert, head);
            head = newNode;
        }
        else if (currNode == NULL)
        {
            newNode = new LinkedNodeClass< T >(tail, valToInsert, NULL);
            tail = newNode;
        }
        else
        {
            newNode = new LinkedNodeClass< T >(currNode->getPrev(),
                valToInsert, currNode);
        }

        //Set nodes that before and after newNode
        newNode->setBeforeAndAfterPointers();
    }
}

//Prints the contents of the list from head to tail to the screen.
template< class T >
void SortedListClass< T >::printForward() const
{
    LinkedNodeClass< T > *currNode;
    cout << "Forward List Contents Follow:" << endl;
    currNode = head;
    while (currNode != NULL)
    {
        cout << "  " << currNode->getValue() << endl;
        currNode = currNode->getNext();
    }
    cout << "End Of List Contents" << endl;
}

//Prints the contents of the list from tail to head to the screen.
template< class T >
void SortedListClass< T >::printBackward() const
{
    LinkedNodeClass< T > *currNode;
    cout << "Backward List Contents Follow:" << endl;
    currNode = tail;
    while (currNode != NULL)
    {
        cout << "  " << currNode->getValue() << endl;
        currNode = currNode->getPrev();
    }
    cout << "End Of List Contents" << endl;
}

//Removes the front item from the list and returns the contained value.
template< class T >
bool SortedListClass< T >::removeFront(T &theVal)
{
    bool success;
    LinkedNodeClass< T > *currNode;
    success = true; 

    if (head == NULL) //if the list is empty
    {
        success = false;
    }
    else   //if the list is not empty
    {
        currNode = head;
        theVal = head->getValue();
        head = head->getNext();
        delete currNode;

        if (head == NULL) //if new list is empty
        {
            tail = NULL;
        }
        else //if the new list is not empty
        {
            head->setPreviousPointerToNull();
        }
    }
    return success;
}

//Removes the last item from the list and returns the contanined value.
template< class T >
bool SortedListClass< T >::removeLast(T &theVal)
{
    bool success;
    LinkedNodeClass< T > *currNode;
    success = true;

    if (tail == NULL)  //if the list is empty
    {
        success = false;
    }
    else  //if the list is not empty
    {
        currNode = tail;
        theVal = tail->getValue();
        tail = tail->getPrev();
        delete currNode;

        if (tail == NULL) //if new list is empty
        {
            head = NULL;
        }
        else // if the new list is not empty
        {
            tail->setNextPointerToNull();
        }
    }
    return success;
}

//Returns the number of nodes contained in the list.
template< class T >
int SortedListClass< T >::getNumElems() const
{
    int numNode = 0;
    LinkedNodeClass< T > *currNode;
    currNode = head;
    while (currNode != NULL)
    {
        numNode++;
        currNode = currNode->getNext();
    }
    return numNode;
}

//Provides the value stored in the node at index from input.
template< class T >
bool SortedListClass< T >::getElemAtIndex(const int index, T &outVal)
{
    bool success;
    LinkedNodeClass< T > *currNode;
    success = true;

    if (index < 0 || index >= this->getNumElems())
    {
        success = false;
    }
    else
    {
        currNode = head;
        for (int i = 0; i < index; i++)
        {
            currNode = currNode->getNext();
        }
        outVal = currNode->getValue();
    }
    return success;
}
