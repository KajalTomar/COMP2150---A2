//--------------------------------------------
// CLASS: Exit.cpp
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: creates a process and adds it to
//
//
//--------------------------------------------
#include "Exit.h"
#include "Simulation.h"
#include "Process.h"
#include "StartIO.h"
#include "StartCPU.h"
#include <iostream>
using namespace std;

Exit::Exit(int time,Process * theProcess, Simulation * sim): Event(time,theProcess,sim){
    cout <<  "Time\t"<< eventTime <<": Process\t" << process->getID() << " exits the system." << endl;
}

void Exit::handleEvent() {

}

int Exit::compareTo(ListItem *other) {
    return Event::compareTo(other);
}