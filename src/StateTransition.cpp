/** StateTransition.cpp
 *
 * Joshua Southerland
 *
 * November 29, 2012
 *
 * All Rights Reserved
 */

#include "StateTransition.h"
#include "State.h"

StateTransition::StateTransition(transitionCriterion criterion, State *nextState) :
_timesTaken(0),
_criterion(criterion),
_nextState(nextState)
{
}

StateTransition::~StateTransition()
{
}


unsigned long int StateTransition::getTimesTaken() const
{
	return _timesTaken;
}

State* StateTransition::evaluate() const
{

	if (_criterion()) return _nextState;

	return NULL;
}

State* StateTransition::getNextState() const
{
	return _nextState;
}

void StateTransition::increaseTimesTaken()
{
	_timesTaken += 1;
}
