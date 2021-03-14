//--------------------------------------------
// CLASS: ParentQueue.cpp
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: superclass of all types of queue
// classes.
// To group together the queue classes and minimize
// code duplication.
//--------------------------------------------

#include "ParentQueue.h"
#include "ListItem.h"
#include "Node.h"
#include <iostream>
using namespace std;

//------------------------------------------------------
// ParentQueue
//
// PURPOSE: the constructor for a CompleteIO object.
// sets everythine to nullptr and 0
//------------------------------------------------------
ParentQueue::ParentQueue() : front(nullptr), back(nullptr), size(0) {}

//------------------------------------------------------
// getSize
//
// PURPOSE: returns the size of the queue
// REUTRNS: size of queue
//------------------------------------------------------
int ParentQueue::getSize(){
    return size;
}

//------------------------------------------------------
// isEmpty
//
// PURPOSE: to check if the queue is empty
// RETURNS: true if the queue is empty, false otherwise
//------------------------------------------------------
bool ParentQueue::isEmpty(){
    return size == 0;
}

//------------------------------------------------------
// dequeue
//
// PURPOSE: to dequeue an item
// RETURNS: the first List item in queue
//------------------------------------------------------
ListItem *ParentQueue::dequeue(){

    /* I didn't change anything here. It's from the given queue implementation*/
    ListItem *theItem = nullptr;
    Node *theNode = front;
    if(front != nullptr){
        theItem = front->getItem();
        // special case: removing last item
        if(front == back){
            front = back = nullptr;
        } else {
            front = front->getNext();
        }
        size--;
        delete(theNode);
    }
    return theItem;
}// dequeue

//------------------------------------------------------
// getFront
//
// PURPOSE: to get a pointer to the first item on the list
// RETURNS: the pointer to the first List item in queue
//------------------------------------------------------
ListItem *ParentQueue::getFront(){
    /* I didn't change anything here. It's from the given queue implementation*/
    ListItem *theItem = nullptr;
    if(front != nullptr){
        theItem = front->getItem();
    }
    return theItem;
}// getFront
