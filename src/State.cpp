/** State.cpp
 *
 * Joshua Southerland
 *
 * November 29, 2012
 *
 * All Rights Reserved
 */

#include <iostream>
#include <sstream>

#include "State.h"
#include "StateTransition.h"


State::State(std::string id) :
_numSteps(0),
_id(id)
{
}

State::State(std::string id, userFunction uFunc, StateTransition *transition) :
_numSteps(0),
_id(id)
{
	registerUserFunction(uFunc);
	addStateTransition(transition);
}

State::~State()
{
}


State* State::operate()
{

	_numSteps += 1;

	// call user function
	_userFunc();

	// check for state transition
	std::list<StateTransition*>::iterator it;

	StateTransition  *st;
	State *nextState;

	for (it = _transitions.begin(); it != _transitions.end(); it++){
		st = *it;

		nextState = st->evaluate();

		if (nextState != NULL){
			st->increaseTimesTaken();
			return nextState;
		}

	}

	return this;
}


void State::registerUserFunction(userFunction uFunc)
{
	_userFunc = uFunc;
}


void State::addStateTransition(StateTransition *transition)
{
	_transitions.push_back(transition);
}


std::string State::getID() const
{
	return _id;
}


unsigned long int State::getNumSteps() const
{
	return _numSteps;
}

std::string State::report() const
{

	std::stringstream ss;

	ss << "###############################" << std::endl;
	ss << "State (" << _id << ") : " << std::endl;
	ss << "timesteps = " << _numSteps << std::endl;

	State *nextState;

	std::list<StateTransition*>::const_iterator it;

	StateTransition  *st;
	for (it = _transitions.begin(); it != _transitions.end(); it++){
		st = *it;
		nextState = st->getNextState();

		if (nextState != NULL){
			ss << "Transition count (" << nextState->getID()  << ") = " << st->getTimesTaken() << std::endl;
		}
	}

	ss << "###############################" << std::endl << std::endl;

	return ss.str();
}


std::string State::reportDot() const
{

	std::stringstream ss;

	State *nextState;

	std::list<StateTransition*>::const_iterator it;
	StateTransition  *st;

	for (it = _transitions.begin(); it != _transitions.end(); it++){
		st = *it;

		nextState = st->getNextState();

		if (nextState != NULL){
			ss << "\"" <<_id << " : " << _numSteps  << "\""
				<< " -> \""
				<< nextState->getID() << " : " << nextState->getNumSteps() << "\""
				<< " [style=bold,label=\"" << st->getTimesTaken() << "\"];" << std::endl;
		}
	}

	return ss.str();
}
