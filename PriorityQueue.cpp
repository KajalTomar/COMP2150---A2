//--------------------------------------------
// CLASS: PriorityPriorityQueue.cpp
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: implementation of a PriorityQueue
//--------------------------------------------
#include "PriorityQueue.h"
#include "ParentQueue.h"
#include "ListItem.h"
#include "Node.h"

/**** PriorityQueue implementation */
PriorityQueue::PriorityQueue() : ParentQueue() {}

int PriorityQueue::getSize(){
    ParentQueue::getSize();
}

bool PriorityQueue::isEmpty(){
    ParentQueue::isEmpty();
}

void PriorityQueue::enqueue(ListItem *item){
    // special case: adding to empty PriorityQueue
    // implement priority queue
    size++;
}// enPriorityQueue

ListItem *PriorityQueue::dequeue(){
    ParentQueue::dequeue();
}// dePriorityQueue


ListItem *PriorityQueue::getFront(){
    ParentQueue::getFront();
}// getFront