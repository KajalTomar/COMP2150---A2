//--------------------------------------------
// CLASS: StartCPU.h
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: class definitions for the
// StartCPU.cpp class.
//
//--------------------------------------------
#include "Event.h"
class Simulation;

class StartCPU: public Event {
private:

public:
    // constructor, with pointer to the process that is being handled, and the simulation.
    StartCPU(int time, Process * newProcess, Simulation * sim);

    // pure virtual method - to handle the current event when it is removed from the queue.
    void handleEvent();

    // compareTo - used to order Events.
    int compareTo(ListItem *other);

    void print();

};// class Event
