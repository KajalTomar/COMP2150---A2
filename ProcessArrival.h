//--------------------------------------------
// CLASS: ProcessArrival.h
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: class definitions for the
// ProcessArrival.cpp class.
//
//--------------------------------------------
#include "Event.h"
class FileReader;
class Simulation;

class ProcessArrival: public Event {
private:
    FileReader * dataReader;
public:
    // constructor, with pointer to the process that is being handled, and the simulation.
    ProcessArrival(Process * newProcess, Simulation * sim ,FileReader * fReader);

    // pure virtual method - to handle the current event when it is removed from the queue.
    void handleEvent();

    // compareTo - used to order Events.
    int compareTo(ListItem *other);
};// class Event