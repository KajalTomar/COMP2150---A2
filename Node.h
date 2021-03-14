//--------------------------------------------
// CLASS: Node.h
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: class definitions for the Node.cpp
// class.
//
//--------------------------------------------
class ListItem;


/**** I didn't make any changes to this. It's exactly how it was given to us*/

class Node {
private:
	ListItem *item;
	Node *next;
public:
	Node();
	Node(ListItem *i, Node *n);
	Node *getNext();
	void setNext(Node *next);
	ListItem *getItem();
	void setItem(ListItem *i);
}; // class Node
