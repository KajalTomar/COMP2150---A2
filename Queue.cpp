//--------------------------------------------
// CLASS: Queue.cpp
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: implementation of a queue.
//--------------------------------------------
#include "Queue.h"
#include "ListItem.h"
#include "Node.h"

/**** Queue implementation */
/** The same as how it was given to use, just moved some methods to a parent class (also untouched)**/


Queue::Queue() : ParentQueue() {}

void Queue::enqueue(ListItem *item){
	// special case: adding to empty queue
	if(front == nullptr){
		front = new Node(item, nullptr);
		back = front;
	} else {
		back->setNext(new Node(item, nullptr));
		back = back->getNext();
	}
	size++;
}// enqueue




