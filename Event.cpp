//--------------------------------------------
// CLASS: Event.cpp
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: superclass of all event classes,
// which are all the types of events that can
// take place during a Process's journey
// through the system.
// It defines the behaviours of it's subclasses.
//
//--------------------------------------------
#include "Event.h"

/**** Event implementation */
Event::Event(int theTime, Process *theProcess, Simulation *theSim) 
	 :eventTime(theTime), process(theProcess), sim (theSim) {}


int Event::compareTo(ListItem *other){
	return -1; // you should implement this method.
}

