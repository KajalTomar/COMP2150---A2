//--------------------------------------------
// CLASS: Timeout.cpp
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: creates a process and adds it to
//
//
//--------------------------------------------
#include "Timeout.h"
#include "Simulation.h"
#include "Process.h"
#include <iostream>
using namespace std;

Timeout::Timeout(int time,Process * theProcess, Simulation * sim): Event(time,theProcess,sim){}

void Timeout::handleEvent() {
    cout <<  "Time\t"<< eventTime <<": Process\t" << process->getID() << " times out (needs " << process->getCurrentBurst() << "units total)." << endl;
}

int Timeout::compareTo(ListItem *other) {
    return Event::compareTo(other);
}
