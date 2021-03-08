#include "Simulation.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "FileReader.h"
#include "ProcessArrival.h"
#include "Process.h"
//--------------------------------------------
// CLASS: Simulation.cpp
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: starts a simulation of the
// operating system by reading the file and
// managing the interactions between
// events and Processes.
//--------------------------------------------

#include <iostream>
using namespace std;

Simulation::Simulation(){
    CPUprocesses = new Queue;
    IOprocesses = new Queue;
    eventList = new PriorityQueue;
    nextProcessID = 0;
}

void Simulation::runSimulation(char *file){
    dataReader = new FileReader(file);  // create the file reader
    nextProcessID = 0;
    QUANTUM_TIME = dataReader->getQuantumNumber(); // set the quantum time
    //cout << QUANTUM_TIME << endl;
    Process * firstProcess = new Process((dataReader->getLine()),nextProcessID);
   // cout << "First Process: ";
   // firstProcess->print();

    currentEvent = new ProcessArrival(firstProcess, this, dataReader);
    eventList->enqueue(currentEvent);

    cout << "RIGHT BEFORE ENTERING WHILE LOOP" << endl;
    eventList->printList();

    while(!eventList->isEmpty()){
        currentEvent = dynamic_cast<ProcessArrival *>(eventList->dequeue());

        // the top eventList event is Process arrival
        if(currentEvent != nullptr){
            currentEvent->handleEvent();
        }

        cout << "AFTER LOOP" << endl;
        cout << "----------------------------------------" << endl;
        cout << "EVENTS: " << endl;
        eventList->printList();

        cout << endl << "CPU Processes: " << endl;
        CPUprocesses->printList();

        cout << endl << "IO Processes: " << endl;
        IOprocesses->printList();
    }
}

int  Simulation::getNextIdNumber(){
    nextProcessID++;
    return nextProcessID;
}

void Simulation::addEvent(Event *toAdd) {
    eventList->enqueue(toAdd);
}

void Simulation::addToCPULine(Process *toAdd) {
    CPUprocesses->enqueue(toAdd);
}

void Simulation::addToIOLine(Process *toAdd) {
    IOprocesses->enqueue(toAdd);
}

int Simulation::getQUANTUM_TIME() {
    return QUANTUM_TIME;
}

bool Simulation::eventListEmpty(){return eventList->isEmpty(); }

void Simulation::summary(){
}

