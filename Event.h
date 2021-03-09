
//--------------------------------------------
// CLASS: Event.h
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: class definitions for the event.cpp
// class.
//
//--------------------------------------------
#pragma once
#include "ListItem.h"
class Process;
class Simulation;

class Event: public ListItem {
protected:
    int eventTime;
    Process * process;
	Simulation * sim;
public:
	// constructor, with pointer to the process that is being handled, and the simulation.
	Event(int theTime, Process *theProcess, Simulation* sim); 

	// pure virtual method - to handle the current event when it is removed from the queue.
	virtual void handleEvent() = 0;

	int getEventTime();
    int getProcessID();

	virtual int compareTo(ListItem *other);

};// class Event
