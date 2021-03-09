//--------------------------------------------
// CLASS: StartIO.cpp
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: creates a process and adds it to
//
//
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

StartIO::StartIO(int time,Process * theProcess, Simulation * sim): Event(time,theProcess,sim){}

void StartIO::handleEvent() {
    const int requestedBurst = process->getCurrentBurst();
    const int timeAfterBurst = eventTime+abs(requestedBurst);
    cout <<  "Time\t"<< eventTime <<": Process\t" << process->getID() << " begins IO burst" << endl;

    process->updateCurrentBurst(requestedBurst);
    process->nextBurst();
    sim->addEvent(new CompleteIO(timeAfterBurst,process,sim));

}

//int StartIO::compareTo(ListItem *other) {
//    return Event::compareTo(other);
//}