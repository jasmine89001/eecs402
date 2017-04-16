#include <iostream>

//Programmer: Yingjie Cai
//Date: April 2017
//Purpose: Implement the member functions of linkedNodeClass.

template < class T >
T LinkedNodeClass< T >::getValue() const
{
    return nodeVal;
}

template < class T >
LinkedNodeClass< T >* LinkedNodeClass< T >::getNext() const
{
    return nextNode;
}

template < class T >
LinkedNodeClass< T >* LinkedNodeClass< T >::getPrev() const
{
    return prevNode;
}

template < class T >
void LinkedNodeClass< T >::setNextPointerToNull()
{
    nextNode = NULL;
}

template < class T >
void LinkedNodeClass< T >::setPreviousPointerToNull()
{
    prevNode = NULL;
}

template < class T >
void LinkedNodeClass< T >::setBeforeAndAfterPointers()
{
    //Set the pointers in the nodes before and after the new
    //node to point to the new node
    if (prevNode != NULL)
    {
        prevNode->nextNode = this;
    }
    if (nextNode != NULL)
    {
        nextNode->prevNode = this;
    }
}