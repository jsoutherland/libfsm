/** State.h
 *
 * Joshua Southerland
 *
 * November 29, 2012
 *
 * All Rights Reserved
 */

#ifndef STATE_H_
#define STATE_H_

#include <list>
#include <string>

// TODO: namespace

class StateTransition; // forward declaration

typedef void (*userFunction)();


class State
{

protected:
	userFunction _userFunc;
	std::list<StateTransition*> _transitions; //TODO: priority queue
	std::string _id;
	unsigned long int _numSteps;

public:
	State(std::string id);
	State(std::string id, userFunction uFunc, StateTransition *transition);
	virtual ~State();
	State* operate();
	void registerUserFunction(userFunction uFunc);
	void addStateTransition(StateTransition *transition);
	std::string getID() const;
	unsigned long int getNumSteps() const;
	std::string report() const;
	std::string reportDot() const;
};

#endif /* STATE_H_ */
