//--------------------------------------------
// CLASS: Queue.h
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: class definitions for the Queue.cpp
// class.
//
//--------------------------------------------
#pragma once
#include "ParentQueue.h"
class Node;
class ListItem;

class Queue : public ParentQueue {
private:
public:
	Queue();
	int getSize();
	bool isEmpty();
	void enqueue(ListItem *item);
	ListItem *getFront();
	ListItem *dequeue();
}; // class Queue
