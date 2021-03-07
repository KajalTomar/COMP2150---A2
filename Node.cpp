//--------------------------------------------
// CLASS: Node.cpp
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: The node class for our implementation
// of a queue (linked list). Holds ListItems.
//
//--------------------------------------------
#include "Node.h"
#include "ListItem.h"

/**** Node implementation */
Node::Node() : item(nullptr), next(nullptr)  {}

Node::Node(ListItem *i, Node *n) : item(i), next(n) {}

Node *Node::getNext() {
	return next;
}

void Node::setNext(Node *n) {
	next=n;
}

ListItem *Node::getItem() {
	return item;
}
