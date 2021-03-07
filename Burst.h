//--------------------------------------------
// CLASS: Burst.h
//
// Author:Kajal Tomar, 7793306
//
// REMARKS: header for burst.cpp which is a
// subclass of ListType so we can create a list
// of bursts
//
//--------------------------------------------
#pragma once
#include "ListItem.h"

class Burst: public ListItem {

private:
    int burstTime;
public:
    Burst();
    Burst(int burstTime);
    int getBurst();
    int compareTo(ListItem *other);
};
