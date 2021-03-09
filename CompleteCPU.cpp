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
#include "StartIO.h"
#include "Exit.h"
#include "StartCPU.h"
#include <iostream>
using namespace std;

CompleteCPU::CompleteCPU(int time,Process * theProcess, Simulation * sim): Event(time,theProcess,sim){}

void CompleteCPU::handleEvent() {
    Process * firstInLine = sim->dequeueCPULine(); // dequeue
    cout <<  "Time\t"<< eventTime <<": Process\t" << process->getID() << " completes CPU burst." << endl;

    if(process->compareTo(firstInLine)==0){
        if(process->noMoreBursts()){
            sim->addEvent(new Exit(eventTime,process,sim));
        } else {
            if(!sim->IOInUse()){
                sim->addEvent(new StartIO(eventTime,process,sim));
            }
            sim->addToIOLine(process);
        }
    }

    firstInLine = nullptr;

    if(sim->CPUInUse()){    // not empty
        firstInLine = sim->getFirstInCPULine();
        if(firstInLine!= nullptr){
            sim->addEvent(new StartCPU(eventTime,firstInLine,sim));
        }
    }

}
//
//int CompleteCPU::compareTo(ListItem *other) {
//    return Event::compareTo(other);
//}

//void CompleteCPU::print() {
//    cout << "CompleteCPU event ";
//    Event::print();
//}