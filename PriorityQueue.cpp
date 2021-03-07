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
    }
    else if (item->compareTo(front->getItem()) == -1) {
        // item has a higher priority than the first item on the list
        // no need to look through the whole list, just add this item to the front

        temp = new Node(item, front);
        front = temp;
    }
    else if(item->compareTo(back->getItem()) == 1) {
            // item has a lower priority than the last item on the list
            // no need to look through the whole list, just add this item to the back

            back->setNext(new Node(item, nullptr));
            back = back ->getNext();
    }
//    else if (size == 1){  // there is only one item in the priority queue
//            if (item->compareTo(getFront())== 1 ){
//                // item is has a higher priority than the first item on the list
//                back->setNext(new Node(item, nullptr));
//                back = back->getNext();
//            } else {
//                temp = new Node(item, front);
//                back = front;
//                front = temp;
//                // item comes before current first
//            }
//    }
    else {
        // there are more than one items in the priority queue
        // search for the right spot and add it there

        addInTheMiddle(item);
    }
    size++;
}// enPriorityQueue

void PriorityQueue::addInTheMiddle(ListItem *item) {
    bool foundSpot = false;
    Node * current;
    Node * beforeCurrent;


}



ListItem *PriorityQueue::dequeue(){
    return ParentQueue::dequeue();
}// dePriorityQueue


ListItem *PriorityQueue::getFront(){
    return ParentQueue::getFront();
}// getFront