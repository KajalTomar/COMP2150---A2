#include "Simulation.h"
#include <assert.h>
#include <string>
#include "Process.h"
#include "Queue.h"
#include <iostream>
using namespace std;

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
            newProcess = new Process(line, allProcesses->getSize());
            allProcesses->enqueue(newProcess);
        }

        cout << QUANTUM_TIME << endl;
        inFile.close();
        assert(!inFile.is_open());

    } else {
        cout << "error" << endl;
    }
}

void Simulation::summary(){}

