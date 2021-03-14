//--------------------------------------------
// CLASS: Burst.h
//
// Author: Kajal Tomar, 7793306
//
// REMARKS: header for burst.cpp
//
//--------------------------------------------
#pragma once
#include "ListItem.h"

class Burst: public ListItem {
private:
    int burstTime;
public:
    Burst(int burstTime);
    int getBurst();
    int compareTo(ListItem *other);
};
