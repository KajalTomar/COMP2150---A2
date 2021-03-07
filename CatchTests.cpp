#define CATCH_CONFIG_MAIN
#include "catch.hpp"
//#include "Catch2.h"
#include "PriorityQueue.h"
#include "Simulation.h"
#include "Process.h"
#include "Event.h"

TEST_CASE("Testing enqueue edge cases"){

	// CHANGE THESE TEST BECAUSE EVENT IS A VIRTUAL CLASS
	// I JUST WANTED TO DO A QUICK TEST SO I MADE IT NON-VIRTUAL
	
	Simulation * sim = new Simulation();
	Process * newProcess = new Process("4 3 54 23 54",2);
	Event * testEvent = new Event(4, newProcess, sim);
	
	PriorityQueue * testQ = new PriorityQueue();
	
	testQ->enqueue(testEvent);  
	
	SECTION("Adding an item to an empty priority queue"){
		REQUIRE(testQ->getSize() == 1);
	} // SECTION 1
	
	SECTION("Adding an item with lower priority (earlier in time) to a priority queue with exactly one item"){
		Process * earliestProcess = new Process("1 2 4 5 -6 12",1);
		Event * earliestEvent = new Event(2, earliestProcess, sim);
		
		testQ->enqueue(earliestEvent); 

		REQUIRE(earliestEvent->compareTo(testQ->getFront()) == 0);
		REQUIRE(testQ->getSize() == 2);
	
	} // SECTION 2
	
	
	SECTION("Adding a higgher priority item (later on in time) to a priority queue with exactly one item"){
		Process * laterProcess = new Process("20 43 -4 1 -6",15);
		Event * laterEvent = new Event(22, laterProcess, sim);
		
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
        Event * dequeued;

        for (int i = 0; i < 10; i++) {
            testQ->enqueue(new Event(i, new Process(("4 3 54 23 54"), i), sim));
        }

        while(testQ->getSize()>=2){
            dequeued =  dynamic_cast<Event *>(testQ->dequeue());

            if(dequeued != nullptr && dequeued->compareTo(testQ->getFront())){
                REQUIRE(dequeued->compareTo(testQ->getFront()) <= 0);
                // dequeued event had a higher priority
            }
        }

    } // SECTION 4

    SECTION("Adding a events in opposite of correct order of priorities. So each event should is of a higher priority that everything else on the list") {
        Event * dequeued;

        for (int i = 10; i > 0; i--) {
            testQ->enqueue(new Event(i, new Process(("4 3 54 23 54"), i), sim));
        }

        while(testQ->getSize()>=2){
            dequeued =  dynamic_cast<Event *>(testQ->dequeue());

            if(dequeued != nullptr && dequeued->compareTo(testQ->getFront())){
                REQUIRE(dequeued->compareTo(testQ->getFront()) <= 0);
                // dequeued event had a higher priority
            }
        }

    } // SECTION 5

    SECTION("Adding a events in mixed up priority") {
        Event * dequeued;


        testQ->enqueue(new Event(13, new Process(("4 3 -54 23 -54"), 0), sim));
        testQ->enqueue(new Event(54, new Process(("12 31 -4 3 -14"), 1), sim));
        testQ->enqueue(new Event(2, new Process(("13 3 -3 9 -11"), 2), sim));
        testQ->enqueue(new Event(12, new Process(("20 5"), 3), sim));
        testQ->enqueue(new Event(7, new Process(("21 44 -10"), 4), sim));
        testQ->enqueue(new Event(10, new Process(("25 4, -2, 12"), 5), sim));

        while(testQ->getSize()>=2){
            dequeued =  dynamic_cast<Event *>(testQ->dequeue());

            if(dequeued != nullptr && dequeued->compareTo(testQ->getFront())){
                REQUIRE(dequeued->compareTo(testQ->getFront()) <= 0);
                // dequeued event had a higher priority
            }
        }

    } // SECTION 5

}
