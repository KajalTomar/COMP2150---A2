//--------------------------------------------
// CLASS: Burst.cpp
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: one burst. This is a subclass of
// ListType so we can create a list of bursts
//--------------------------------------------

#include "Burst.h"
#include <iostream>
using namespace std;

//------------------------------------------------------
// Burst
//
// PURPOSE: the constructor for a Burst object.
// PARAMETERS: burst time
//------------------------------------------------------
Burst::Burst(int newBurstTime) : burstTime(newBurstTime){}

//------------------------------------------------------
// getBurst
//
// PURPOSE: a getter method for the burst's time
// RETURNS: burst time
//------------------------------------------------------
int Burst::getBurst() { return burstTime; }

//------------------------------------------------------
// compareTo
//
// PURPOSE: compares a given burst to itself based
//      on how much time each burst requires.
// PARAMETERS: List item to compare with (will be safely
//  casted to make sure it's a  burst object before
//  comparing.
//  RETURNS: returns int
//      -2 = we were not comparing to a Burst item,
//      -1 = this item requires less time
//       1 = this item requires more time
//       0 = both bursts require equal time
//------------------------------------------------------
int Burst::compareTo(ListItem *other){
    int result = -2;
    Burst * comparingTo = dynamic_cast<Burst *>(other);

    if(comparingTo != nullptr) {
        if (burstTime == comparingTo->getBurst()) {
            result = 0; // same bursts
        } else if (burstTime < comparingTo->getBurst()) {
            result = -1; // this burst requires less time
        } else {
            result = 1; // this burst requires more time
        }
    }
    return result;
}


