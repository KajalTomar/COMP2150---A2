//--------------------------------------------
// CLASS: ProcessArrival.cpp
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: reads in new processes. Starts
// events and adds processed to appropriate
// queues.
//--------------------------------------------
#include "ProcessArrival.h"
#include "Queue.h"
#include "FileReader.h"
#include "Simulation.h"
#include "StartCPU.h"
#include "Process.h"
#include "Timeout.h"
#include <iostream>
using namespace std;

//------------------------------------------------------
// ProcessArrival
//
// PURPOSE: the constructor for a ProcessArrival object.
// Calls Event class's constructor.
// PARAMETERS: time of event, a pointer the process,
//  a pointer to the simulation.
//------------------------------------------------------
ProcessArrival::ProcessArrival(Process * newProcess, Simulation * sim ,FileReader * fileReader): Event(newProcess->getArrivalTime(),newProcess,sim){
    dataReader = fileReader;
}

//------------------------------------------------------
// handleEvent
//
// PURPOSE: create appropriate events depending for this
//      process depending on it's current burst requirements.
//      read in the next process and add it to CPUqueue
//------------------------------------------------------
void ProcessArrival::handleEvent() {
    Process * newProcess;

    cout <<  "Time\t"<< eventTime <<": Process\t" << process->getID() << " arrives in the system";

    if(!sim->CPUInUse()){
        // if CPU is not in use, then create a startcpu event and add it to the event priority queue

        cout << ": CPU is free (process begins execution)." << endl;
        sim->addEvent(new StartCPU(process->getArrivalTime(),process,sim));
    }
    else {
        // the cpu is busy
        cout << ": CPU is busy (process will be queued)." << endl;
    }

    // add it to the CPU Queue
    sim->addToCPULine(process);

    if(!dataReader->isEmpty()){

        // create new arrival event
        newProcess = new Process(dataReader->getLine(),sim->getNextIdNumber()); // i didn't include process.h but it's working...

        // add it to the simulation event list
        sim->addEvent(new ProcessArrival(newProcess, sim, dataReader));
    }
}

//------------------------------------------------------
// compareTo
//
// PURPOSE: compares a given Event to itself. If they have the
//      same time and the other Event is a timeout event, then
//      this event is always higher priority. Otherwise, it
//      calls it's parent's (Event class's) compareTo/
// PARAMETERS: List item to compare with.
//  RETURNS: returns int
//      -2 = default return
//      -1 = this is higher priority
//------------------------------------------------------
int ProcessArrival::compareTo(ListItem *other) {
    int result = -2;
    Timeout * checkIfTimeout = dynamic_cast<Timeout *>(other);

    if((checkIfTimeout != nullptr) && (eventTime == checkIfTimeout->getEventTime())){
        // if we are comparing to a timeout event that took place at the same time
        result = -1; // this is higher
    }
    else {
        // call the parent's compareTo
        result = Event::compareTo(other);
    }

    return result;
}

