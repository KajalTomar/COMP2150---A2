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
//#include "Queue.h"
//#include "FileReader.h"
#include "Simulation.h"
#include "Process.h"
#include "Timeout.h"
#include "CompleteCPU.h"
#include <iostream>
using namespace std;

StartCPU::StartCPU(int time,Process * theProcess, Simulation * sim): Event(time,theProcess,sim){}

void StartCPU::handleEvent() {
    const int QUANTUM_TIME = sim ->getQUANTUM_TIME();
    const int requestedBurst = process->getCurrentBurst();

    if(requestedBurst > QUANTUM_TIME){
        process->updateCurrentBurst(QUANTUM_TIME);
        sim->addEvent(new Timeout((eventTime+QUANTUM_TIME),process,sim));
    } else {
        process->nextBurst(); // make current burst = next burst
        sim->addEvent(new CompleteCPU((eventTime+requestedBurst), process, sim));
    }

}

int StartCPU::compareTo(ListItem *other) {
    return -1;
}

void StartCPU::print() {
    cout << "startCPU event ";
    Event::print();
}

