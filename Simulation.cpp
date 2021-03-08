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
Simulation::Simulation(){}
#include <iostream>
using namespace std;

void Simulation::runSimulation(char *file){
    dataReader = new FileReader(file);
    CPUprocesses = new Queue;
    IOprocesses = new Queue;
    eventList = new PriorityQueue;

    QUANTUM_TIME = dataReader->getQuantumNumber();
    cout << QUANTUM_TIME << endl;
    Process * firstProcess = new Process((dataReader->getLine()),totalProcess);
    cout << "First Process: ";
    firstProcess->print();

    currentEvent = new ProcessArrival(firstProcess, this, dataReader);
    totalProcess++;
}

void Simulation::summary(){}

