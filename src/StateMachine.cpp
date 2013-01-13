/** StateMachine.h
 *
 * Joshua Southerland
 *
 * November 29, 2012
 *
 * All Rights Reserved
 */


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <sstream>

#include "StateMachine.h"
#include "State.h"


StateMachine::StateMachine() :
_numSteps(0)
{
}

StateMachine::~StateMachine()
{
}


void StateMachine::step()
{
	_numSteps += 1;
	_currentState = _currentState->operate();
}


void StateMachine::addState(State *state)
{
	// TODO: error checking
	_states.push_back(state);
}


void StateMachine::setState(State *state)
{
	_currentState = state;
}

std::string StateMachine::report() const
{
	std::stringstream ss;

	ss << std::endl << std::endl;

	ss << "***** State Machine Report *****" << std::endl;

	ss << std::endl;
	ss << "Total timesteps: " << _numSteps << std::endl;
	ss << std::endl;

	std::list<State*>::const_iterator it;

	State *st;

	for (it = _states.begin(); it != _states.end(); it++){
		st = *it;
		ss << st->report();
	}

	ss << "*******************************" << std::endl <<  std::endl;

	return ss.str();
}

void StateMachine::writeDotFile() const
{

	std::ofstream dotFile;
	dotFile.open ("out.dot");

	dotFile << "digraph \"FSM : " << _numSteps << "\" {" << std::endl;
	std::list<State*>::const_iterator it;

	State *st;

	for (it = _states.begin(); it != _states.end(); it++){
		st = *it;
		dotFile << st->reportDot();
	}

	dotFile << "}" << std::endl;

	dotFile.close();
}



#if defined DOT_SUPPORT && defined EVINCE_SUPPORT

void StateMachine::viewDotFile() const
{
	system("dot -Tps out.dot -o out.ps && evince out.ps &");
}

#else

void StateMachine::viewDotFile() const
{
	std::cout << "Warning (StateMachine.cpp:"
			<< __LINE__
			<< ") : lacking dot and/or evince support, cannot display FSM graph."
			<< std::endl;
}

#endif
