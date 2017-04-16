#include <iostream>
#include "LinkedNodeClass.h"

using namespace std;

//Programmer: Yingjie Cai
//Date: April 2017
//Purpose: Implement the member functions of FIFOQueueClass.

//Inserts the value provided (newItem) into the queue.
template < class T >
void FIFOQueueClass< T >::enqueue(const T &newItem)
{
    LinkedNodeClass< T >* prevPtr = NULL;
    LinkedNodeClass< T >* nextPtr = NULL;
    LinkedNodeClass< T >* newNode;

    if (head == NULL && tail == NULL)   //if the queue is empty
    {
        newNode = new LinkedNodeClass< T >(prevPtr, newItem, nextPtr);
        head = newNode;
        tail = newNode;
    }
    else
    {
        prevPtr = tail;
        newNode = new LinkedNodeClass< T >(prevPtr, newItem, nextPtr);
        newNode->setBeforeAndAfterPointers();
        tail = newNode;
    }
}

//Attempts to take the next item out of the queue.
template < class T >
bool FIFOQueueClass< T >::dequeue(T &outItem)
{
    bool success = true;

    if (head == NULL && tail == NULL)   //if the queue is empty
    {
        success = false;
    }
    else if (tail != head)  //if the queue has more than one node
    {
        outItem = head->getValue();
        head = head->getNext();
        head->getPrev()->setNextPointerToNull();
        delete head->getPrev();
        head->setPreviousPointerToNull();
    }
    else   //if the queue has only one node
    {
        outItem = head->getValue();
        delete head;
        head = NULL;
        tail = NULL;
    }
    return success;
}

//Prints out the contents of the queue. 
template < class T >
void FIFOQueueClass< T >::print() const
{
    LinkedNodeClass< T >* currNode = head;
    while (currNode != NULL)
    {
        cout << currNode->getValue() << " ";
        currNode = currNode->getNext();
    }
    cout << endl;
}

//Returns the number of elements in the queue
template < class T >
int FIFOQueueClass< T >::getNumElems() const
{
    LinkedNodeClass< T >* temp = head;
    int numOfNodes = 0;
    while (temp != NULL)
    {
        temp = temp->getNext();
        numOfNodes++;
    }
    return numOfNodes;
}


