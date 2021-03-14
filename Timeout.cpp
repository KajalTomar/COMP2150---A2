//--------------------------------------------
// CLASS: Timeout.cpp
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: createsa StartCPU event
// for the process. Also checks the CPUqueue
// and starts a StarCPU event for the first item.
//--------------------------------------------
#include "Timeout.h"
#include "Simulation.h"
#include "ProcessArrival.h"
#include "Process.h"
#include "StartCPU.h"
#include <iostream>
using namespace std;

//------------------------------------------------------
// Timeout
//
// PURPOSE: the constructor for a Timeout object.
// Calls Event class's constructor.
// PARAMETERS: time of event, a pointer the process,
//  a pointer to the simulation.
//------------------------------------------------------
Timeout::Timeout(int time,Process * theProcess, Simulation * sim): Event(time,theProcess,sim){}

//------------------------------------------------------
// handleEvent
//
// PURPOSE: adds this process to the end of the CPUqueue
// and creates a startCPU event for the first item in
// the CPU queue.
//------------------------------------------------------
void Timeout::handleEvent() {
    cout <<  "Time\t"<< eventTime <<": Process\t" << process->getID() << " times out (needs " << process->getCurrentBurst() << " units total)." << endl;
    Process * firstInLine = sim->dequeueCPULine(); // dequeue

    if(process->compareTo(firstInLine)==0){
        // just to make sure that this process was first in line (so is the one that should be at timeout)

        // add this process to the cpu line
        sim->addToCPULine(process);
    }

    // get the first item from the CPU line
    firstInLine = nullptr;
    firstInLine = sim->getFirstInCPULine();

    if(firstInLine!= nullptr){
        // create a start CPU event for this process
        sim -> addEvent(new StartCPU(eventTime,firstInLine,sim));
    }

}

//------------------------------------------------------
// compareTo
//
// PURPOSE: compares a given Event to itself. If they have the
//      same time and the other Event is a ProcessArrival event,
//      then this event is always lower priority. Otherwise, it
//      calls it's parent's (Event class's) compareTo/
// PARAMETERS: List item to compare with.
//  RETURNS: returns int
//      -2 = default return
//      1 = this is lower priority
//------------------------------------------------------
int Timeout::compareTo(ListItem *other) {
    int result = -2;
    ProcessArrival * checkIfArrival = dynamic_cast<ProcessArrival *>(other);

    if((checkIfArrival != nullptr) && (eventTime == checkIfArrival->getEventTime())){
        // if we are comparing to a timeout event that took place at the same time

       result = 1; // other is higher priority
    }
    else {
        // call the parent's compareTo
        result = Event::compareTo(other);
    }

    return result;
}
