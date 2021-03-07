#pragma once
#include "ListItem.h"
class Process;
//--------------------------------------------
// CLASS: Event.h
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: class definitions for the event.cpp
// class.
//
//--------------------------------------------
class Simulation;

class Event: public ListItem {
private:
	int eventTime;
	Process *process;
protected:
	Simulation *sim;
public:
	// constructor, with pointer to the process that is being handled, and the simulation.
	Event(int theTime, Process *theProcess, Simulation* sim); 

	// pure virtual method - to handle the current event when it is removed from the queue.
	// virtual void handleEvent() = 0;
	void handleEvent();

	// I made this for compareTo
	int getEventTime();

	// compareTo - used to order Events. 
	int compareTo(ListItem *other);
};// class Event
