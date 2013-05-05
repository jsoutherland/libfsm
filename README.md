libfsm
======

Finite State Machine Library

May-5-2013:  Today I have switched to C++11.  
Supporting member functions as callbacks using std::bind and std::function was too enticing. 
This does mean that user programs will have to switch from using function callbacks  "&func"  to 
a std::function "std::bind(&func)".
