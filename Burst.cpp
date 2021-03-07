#include "Burst.h"

Burst::Burst(){}
Burst::Burst(int newBurstTime) : burstTime(newBurstTime){}

int Burst::getBurst() { return burstTime; }

int Burst::compareTo(ListItem *other){
    return -1; // you should implement this method.
}