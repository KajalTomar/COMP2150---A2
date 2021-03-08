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

    waitingTime = 0;

}

int Process::getArrivalTime(){ return arrivalTime; }

void Process::updateWaitTime(int time){ waitingTime+= time; }

void Process::updateCurrentBurst(int time) {

       // for CPU bursts
       currentBurst-=time;
       if(currentBurst < 0){
           currentBurst = 0;
       }

}

void Process::nextBurst() {
    Burst * nextBurst = dynamic_cast<Burst *>(burstRequests->dequeue());

    if(nextBurst != nullptr){
        currentBurst = nextBurst->getBurst();
    }
}

int Process::getCurrentBurst() { return currentBurst;}

bool Process::noMoreBursts() { return (burstRequests->isEmpty());}

//void Process::print(){
//    cout << "Process\t" << id << " / arrival time: " << arrivalTime << " / current burst: " << currentBurst << " / # of remaining bursts: " << burstRequests->getSize() << endl;
//}
int Process::getID(){ return id; }

int Process::compareTo(ListItem *other){
    int result = -2; // -1 means we are higher priority (smaller, earlier in time), 1 means we are lower priority (bigger, later in time), 0 means the same priority
    Process * comparingTo = dynamic_cast<Process *>(other); // take out the first burst. This will be the current burst

    // safe down casting
    if (comparingTo != nullptr){
        if (id < comparingTo->getID()){
            result = -1; // this is higher priority
        } else {
            result = 1; // lthis is lower priority
        }
    }

    return  result;
}
