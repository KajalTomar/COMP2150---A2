//--------------------------------------------
// CLASS: Burst.cpp
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: one burst. is a subclass of
// ListType so we can create a list of bursts
//
//--------------------------------------------

#include "Burst.h"
#include <iostream>
using namespace std;

Burst::Burst(){}
Burst::Burst(int newBurstTime) : burstTime(newBurstTime){}

int Burst::getBurst() { return burstTime; }

int Burst::compareTo(ListItem *other){
    int result = -2;
    Burst * comparingTo = dynamic_cast<Burst *>(other);

    if(comparingTo != nullptr){
        if(burstTime == comparingTo->getBurst()){
            result = 0; // same bursts
        }
        else if (burstTime < comparingTo->getBurst()){
            result = -1; // this burst requires less time
        } else {
            result = 1; // this burst requires more time
        }
    }
}

void Burst::print(){
    cout << "Burst Time: " << burstTime;
}