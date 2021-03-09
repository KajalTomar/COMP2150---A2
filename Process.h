//--------------------------------------------
// CLASS: Process.h
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: class definitions for the Process.cpp
// class.
//
//--------------------------------------------
#pragma once
#include "ListItem.h"
#include <string>
using namespace std;

class Queue;

class Process: public ListItem {

private:
    int id; // unique id
    int arrivalTime;
    int currentBurst;   // we will deque bursts one at a time. current burst time is held because of quantum time
    Queue * burstRequests;
    int totalBurstTime;
    int exitTime;

public:
    Process();
    Process(string entireProcess, int id);
    void print();
    int getArrivalTime();
    int getID();
    int getExitTime();
    int getWaitTime();
    void setExitTime(int time);
    void updateCurrentBurst(int time);
    void nextBurst();
    int getCurrentBurst();
    bool noMoreBursts();

    int compareTo(ListItem *other);


};
