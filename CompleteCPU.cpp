//--------------------------------------------
// CLASS: CompleteCPU.cpp
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: creates the appropriate event
// for the process depending on how many bursts
// it still needs (either exit event or StartIO
// event). Also checks the CPUqueue
// and starts a StarCPU event for the first item.
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

//------------------------------------------------------
// CompleteCPU
//
// PURPOSE: the constructor for a CompleteCPU object.
// Calls Event class's constructor.
// PARAMETERS: time of event, a pointer the process,
//  a pointer to the simulation.
//------------------------------------------------------
CompleteCPU::CompleteCPU(int time,Process * theProcess, Simulation * sim): Event(time,theProcess,sim){}

//------------------------------------------------------
// handleEvent
//
// PURPOSE: create appropriate events depending for this
//      process depending on it's current burst requirements.
//------------------------------------------------------
void CompleteCPU::handleEvent() {
    cout <<  "Time\t"<< eventTime <<": Process\t" << process->getID() << " completes CPU burst.";
    Process * firstInLine = sim->dequeueCPULine(); // dequeue the first item on the list


    if(process->compareTo(firstInLine)==0){
        // just to make sure that this process was first in line (so is the one that should be at completeCPU)

        if(process->noMoreBursts()){
            // if this process does not require anymore bursts
            // then create an Exit event for it
            cout << endl;
            sim->addEvent(new Exit(eventTime,process,sim));
        }
        else {
            // if this process requires more bursts
            cout << " Joining the IO queue." << endl;

            if(!sim->IOInUse()){
                // if IO is currently free
                // then create a startIO event for this process
                sim->addEvent(new StartIO(eventTime,process,sim));
            }

            // add this process to the IOQueue
            sim->addToIOLine(process);
        }
    }

    firstInLine = nullptr;

    if(sim->CPUInUse()){
        // if the CPU queue still has processes in line

        // get the first item from the queue
        firstInLine = sim->getFirstInCPULine();

        if(firstInLine!= nullptr){
            // create a start CPU event for this process
            sim->addEvent(new StartCPU(eventTime,firstInLine,sim));
        }
    }

} // handle
