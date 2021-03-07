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
    return ParentQueue::getSize();
}

bool PriorityQueue::isEmpty(){
    return ParentQueue::isEmpty();
}

//void PriorityQueue::setBack(Node *newBack) {
//    back = item;
//}

void PriorityQueue::enqueue(ListItem *item){
    Node * temp;
    // special case: adding to empty PriorityQueue
    if(front == nullptr){
        front = new Node(item, nullptr);
        back = front;
    } else if (size == 1){  // there is only one item in the list
        if (item->compareTo(getFront())== 1){
            // item is has a later time than the first item on the list
            back->setNext(new Node(item, nullptr));
            back = back->getNext();
        } else {
            temp = new Node(item, front);
            back = front;
            front = temp;
            // item comes before current first
        }
        // search for the correct spot
    }
    size++;
}// enPriorityQueue

ListItem *PriorityQueue::dequeue(){
    return ParentQueue::dequeue();
}// dePriorityQueue


ListItem *PriorityQueue::getFront(){
    return ParentQueue::getFront();
}// getFront