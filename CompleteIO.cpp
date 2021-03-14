//--------------------------------------------
// CLASS: CompleteIO.cpp
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: creates the appropriate event
// for the process depending on how many bursts
// it still needs (either startIO event or exit
// event. Also checks the IOqueue
// and starts a StartIO event for the first item.
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

//------------------------------------------------------
// CompleteIO
//
// PURPOSE: the constructor for a CompleteIO object.
// PARAMETERS: time of event, a pointer the process,
//  a pointer to the simulation.
//------------------------------------------------------
CompleteIO::CompleteIO(int time,Process * theProcess, Simulation * sim): Event(time,theProcess,sim){}

//------------------------------------------------------
// handleEvent
//
// PURPOSE: create appropriate events depending for this
//      process depending on it's current burst requirements.
//------------------------------------------------------
void CompleteIO::handleEvent() {
    cout <<  "Time\t"<< eventTime <<": Process\t" << process->getID() << " completes IO burst.";
    Process * firstInLine = sim->dequeueIOLine(); // dequeue

    if(process->compareTo(firstInLine)==0){
        // just to make sure that this process was first in line (so is the one that should be at completeIO)

        if(!process->noMoreBursts()){
            // if this process requires more bursts
            cout << " Joining the CPU queue." << endl;

            if(!sim->CPUInUse()){
                // if CPU is currently free
                // then create a startCPU event for this process
                sim->addEvent(new StartCPU(eventTime,process,sim));
            }
            sim->addToCPULine(process);
        }
        else {
            cout << endl;

            // if this process does not require anymore bursts
            // then create an Exit event for it
            sim->addEvent(new Exit(eventTime,process,sim));
        }
    }


    firstInLine = nullptr;

    if(sim->IOInUse()){
        // if the IO queue still has process in line

        // get the first item from the queue
        firstInLine = sim->getFirstInIOLine();

        if(firstInLine!= nullptr){
            // create a startIO event for this process
            sim->addEvent(new StartIO(eventTime,firstInLine,sim));
        }
    }

} // handle

