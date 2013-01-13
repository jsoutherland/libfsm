/** StateMachine.h
 *
 * Joshua Southerland
 *
 * November 29, 2012
 *
 * All Rights Reserved
 */

#ifndef STATEMACHINE_H_
#define STATEMACHINE_H_

#define DOT_SUPPORT
#define EVINCE_SUPPORT

#include <list>
#include <string>

class State;

// TODO: namespace

class StateMachine
{

protected:
	State *_currentState;
	unsigned long int _numSteps;
	std::list<State*> _states;

public:
	StateMachine();
	virtual ~StateMachine();
	void step();
	void addState(State *state);
	void setState(State *state);
	std::string report() const;

	void writeDotFile() const;
	void viewDotFile() const;
};

#endif /* STATEMACHINE_H_ */
