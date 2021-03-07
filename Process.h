#pragma once
#include "ListItem.h"
#include <string>

class Queue;

using namespace std;
//--------------------------------------------
// CLASS: Process.h
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: class definitions for the Process.cpp
// class.
//
//--------------------------------------------
class Process: public ListItem {

private:
    int id; // unique id
    int arrivalTime;
    int currentBurst;   // we will deque bursts one at a time. current burst time is held because of quantum time
    Queue * burstRequests;

public:
    Process();
    Process(string entireProcess, int id);
    void print();
    int compareTo(ListItem *other);

};
