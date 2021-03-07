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
public:
    PriorityQueue();
    int getSize();
    bool isEmpty();
    void enqueue(ListItem *item);
    ListItem *getFront();
    ListItem *dequeue();
}; // class PriorityQueue
