#define CATCH_CONFIG_MAIN
#include "catch.hpp"
//#include "Catch2.h"
#include "PriorityQueue.h"
#include "Simulation.h"
#include "StartCPU.h"
#include "Process.h"
#include <iostream>
using namespace std;
TEST_CASE("Testing enqueue edge cases"){

	// CHANGE THESE TEST BECAUSE EVENT IS A VIRTUAL CLASS
	// I JUST WANTED TO DO A QUICK TEST SO I MADE IT NON-VIRTUAL
	
	Simulation * sim = new Simulation();
	Process * newProcess = new Process("4 3 54 23 54",2);
	StartCPU* testEvent = new StartCPU(4, newProcess, sim);
	
	PriorityQueue * testQ = new PriorityQueue();
	
	testQ->enqueue(testEvent);  
	
	SECTION("Adding an item to an empty priority queue"){
		REQUIRE(testQ->getSize() == 1);
	} // SECTION 1
	
	SECTION("Adding an item with higher priority (earlier in time) to a priority queue with exactly one item"){
		Process * earliestProcess = new Process("1 2 4 5 -6 12",1);
        StartCPU* earliestEvent = new StartCPU(2, earliestProcess, sim);
		
		testQ->enqueue(earliestEvent);
		cout << "HERE" << endl;
		cout << "New item: " << endl;
        earliestEvent->print();
        testQ->getFront()->print();
		REQUIRE(earliestEvent->compareTo(testQ->getFront()) == 0);
		REQUIRE(testQ->getSize() == 2);
	
	} // SECTION 2
	
	
	SECTION("Adding a higgher priority item (later on in time) to a priority queue with exactly one item"){
		Process * laterProcess = new Process("20 43 -4 1 -6",15);
        StartCPU* laterEvent = new StartCPU(22, laterProcess, sim);
		
		testQ->enqueue(laterEvent); 
		
		REQUIRE(laterEvent->compareTo(testQ->getFront()) == 1);
		REQUIRE(testQ->getSize() == 2);
	
	} // SECTION 3

	// ADD A TEST FOR WHEN THERE IS ONLY ONE ITEM AND THE ITEM WE ARE ADDING HAS THE SAME TIME
	// ONE IS A TIMOUT EVENT AND THE OTHER IS A ARRIVAL EVENT. I
}

TEST_CASE("Testing enqueue general cases") {

    // CHANGE THESE TEST BECAUSE EVENT IS A VIRTUAL CLASS
    // I JUST WANTED TO DO A QUICK TEST SO I MADE IT NON-VIRTUAL

    Simulation * sim = new Simulation();

    PriorityQueue * testQ = new PriorityQueue();

    SECTION("Adding a events in an already correct order of priorities") {
        StartCPU* dequeued;

        cout << endl <<  endl << "TEST 4" << endl;
        for (int i = 0; i < 10; i++) {
            testQ->enqueue(new StartCPU(i, new Process(("4 3 54 23 54"), i), sim));
        }

        while(testQ->getSize()>=2){
            dequeued =  dynamic_cast<StartCPU*>(testQ->dequeue());

            dequeued->print();

            if(dequeued != nullptr && dequeued->compareTo(testQ->getFront())){
                REQUIRE(dequeued->compareTo(testQ->getFront()) <= 0);
                // dequeued event had a higher priority
            }
        }
    } // SECTION 4

    SECTION("Adding a events in opposite of correct order of priorities. So each event should is of a higher priority that everything else on the list") {
        StartCPU* dequeued;
        cout << endl <<  endl << "TEST 5" << endl;
        for (int i = 10; i > 0; i--) {
            testQ->enqueue(new StartCPU(i, new Process(("4 3 54 23 54"), i), sim));
        }

        while(testQ->getSize()>=2){
            dequeued =  dynamic_cast<StartCPU*>(testQ->dequeue());

            dequeued->print();

            if(dequeued != nullptr && dequeued->compareTo(testQ->getFront())){
                REQUIRE(dequeued->compareTo(testQ->getFront()) <= 0);
                // dequeued event had a higher priority
            }
        }

    } // SECTION 5

    SECTION("Adding a events in mixed up priority") {
        StartCPU* dequeued;

        cout << endl <<  endl << "TEST 4" << endl;

        testQ->enqueue(new StartCPU(13, new Process(("4 3 -54 23 -54"), 0), sim));
        testQ->enqueue(new StartCPU(54, new Process(("12 31 -4 3 -14"), 1), sim));
        testQ->enqueue(new StartCPU(2, new Process(("13 3 -3 9 -11"), 2), sim));
        testQ->enqueue(new StartCPU(12, new Process(("20 5"), 3), sim));
        testQ->enqueue(new StartCPU(7, new Process(("21 44 -10"), 4), sim));
        testQ->enqueue(new StartCPU(10, new Process(("25 4, -2, 12"), 5), sim));

        while(testQ->getSize()>=2){
            dequeued =  dynamic_cast<StartCPU*>(testQ->dequeue());

            dequeued->print();

            if(dequeued != nullptr && dequeued->compareTo(testQ->getFront())){
                REQUIRE(dequeued->compareTo(testQ->getFront()) <= 0);
                // dequeued event had a higher priority
            }
        }



    } // SECTION 5

}
