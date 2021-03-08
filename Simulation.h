//--------------------------------------------
// CLASS: Simulation.h
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: class definitions for the Simulation.cpp
// class.
//
//--------------------------------------------
#pragma once
#include <fstream>
using namespace std;

class Queue;
class PriorityQueue;
class Event;
class FileReader;
class Process;

class Simulation {
private:
    FileReader * dataReader;
    Queue * CPUprocesses;
    Queue * IOprocesses;
    PriorityQueue * eventList;
    Event * currentEvent;
    int QUANTUM_TIME;
    int nextProcessID;
    // you will need to add fields
	// including: Queues for CPU and IO, and priority queues for Events
public:
	Simulation();

	// runSimulation -- start the simulation with the given filename.
	// Called by main.
	void runSimulation(char *fileName);
    void addEvent(Event * toAdd);
    void addToCPULine(Process * toAdd);
    void addToIOLine(Process * toAdd);
    Process * dequeueCPULine();
  //  bool eventListEmpty();
    bool CPUInUse();
    bool IOInUse();
    int getNextIdNumber();
    int getQUANTUM_TIME();
    void processEvent();
	// summary -- print a summary of all the processes, as shown in the
	// assignment.  Called by main.
	void summary();

	// you may need to add more methods

};// class Simulation
