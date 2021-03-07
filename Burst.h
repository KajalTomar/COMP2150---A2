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
