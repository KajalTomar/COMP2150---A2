//--------------------------------------------
// CLASS: CompleteIO.cpp
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: creates a process and adds it to
//
//
//--------------------------------------------
#include "CompleteIO.h"
#include "Simulation.h"
#include "Process.h"
#include "StartIO.h"
#include "StartCPU.h"
#include "Exit.h"
#include <iostream>
using namespace std;

CompleteIO::CompleteIO(int time,Process * theProcess, Simulation * sim): Event(time,theProcess,sim){}

void CompleteIO::handleEvent() {
    Process * firstInLine = sim->dequeueIOLine(); // dequeue
    cout <<  "Time\t"<< eventTime <<": Process\t" << process->getID() << " completes IO burst." << endl;

    if(process->compareTo(firstInLine)==0){
        if(!process->noMoreBursts()){
            if(!sim->CPUInUse()){
                sim->addEvent(new StartCPU(eventTime,process,sim));
            }
            sim->addToCPULine(process);
        } else {

            sim->addEvent(new Exit(eventTime,process,sim));
        }
    }


    firstInLine = nullptr;

    if(sim->IOInUse()){    // not empty
        firstInLine = sim->getFirstInIOLine();
        if(firstInLine!= nullptr){
            sim->addEvent(new StartIO(eventTime,firstInLine,sim));
        }
    }
}

//int CompleteIO::compareTo(ListItem *other) {
//    return Event::compareTo(other);
//}
