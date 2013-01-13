/** UserFunction.h
 *
 * Joshua Southerland
 *
 * December 04, 2012
 *
 * All Rights Reserved
 */

#ifndef USERFUNCTION_H_
#define USERFUNCTION_H_

template <class T>
class UserFunction {
private:

	typedef void (*funcPtr)();
	funcPtr _fPtr;

	typedef void (T::*mFuncPtr)(void);
	T _obj;
	mFuncPtr _mFuncPtr;

	enum FunctionType {NONMEMBER = 0, MEMBER};
	FunctionType _ft;

public:

	UserFunction() :
		_obj(0), _mFuncPtr(0), _fPtr(0), _ft(0) {};

	virtual ~UserFunction() {};

	void setFunc(mFuncPtr mPtr, T obj){
		_mFuncPtr = mPtr;
		_obj = obj;
		_ft = MEMBER;
	}

	void setFunc(funcPtr fPtr){
		_fPtr = fPtr;
		_ft = NONMEMBER;
	}

	void call(){
		switch(_ft){
		case MEMBER:
			if (_obj != NULL && _mFuncPtr != NULL){
				(_obj->*_mFuncPtr)();
			}
			break;
		case NONMEMBER:
			if (_fPtr != NULL){
				_fPtr();
			}
			break;
		}
	}

};

#endif /* USERFUNCTION_H_ */
