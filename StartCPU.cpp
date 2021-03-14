//--------------------------------------------
// CLASS: StartCPU.cpp
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: creates the appropriate event
// for the process depending on how many bursts
// it (still) needs (either completePPU event or
// timeout event).
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

//------------------------------------------------------
// StartCPU
//
// PURPOSE: the constructor for a StartCPU object.
// Calls Event class's constructor.
// PARAMETERS: time of event, a pointer the process,
//  a pointer to the simulation.
//------------------------------------------------------
StartCPU::StartCPU(int time,Process * theProcess, Simulation * sim): Event(time,theProcess,sim){}

//------------------------------------------------------
// handleEvent
//
// PURPOSE: create appropriate events depending for this
//      process depending on it's current burst requirements.
//------------------------------------------------------
void StartCPU::handleEvent() {
    cout <<  "Time\t"<< eventTime <<": Process\t" << process->getID() << " begins CPU burst";

    const int QUANTUM_TIME = sim ->getQUANTUM_TIME();
    const int requestedBurst = process->getCurrentBurst();


    if(requestedBurst > QUANTUM_TIME){
        // if the process requires more bursts then possible

        cout << " (will time out; needs "<<requestedBurst<<" units total)." << endl;

        // fulfill the bursts we can (quantum time)
        // update the process's current burst to reflect this
        process->updateCurrentBurst(QUANTUM_TIME);

        // create a timeout event for the process.
        sim->addEvent(new Timeout((eventTime+QUANTUM_TIME),process,sim));
    } else {
        // the process's requests are less than or equal to quantum time!

        cout << " (will complete all "<<requestedBurst<<" remaining units)." << endl;

        // fulfill the bursts we can (quantum time)
        // update the process's current burst to reflect this
        process->updateCurrentBurst(QUANTUM_TIME);
        process->nextBurst(); // make current burst = next burst

        // crate a completeCPU event for this process
        sim->addEvent(new CompleteCPU((eventTime+requestedBurst), process, sim));
    }

}




