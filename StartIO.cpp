//--------------------------------------------
// CLASS: StartIO.cpp
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: creates a completeIO event for
// a process and updates it's burst.
//--------------------------------------------
#include "StartIO.h"
//#include "Queue.h"
//#include "FileReader.h"
#include "Simulation.h"
#include "Process.h"
#include <cmath>
#include "CompleteIO.h"
//#include "CompleteIO.h"
#include <iostream>
using namespace std;

//------------------------------------------------------
// StartIO
//
// PURPOSE: the constructor for a StartIO object.
// Calls Event class's constructor.
// PARAMETERS: time of event, a pointer the process,
//  a pointer to the simulation.
//------------------------------------------------------
StartIO::StartIO(int time,Process * theProcess, Simulation * sim): Event(time,theProcess,sim){}

//------------------------------------------------------
// handleEvent
//
// PURPOSE: create appropriate events depending for this
//      process depending on it's current burst requirements.
//------------------------------------------------------
void StartIO::handleEvent() {
    cout <<  "Time\t"<< eventTime <<": Process\t" << process->getID() << " begins IO burst" << endl;
    const int requestedBurst = process->getCurrentBurst();
    const int timeAfterBurst = eventTime+abs(requestedBurst);

    // fulfill the bursts we can (quantum time)
    // update the process's current burst to reflect this
    process->updateCurrentBurst(requestedBurst);
    process->nextBurst();

    // create a completeIO event for this process
    sim->addEvent(new CompleteIO(timeAfterBurst,process,sim));

}
