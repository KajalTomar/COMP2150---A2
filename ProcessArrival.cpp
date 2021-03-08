//--------------------------------------------
// CLASS: ProcessArrival.cpp
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: creates a process and adds it to
//
//
//--------------------------------------------
#include "ProcessArrival.h"
#include "Queue.h"
#include "FileReader.h"
#include "Simulation.h"
#include "StartCPU.h"
#include "Process.h"
#include <iostream>
using namespace std;

ProcessArrival::ProcessArrival(Process * newProcess, Simulation * sim ,FileReader * fileReader): Event(newProcess->getArrivalTime(),newProcess,sim){
    dataReader = fileReader;
}

void ProcessArrival::handleEvent() {
    Process * newProcess;
    // if eventlist empty then create a startcpu event and add it to the event priority queue
    if(sim->eventListEmpty()){
        sim->addEvent(new StartCPU(process->getArrivalTime(),process,sim));
    }

    // record time spend waiting = 0

    if(!dataReader->isEmpty()){
        // create new arrival event
        newProcess = new Process(dataReader->getLine(),sim->getNextIdNumber()); // i didn't include process.h but it's working...
        // add it to the simulation event list
        sim->addEvent(new ProcessArrival(newProcess, sim, dataReader));
    }
}

int ProcessArrival::compareTo(ListItem *other) {
    return -1;
}

void ProcessArrival::print() {
    cout << "arrival event ";
    Event::print();
}
