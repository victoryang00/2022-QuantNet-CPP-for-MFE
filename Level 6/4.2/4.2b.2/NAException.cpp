#include "ExHandle.h"
// constructor and destructor
NAException::NAException() : ArrayException() {} // default constructor
NAException::~NAException() {} // destructor

// message
std::string NAException::GetMessage() // overriden GetMessage() function
{
    std::stringstream source;
    source << "Two arrays are of different size!";
    return source.str(); // return the string
}