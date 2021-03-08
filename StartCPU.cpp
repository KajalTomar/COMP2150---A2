//--------------------------------------------
// CLASS: StartCPU.cpp
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: creates a process and adds it to
//
//
//--------------------------------------------
#include "StartCPU.h"
#include "Queue.h"
#include "FileReader.h"
#include "Simulation.h"
#include "Process.h"
#include <iostream>
using namespace std;

StartCPU::StartCPU(int time,Process * theProcess, Simulation * sim): Event(time,theProcess,sim){}

void StartCPU::handleEvent() {
    const int QUANTUM_TIME= sim ->getQUANTUM_TIME();
    if(process->getCurrentBurst() > QUANTUM_TIME){
        // need more time
        // update burstRequest
        process->updateCurrentBurst(QUANTUM_TIME);
        // this event time + quantumtime = new event time

        // schedule a timeout event

    } else {
        // this event time + bursttime = new event time
        // update burst
        // schedule a complete IO event
    }

}

int StartCPU::compareTo(ListItem *other) {
    return -1;
}

void StartCPU::print() {
    cout << "startCPU event ";
    Event::print();
}

