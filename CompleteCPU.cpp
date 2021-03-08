//--------------------------------------------
// CLASS: CompleteCPU.cpp
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: creates a process and adds it to
//
//
//--------------------------------------------
#include "CompleteCPU.h"
#include "Simulation.h"
#include "Process.h"
#include <iostream>
using namespace std;

CompleteCPU::CompleteCPU(int time,Process * theProcess, Simulation * sim): Event(time,theProcess,sim){}

void CompleteCPU::handleEvent() {
    cout <<  "Time\t"<< eventTime <<": Process\t" << process->getID() << " completes CPU burst." << endl;
}

int CompleteCPU::compareTo(ListItem *other) {
    return Event::compareTo(other);
}

//void CompleteCPU::print() {
//    cout << "CompleteCPU event ";
//    Event::print();
//}