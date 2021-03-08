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

ParentQueue::ParentQueue() : front(nullptr), back(nullptr), size(0) {}

int ParentQueue::getSize(){
    return size;
}
bool ParentQueue::isEmpty(){
    return size == 0;
}

ListItem *ParentQueue::dequeue(){
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


ListItem *ParentQueue::getFront(){
    ListItem *theItem = nullptr;
    if(front != nullptr){
        theItem = front->getItem();
    }
    return theItem;
}// getFront
