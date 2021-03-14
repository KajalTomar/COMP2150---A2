//--------------------------------------------
// CLASS: Exit.cpp
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: updates process's exit time
// and add its to the summary queue.
//--------------------------------------------
#include "Exit.h"
#include "Simulation.h"
#include "Process.h"
#include "StartIO.h"
#include "StartCPU.h"
#include <iostream>
using namespace std;

//------------------------------------------------------
// Exit
//
// PURPOSE: the constructor for a Exit object.
// PARAMETERS: time of event, a pointer the process,
//  a pointer to the simulation.
//------------------------------------------------------
Exit::Exit(int time,Process * theProcess, Simulation * sim): Event(time,theProcess,sim){}

//------------------------------------------------------
// handleEvent
//
// PURPOSE: sets the exits time as the current time
//  adds this process to a list (so we can summarize it later)
//------------------------------------------------------
void Exit::handleEvent() {
    cout <<  "Time\t"<< eventTime <<": Process\t" << process->getID() << " exits the system." << endl;
    process->setExitTime(eventTime);
    sim->addToSummary(process);
}
