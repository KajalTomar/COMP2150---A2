// Author: Kajal Tomar, 7793306
//
// REMARKS: class definitions for the PriorityQueue.cpp
// class.
//
//--------------------------------------------
#pragma once
#include "ParentQueue.h"
class Node;
class ListItem;

class PriorityQueue : public ParentQueue {
private:
    void addInTheMiddle(ListItem *item);
public:
    PriorityQueue();
    int getSize();
    bool isEmpty();
    void enqueue(ListItem *item);
    //void setBack(Node * newBack);
    ListItem *getFront();
    ListItem *dequeue();
    void printList();
}; // class PriorityQueue
