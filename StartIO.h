//--------------------------------------------
// CLASS: StartIO.h
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: class definitions for the
// StartIO.cpp class.
//
//--------------------------------------------
#include "Event.h"
class Simulation;

class StartIO: public Event {
private:

public:
    // constructor, with pointer to the process that is being handled, and the simulation.
    StartIO(int time, Process * newProcess, Simulation * sim);
    // pure virtual method - to handle the current event when it is removed from the queue.
    void handleEvent();

};// class Event
