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
	
	} // SECTION 2

	// ADD A TEST FOR WHEN THERE IS ONLY ONE ITEM AND THE ITEM WE ARE ADDING HAS THE SAME TIME
	// ONE IS A TIMOUT EVENT AND THE OTHER IS A ARRIVAL EVENT. I
}
