//--------------------------------------------
// CLASS: Queue.cpp
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: implementation of a queue
//--------------------------------------------
#include "Queue.h"
#include "ListItem.h"
#include "Node.h"

/**** Queue implementation */
Queue::Queue() : ParentQueue() {}

int Queue::getSize(){
    ParentQueue::getSize();
}

bool Queue::isEmpty(){
    ParentQueue::isEmpty();
}

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

ListItem *Queue::dequeue(){
    ParentQueue::dequeue();
}// dequeue


ListItem *Queue::getFront(){
    ParentQueue::getFront();
}// getFront

