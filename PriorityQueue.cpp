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
#include "Event.h"
#include "Node.h"
// take this everything after this comment  out
#include <iostream>
using namespace std;

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
        if (front == nullptr) {
            front = new Node(item, nullptr);
            back = front;
        } else if (item->compareTo(front->getItem()) == -1) {
            // item has a higher priority than the first item on the list
            // no need to look through the whole list, just add this item to the front
            temp = new Node(item, front);
            front = temp;
            temp = nullptr;
        } else if (item->compareTo(back->getItem()) == 1) {
            // item has a lower priority than the last item on the list
            // no need to look through the whole list, just add this item to the back

            back->setNext(new Node(item, nullptr));
            back = back->getNext();
        }
        else {

            // there are more than one items in the priority queue
            // search for the right spot and add it there

            addInTheMiddle(item);
        }
        size++;

}// enPriorityQueue

void PriorityQueue::addInTheMiddle(ListItem *item) {
    bool foundSpot = false;
    Node * current = front;
    Node * beforeCurrent = nullptr;

    while (current && !foundSpot) {
            beforeCurrent = current;
            current = current->getNext();

            if((current->getItem())->compareTo(item) == 1){
                // current is of a lower priority or the same
                // later if 1 then current is a lower priority
                // 0 = same priority
                // right now this means we would add this new item
                // before the old item (change later to account for timeout
                // and arrival event)
                foundSpot = true;
            }
    }

    beforeCurrent->setNext(new Node(item, current));

}

ListItem *PriorityQueue::dequeue(){
    return ParentQueue::dequeue();
}// dePriorityQueue


ListItem *PriorityQueue::getFront(){
    return ParentQueue::getFront();
}// getFront

