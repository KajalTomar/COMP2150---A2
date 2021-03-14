
//--------------------------------------------
// CLASS: Simulation.cpp
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: starts a simulation of the
// operating system by reading the file.
// Keeps track of all the queues. Dequeues the
// event queue in order to keep the simulation
// running.
//--------------------------------------------
#include "Simulation.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "FileReader.h"
#include "ProcessArrival.h"
#include "Process.h"
#include <iostream>
using namespace std;

//------------------------------------------------------
// Simulation
//
// PURPOSE: the constructor for a Simulation object.
// starts all the queues and initializes the process id to 1
//------------------------------------------------------
Simulation::Simulation(){
    CPUprocesses = new Queue;
    IOprocesses = new Queue;
    eventList = new PriorityQueue;
    summary = new PriorityQueue;
    nextProcessID = 1;
}

//------------------------------------------------------
// runSimulation
//
// PURPOSE: runs the simulation by creating the first a
// arrival event. Then calling a method to handle events
// until the vent list is empty.
// PARAMETER: pointer to file to run simulation for
//------------------------------------------------------
void Simulation::runSimulation(char *file){
    dataReader = new FileReader(file);  // create the file reader
    QUANTUM_TIME = dataReader->getQuantumNumber(); // set the quantum time

    Process * firstProcess = new Process((dataReader->getLine()),nextProcessID); // create first process

    // and an arrival event for it and add it to the queue
    currentEvent = new ProcessArrival(firstProcess, this, dataReader);
    eventList->enqueue(currentEvent);

    while(!eventList->isEmpty()){
        // keep reading and handeling events until the list is empty

        currentEvent = dynamic_cast<Event*>(eventList->dequeue());

        if(currentEvent!= nullptr) {
            // safe casting

            currentEvent->handleEvent(); // dynamic
        }
    }

    dataReader->closeFile();

} // runSimulation

//------------------------------------------------------
// getFirstInIOLine
//
// PURPOSE: returns a pointer to the first Process in
//  IO line
//------------------------------------------------------
Process * Simulation::getFirstInIOLine(){
    Process * toReturn = nullptr;
    if(!IOprocesses->isEmpty()){
        toReturn = dynamic_cast<Process *>(IOprocesses->getFront());
    }
    return toReturn;
}

//------------------------------------------------------
// getQUANTUM_TIME
//
// PURPOSE: returns the quantum time
//------------------------------------------------------
int Simulation::getQUANTUM_TIME() {return QUANTUM_TIME; }

//------------------------------------------------------
// getNextIdNumber
//
// PURPOSE: increments the id number and returns it
//------------------------------------------------------
int  Simulation::getNextIdNumber(){
    nextProcessID++;
    return nextProcessID;
}

//------------------------------------------------------
// getFirstInCPULine
//
// PURPOSE: returns the first Process in the CPU line
// if it's not empty, nullptr otherwise
//------------------------------------------------------
Process * Simulation::getFirstInCPULine(){
    Process * toReturn = nullptr;
    if(!CPUprocesses->isEmpty()) {
        toReturn = dynamic_cast<Process *>(CPUprocesses->getFront());
    }
    return toReturn;
}

//------------------------------------------------------
// addEvent
//
// PURPOSE: adds event to the Event List
// PARAMETER: pointer for the event to add
//------------------------------------------------------
void Simulation::addEvent(Event *toAdd) {
    eventList->enqueue(toAdd);
}

//------------------------------------------------------
// addToSummary
//
// PURPOSE: adds process  to the summary List
// PARAMETER: pointer for the process to add
//------------------------------------------------------
void Simulation::addToSummary(Process *toAdd) {
    summary->enqueue(toAdd);
}

//------------------------------------------------------
// addToCPULine
//
// PURPOSE: adds process to the CPUqueue line
// PARAMETER: pointer for the process to add
//------------------------------------------------------
void Simulation::addToCPULine(Process *toAdd) {
    CPUprocesses->enqueue(toAdd);
}

//------------------------------------------------------
// addToIOLine
//
// PURPOSE: adds process to the IOqueue line
// PARAMETER: pointer for the process to add
//------------------------------------------------------
void Simulation::addToIOLine(Process *toAdd) {
    IOprocesses->enqueue(toAdd);
}

//------------------------------------------------------
// CPUInUse
//
// PURPOSE: check if the CPU is in use
// RETURNS: true if the CPU is in use (line is
// not empty), false otherwise (line is empty)
//------------------------------------------------------
bool Simulation::CPUInUse(){return !CPUprocesses->isEmpty(); }

//------------------------------------------------------
// IOinUse
//
// PURPOSE: check if the IO is in use
// RETURNS: true if the IO is in use (line is
// not empty), false otherwise (line is empty)
//------------------------------------------------------
bool Simulation::IOInUse(){return !IOprocesses->isEmpty(); }

//------------------------------------------------------
// dequeueCPULine
//
// PURPOSE: dequeue the CPU line
// RETURNS: a pointer to the dequeued Process
//------------------------------------------------------
Process * Simulation::dequeueCPULine(){
    Process * toReturn = nullptr;
    if(!CPUprocesses->isEmpty()) {
        toReturn =  dynamic_cast<Process *>(CPUprocesses->dequeue());
    }
    return toReturn;
}

//------------------------------------------------------
// dequeueIOLine
//
// PURPOSE: dequeue the IO line
// RETURNS: a pointer to the dequeued Process
//------------------------------------------------------
Process * Simulation::dequeueIOLine(){
    Process * toReturn = nullptr;
    if(!IOprocesses->isEmpty()) {
        toReturn = dynamic_cast<Process *>(IOprocesses->dequeue());
    }
    return toReturn;
}

//------------------------------------------------------
// dequeueIOLine
//
// PURPOSE: display the summary data from the summary
// queue.
// RETURNS: a pointer to the dequeued Process
//------------------------------------------------------
void Simulation::summarize(){
    Process * temp;

    cout << "Process #\tArrival Time\tExit Time\tWait Time"<<endl;
    cout << "------------------------------------------------------------------"<<endl;

    while(!summary->isEmpty()){
        // go throught the entire list of processes in summary
        temp = dynamic_cast<Process * >(summary->dequeue());

        if(temp!= nullptr){
            // display it's info
            cout << temp->getID() << "\t\t" << temp->getArrivalTime() << "\t\t" << temp->getExitTime() << "\t\t"<<temp->getWaitTime()<< endl;
        }
        temp = nullptr;
    }
}

