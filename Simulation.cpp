
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
#include "Simulation.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "FileReader.h"
#include "ProcessArrival.h"
#include "Process.h"
#include <iostream>
using namespace std;

Simulation::Simulation(){
    CPUprocesses = new Queue;
    IOprocesses = new Queue;
    eventList = new PriorityQueue;
    nextProcessID = 1;
}

void Simulation::runSimulation(char *file){
    dataReader = new FileReader(file);  // create the file reader
    nextProcessID = 1;
    QUANTUM_TIME = dataReader->getQuantumNumber(); // set the quantum time

    Process * firstProcess = new Process((dataReader->getLine()),nextProcessID);
   // cout << "First Process: ";
   // firstProcess->print();

    currentEvent = new ProcessArrival(firstProcess, this, dataReader);
    eventList->enqueue(currentEvent);

    while(!eventList->isEmpty()){
        currentEvent = dynamic_cast<Event*>(eventList->dequeue());
        if(currentEvent!= nullptr) {
            currentEvent->handleEvent(); // dynamic
        }

    }

    cout << "Event: " << eventList->getSize() << endl;
    cout << "CPU queue: " << CPUprocesses->getSize() << endl;
    cout << "IO queue: " << IOprocesses->getSize() << endl;
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

Process * Simulation::dequeueCPULine(){
    Process * toReturn = nullptr;
    if(!CPUprocesses->isEmpty()) {
        toReturn =  dynamic_cast<Process *>(CPUprocesses->dequeue());
    }
    return toReturn;
}
Process * Simulation::getFirstInCPULine(){
    Process * toReturn = nullptr;
    if(!CPUprocesses->isEmpty()) {
        toReturn = dynamic_cast<Process *>(CPUprocesses->getFront());
    }
    return toReturn;
}


Process * Simulation::dequeueIOLine(){
    Process * toReturn = nullptr;
    if(!IOprocesses->isEmpty()) {
        toReturn = dynamic_cast<Process *>(IOprocesses->dequeue());
    }
    return toReturn;
}

Process * Simulation::getFirstInIOLine(){
    Process * toReturn = nullptr;
    if(!IOprocesses->isEmpty()){
        toReturn = dynamic_cast<Process *>(IOprocesses->getFront());
    }
    return toReturn;
}




int Simulation::getQUANTUM_TIME() {
    return QUANTUM_TIME;
}

//bool Simulation::eventListEmpty(){return eventList->isEmpty(); }
bool Simulation::CPUInUse(){return !CPUprocesses->isEmpty(); }

bool Simulation::IOInUse(){return !IOprocesses->isEmpty(); }

//void Simulation::addToOutput(string line) {
//    cout << line;
//}

void Simulation::summarize(){

}

