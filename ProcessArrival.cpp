//--------------------------------------------
// CLASS: ProcessArrival.cpp
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: creates a process and adds it to
//
//
//--------------------------------------------
#include "ProcessArrival.h"
#include "Queue.h"
#include "FileReader.h"

ProcessArrival::ProcessArrival(Process * newProcess, Simulation * sim ,FileReader * fileReader): Event(newProcess->getTime(),newProcess,sim){
    dataReader = fileReader;
}

void ProcessArrival::handleEvent() {};

int ProcessArrival::compareTo(ListItem *other) {
    return -1;
}
