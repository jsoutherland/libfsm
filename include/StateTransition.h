/** StateTransition.h
 *
 * Joshua Southerland
 *
 * November 29, 2012
 *
 * All Rights Reserved
 */

#ifndef STATETRANSITION_H_
#define STATETRANSITION_H_

#include <list>

// TODO: namespace

typedef bool (*transitionCriterion)();

class State;


class StateTransition
{

protected:
	transitionCriterion _criterion; //TODO: list (criterion)
	State *_nextState;
	unsigned long int _timesTaken;

public:
	StateTransition(transitionCriterion criterion, State *nextState);
	virtual ~StateTransition();
	State* evaluate() const;
	virtual State *getNextState() const;
	unsigned long int getTimesTaken() const;
	void increaseTimesTaken();
};

#endif /* STATETRANSITION_H_ */
