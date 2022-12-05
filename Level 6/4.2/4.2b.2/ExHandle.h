#include <iostream>
#include <sstream>
#ifndef CLASS_ARRAYEXCEPTION
#define CLASS_ARRAYEXCEPTION
class ArrayException {
public:
    // constructor and destructor
    ArrayException();
    ~ArrayException();

    // message
    virtual std::string GetMessage() = 0; // abstract GetMessage() function
};
#endif
#ifndef CLASS_OUTOFBOUNDS
#define CLASS_OUTOFBOUNDS
class OutOfBoundsException : public ArrayException // a derived class of ArrayException
{
private:
    int index;

public:
    // constructor and destructor
    OutOfBoundsException(int index); // constructor with an int argument
    ~OutOfBoundsException();

    // message
    std::string GetMessage(); // overriden GetMessage() funciton
};
#endif
#ifndef CLASS_NAEXCEPTION
#define CLASS_NAEXCEPTION
class NAException : public ArrayException // a class specially derived for NumericArray
{
public:
    // constructor and destructor
    NAException(); // default constructor
    ~NAException(); // destructor

    // message
    std::string GetMessage(); // overriden GetMessage() function
};
#endif