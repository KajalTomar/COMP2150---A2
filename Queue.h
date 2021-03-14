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
	void enqueue(ListItem *item);
}; // class Queue
