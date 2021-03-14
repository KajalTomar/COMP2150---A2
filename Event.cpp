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
#include "Process.h"
#include "ProcessArrival.h"
#include "Timeout.h"
#include <iostream>
using namespace std;

//------------------------------------------------------
// Event
//
// PURPOSE: the constructor for an Event object.
// PARAMETERS: time of event, a pointer the process,
//  a pointer to the simulation.
//------------------------------------------------------
Event::Event(int theTime, Process *theProcess, Simulation *theSim) 
	 :eventTime(theTime), process(theProcess), sim (theSim) {}

//------------------------------------------------------
// getEventTime
//
// PURPOSE: returns the event's time
// RETURNS: int (the time of the event)
//------------------------------------------------------
int Event::getEventTime() {
	return eventTime;
}

//------------------------------------------------------
// getProcessID
//
// PURPOSE: returns the process's ID
// RETURNS: int (the process's ID)
//------------------------------------------------------
int Event::getProcessID() {
    return process->getID();
}

//------------------------------------------------------
// compareTo
//
// PURPOSE: compares a given Event to itself based
//      on event's time first and if that ties then the
//      process ID.
// PARAMETERS: List item to compare with.
//  RETURNS: returns int
//      -2 = default return
//      -1 = this is higher priority, earlier in time or
//           lower process id if the time is the same.
//       1 = this has lower priority, later in time or
//           higher process if if time is the same.
//       0 = both events have the same time and process id
//------------------------------------------------------
int Event::compareTo(ListItem *other){
    int result = -2;
    Event * comparingTo = dynamic_cast<Event *>(other); // take out the first burst. This will be the current burst


    if (comparingTo != nullptr){
        // safe down casting

		if(eventTime == comparingTo->getEventTime()){
		    // if the event time is the same

		    // tie breaker, compare the process ID
           if(process->getID() <= comparingTo->getProcessID()){
                // this process ID is lower
                result = -1;
            }
            else {
                // the comparing event's process ID is lower
                result = 1;
            }
		}
		else if (eventTime < comparingTo->getEventTime()){
		    // if the event time's are different

            // this event took place earlier
            result = -1;
        } else {

		    // the other event took place earlier
            result = 1;
        }
    }

    return  result;
}



