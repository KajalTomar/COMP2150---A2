//--------------------------------------------
// CLASS: Process.cpp
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: Process class holds all the
// information related to a process.
//
//--------------------------------------------
#include "Process.h"
#include <sstream>
#include "Burst.h"
#include "Queue.h"
#include <iostream>
using namespace std;

Process::Process() {} // what should I initialize the values with here?

Process::Process(string entireProcess, int makeThisTheID) {
    burstRequests = new Queue; // make a queue of bursts for this process
    int tempBurstAmount; // will hold the burstAmount tokens one by one
    Burst * tempBurst;

    id = makeThisTheID; // set the id

    istringstream iss(entireProcess); // tokenize the string
    iss >> arrivalTime; // first number will always be the arrival time

    // go through each token in the string
    while(iss >> tempBurstAmount){
        tempBurst = new Burst(tempBurstAmount); // create a new burst item for each token
        burstRequests->enqueue(tempBurst); // add it to this process's list of requested bursts
    }

    tempBurst = dynamic_cast<Burst *>(burstRequests->dequeue()); // take out the first burst. This will be the current burst

    // safe down casting
    if (tempBurst != nullptr){
        currentBurst = tempBurst->getBurst();
    }
}

void Process::print(){
    cout << "ID: " << id << " / arrival time: " << arrivalTime << " / current burst: " << currentBurst << " / # of remaining bursts: " << burstRequests->getSize() << endl;
}

int Process::compareTo(ListItem *other){
    return -1; // you should implement this method.
}
