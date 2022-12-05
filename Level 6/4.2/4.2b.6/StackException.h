#include <iostream>
#include <sstream>
#ifndef CLASS_STACKEXCEPTION
#define CLASS_STACKEXCEPTION
class StackException {
public:
    // constructor and destructor
    StackException(); // default constroctor
    ~StackException(); // destrucotor
};
#endif
#ifndef CLASS_STACKFULLEXCEPTION
#define CLASS_STACKFULLEXCEPTION
class StackFullException : public StackException {
public:
    // constructor and destructor
    StackFullException(); // default constructor
    ~StackFullException(); // destructor
};
#endif
#ifndef CLASS_STACKEMPEXCEPTION
#define CLASS_STACKEMPEXCEPTION
class StackEmpException : public StackException {
public:
    // constructor and destructor
    StackEmpException(); // default constructor
    ~StackEmpException(); // destructor
};
#endif