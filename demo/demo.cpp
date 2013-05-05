/** State Machine Demo
 *
 * Joshua Southerland
 *
 * November 29, 2012
 *
 * All Rights Reserved
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <functional>

#include "StateMachine.h"
#include "State.h"
#include "StateTransition.h"


/** User Functions
 *
 */
void aFunc(){ std::cout << "A" << std::endl; }
void bFunc(){ std::cout << "B" << std::endl; }
void cFunc(){ std::cout << "C" << std::endl; }



/** Transition Functions
 *
 */
bool neverTransition(){ return false; }
bool alwaysTransition(){ return true; }
bool randomTransition(){ return  (rand() % 100)  < 50; }



/** Main
 *
 */
int main(int argc, char** argv)
{
	using std::bind;

	// greeting
	std::cout << std::endl;
	std::cout << "State Machine Demo - Joshua Southerland" << std::endl << std::endl;


	// seed the random generator for randomTransition()
	srand((unsigned)time(0));


	// initialize the states
	State stateA("A");
	State stateB("B");
	State stateC("C");


	// state A always transitions to state B
	// You could instead call  stateA.registerUserFunction(bind(&Class::function, object))
	// to use a member function.
	stateA.registerUserFunction(bind(&aFunc));
	stateA.addStateTransition(new StateTransition(&alwaysTransition, &stateB));


	// state B transitions randomly to state A or B, otherwise it continues in state B
	// note that the chance to end up in stateA is greater than stateC, since that state
	// transition is evaluated first
	stateB.registerUserFunction(bind(&bFunc));
	stateB.addStateTransition(new StateTransition(&randomTransition, &stateA));
	stateB.addStateTransition(new StateTransition(&randomTransition, &stateC));


	// state C has no transition so it will stay in state C
	stateC.registerUserFunction(bind(&cFunc));


	// initialize the state machine
	StateMachine sm;


	// add states to be tracked (optional)
	sm.addState(&stateA);
	sm.addState(&stateB);
	sm.addState(&stateC);


	// set the starting and current state
	sm.setState(&stateA);


	// run
	for (unsigned int i = 0; i < 20; i++){
		sm.step();
	}

	// generate a report
	std::cout << sm.report();


	// generate a report for dottie
	sm.writeDotFile();
	sm.viewDotFile();

	// done
	return 0;
}
