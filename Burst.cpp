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

Burst::Burst(){}
Burst::Burst(int newBurstTime) : burstTime(newBurstTime){}

int Burst::getBurst() { return burstTime; }

int Burst::compareTo(ListItem *other){
    return -1; // you should implement this method.
}