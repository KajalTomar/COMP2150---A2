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
#include "ProcessArrival.h"
#include "Process.h"
#include "StartCPU.h"
#include <iostream>
using namespace std;

Timeout::Timeout(int time,Process * theProcess, Simulation * sim): Event(time,theProcess,sim){}

void Timeout::handleEvent() {
    Process * firstInLine = sim->dequeueCPULine(); // dequeue
    cout <<  "Time\t"<< eventTime <<": Process\t" << process->getID() << " times out (needs " << process->getCurrentBurst() << " units total)." << endl;

    if(process->compareTo(firstInLine)==0){
        sim->addToCPULine(process);
    }

    firstInLine = nullptr;
    firstInLine = sim->getFirstInCPULine();

    if(firstInLine!= nullptr){
        sim -> addEvent(new StartCPU(eventTime,firstInLine,sim));
    }

}

int Timeout::compareTo(ListItem *other) {
    int result = 0;
    ProcessArrival * checkIfArrival = dynamic_cast<ProcessArrival *>(other);

    if((checkIfArrival != nullptr) && (eventTime == checkIfArrival->getEventTime())){ //  it's a processArrival event
       result = 1; // other is higher
    } else {
        result = Event::compareTo(other);
    }

    return result;
}
