#include "Event.h"
class Simulation;

class CompleteCPU: public Event {
private:

public:
    // constructor, with pointer to the process that is being handled, and the simulation.
    CompleteCPU(int time, Process * newProcess, Simulation * sim);

    // pure virtual method - to handle the current event when it is removed from the queue.
    void handleEvent();
};// class Event
