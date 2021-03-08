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

}

int CompleteCPU::compareTo(ListItem *other) {
    return -1;
}

void CompleteCPU::print() {
    cout << "CompleteCPU event ";
    Event::print();
}