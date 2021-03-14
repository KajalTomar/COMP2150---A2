//--------------------------------------------
// CLASS: Process.cpp
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: Process class holds all the
// information related to a process.
//--------------------------------------------
#include "Process.h"
#include <sstream>
#include "Burst.h"
#include "Queue.h"
#include <iostream>
#include <cmath>
using namespace std;

//------------------------------------------------------
// Process
//
// PURPOSE: the constructor for a Process object.
// PARAMETERS: the string containing burst information
// the ID of this process
//------------------------------------------------------
Process::Process(string entireProcess, int makeThisTheID) {
    burstRequests = new Queue; // make a queue of bursts for this process
    int tempBurstAmount; // will hold the burstAmount tokens one by one
    totalBurstTime = 0;
    Burst * tempBurst;

    id = makeThisTheID; // set the id

    istringstream iss(entireProcess); // tokenize the string
    iss >> arrivalTime; // first number will always be the arrival time

    // go through each token in the string
    while(iss >> tempBurstAmount){
        totalBurstTime+=abs(tempBurstAmount);

        tempBurst = new Burst(tempBurstAmount); // create a new burst item for each token
        burstRequests->enqueue(tempBurst); // add it to this process's list of requested bursts
    }

    tempBurst = dynamic_cast<Burst *>(burstRequests->dequeue()); // take out the first burst. This will be the current burst

    // safe down casting
    if (tempBurst != nullptr){
        currentBurst = tempBurst->getBurst();
    }


}

//------------------------------------------------------
// getArrivalTime
//
// PURPOSE: returns the arrival time
// RETURNS: int (arrivalTime)
//------------------------------------------------------
int Process::getArrivalTime(){ return arrivalTime; }

//------------------------------------------------------
// getExitTime
//
// PURPOSE: returns the exit time
// RETURNS: int (ExitTime)
//------------------------------------------------------
int Process::getExitTime(){ return exitTime; }

//------------------------------------------------------
// getWaitTime
//
// PURPOSE: calculates and returns the wait time
// RETURNS: int
//------------------------------------------------------
int Process::getWaitTime(){ return ((exitTime-arrivalTime)-totalBurstTime); }

//------------------------------------------------------
// getID
//
// PURPOSE: returns the ID
// RETURNS: int id
//------------------------------------------------------
int Process::getID(){ return id; }

//------------------------------------------------------
// getCurrentBurst
//
// PURPOSE: returns the current burst time
// RETURNS: int
//------------------------------------------------------
int Process::getCurrentBurst() { return currentBurst;}

//------------------------------------------------------
// setExitTime
//
// PURPOSE: sets the wait time
// PARAMETERS: int (time)
//------------------------------------------------------
void Process::setExitTime(int time){ exitTime = time; }

//------------------------------------------------------
// updateCurrentBurst
//
// PURPOSE: updates the current burst time
// PARAMETERS: int (time)
//------------------------------------------------------
void Process::updateCurrentBurst(int time) {

       // for CPU bursts
       currentBurst-=time;

       if(currentBurst < 0){
           // if the burst is negative now, make it 0 because it's not
           // possible to request negative time
           currentBurst = 0;
       }

}

//------------------------------------------------------
// nextBurst
//
// PURPOSE: updates the current burst if another one
// exists in the burst queue
//------------------------------------------------------
void Process::nextBurst() {
    Burst * nextBurst = dynamic_cast<Burst *>(burstRequests->dequeue());

    if(nextBurst != nullptr){
        // if there was a burst in the queue

        // update current burst
        currentBurst = nextBurst->getBurst();
    }
}

//------------------------------------------------------
// noMoreBursts
//
// PURPOSE: check if there are more burst requests
// PARAMETERS: true if there are no more bursts,
// false otherwise
//------------------------------------------------------
bool Process::noMoreBursts() {
        bool empty = false;

        if(currentBurst==0 && burstRequests->isEmpty()){
            // if the current burst requests have been completed
            // and there are no more in the queue
            empty = true;
        }

        return empty;
}

//------------------------------------------------------
// compareTo
//
// PURPOSE: compares two processes.
// PARAMETERS: List item to compare with.
//  RETURNS: returns int
//      -2 = default return
//      -1 = this is higher priority and lower id
//       1 = this has lower priority and higher id
//       0 = both events have the same process id
//------------------------------------------------------
int Process::compareTo(ListItem *other){
    int result = -2;
    Process * comparingTo = dynamic_cast<Process *>(other); // take out the first burst. This will be the current burst

    // safe down casting
    if (comparingTo != nullptr){
        if(id == comparingTo->getID()){
            result = 0; // this is higher priority
        }
        else if (id < comparingTo->getID()){
            result = -1; // this is higher priority
        } else {
            result = 1; // this is lower priority
        }
    }

    return  result;
}
