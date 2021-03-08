//---------------------------------------------------------------------
// NAME		: your name
// STUDENT NUMBER	: 7793306
// COURSE		: COMP 2150
// INSTRUCTOR	: Mike Domaratzki
// ASSIGNMENT	: assignment 2
// QUESTION	: question 1
//
// REMARKS: this program that uses a discrete-event simulation for the
// operation of a multiprogramming Operating System. The operating system
// will manages Processes, which enter the system, and require bursts of
// time – that is, the processes require certain resources (IO/CPU) for
// a particular length of time.
//
// Note: I took the descriptions from the assignment outline for the
// remarks. I hope that's okay :)
//--------------------------------------------------------------------

#include "Simulation.h"
#include <iostream>
using namespace std;

int main(int argc, char *argv[]){
	if(argc < 2){
		cout << "Usage: " << argv[0] << " <file name>" << endl;
	} else {
		cout << "Simulation begins...\n";
		Simulation* sim = new Simulation();
		sim->runSimulation(argv[1]);
		cout << "\n...All Processes complete.  Final Summary:\n\n";

		cout << "\nEnd of processing.\n";
		return 0;
	}
}// main
