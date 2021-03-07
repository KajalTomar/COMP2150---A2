//--------------------------------------------
// CLASS: ParentQueue.h
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: class definitions for the ParentQueue.cpp
// class.
//
//--------------------------------------------
#pragma once

class Node;
class ListItem;

class ParentQueue {
protected:
    Node *front;
    Node *back;
    int size;
public:
    ParentQueue();
    virtual int getSize();
    virtual bool isEmpty() ;
    virtual void enqueue(ListItem *item) =0;
    virtual ListItem *getFront();
    virtual ListItem *dequeue();

}; // class Queue
