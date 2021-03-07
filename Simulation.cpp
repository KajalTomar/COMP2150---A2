#include "Simulation.h"
#include <assert.h>
#include <string>
#include "Process.h"
#include "Queue.h"
#include <iostream>
using namespace std;

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

void Simulation::runSimulation(char *file){
    allProcesses = new Queue;
    Process * newProcess;
    string line;
    ifstream inFile;
    inFile.open("initTest.txt");

    assert(inFile);

    if(inFile){
        inFile >> QUANTUM_TIME;
        inFile.ignore();
        while(getline(inFile, line)){
    // 		cout << line << endl;
	//		cout << "Size = " << (allProcesses -> getSize()) << endl;
			newProcess = new Process(line, allProcesses->getSize());
    		allProcesses->enqueue(newProcess);
        }
        cout << QUANTUM_TIME << endl;
        inFile.close();
        assert(!inFile.is_open());
    } else {
        cout << "An error occured while opening the files" << endl;
    }
	
}

void Simulation::summary(){}

