
cmake_minimum_required(VERSION 3.17)
project(COMP2150___A2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(COMP2150___A2
        A2main.cpp
        Event.cpp
        Event.h
        ListItem.cpp
        ListItem.h
        Process.cpp
        Process.h
        Node.cpp
        Node.h
        Queue.cpp
        Queue.h
        Simulation.h
        Simulation.cpp
        Burst.cpp
        Burst.h
        ParentQueue.cpp
        ParentQueue.h
        )