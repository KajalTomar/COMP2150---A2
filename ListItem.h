//--------------------------------------------
// CLASS: Listitem.h
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: class definitions for the ListItem.cpp
// class. Just has a pure virtual method that
// all subclasses must implement.
//
//--------------------------------------------
#pragma once

class ListItem {
public:
	virtual int compareTo(ListItem *other) = 0;
//	virtual void print() = 0;
}; // class ListItem
