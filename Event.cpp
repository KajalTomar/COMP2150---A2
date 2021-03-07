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

	 // I made this for compareTo
int Event::getEventTime() {
	return eventTime;
}

// just for testing pQueue delete after bc Event is an abstract class
void handleEvent(){}
int Event::compareTo(ListItem *other){
    int result = -2; // -1 means we are smaller, 1 means we are bigger, 0 means the same
    Event * comparingTo = dynamic_cast<Event *>(other); // take out the first burst. This will be the current burst

    // safe down casting
    if (comparingTo != nullptr){
		if(eventTime == comparingTo->getEventTime()){
			result = 0;
		}
		else if (eventTime < comparingTo->getEventTime()){
            result = -1;
        } else {
            result = 1;
        }
    }

    return  result;
}

