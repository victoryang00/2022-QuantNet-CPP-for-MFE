#include "ExHandle.h"
// counstructor and destructor
OutOfBoundsException::OutOfBoundsException(int index)
    : ArrayException(), index(index) {} // default constructor with one parameter(using colon syntax)
OutOfBoundsException::~OutOfBoundsException() {} // destructor

// message
std::string OutOfBoundsException::GetMessage() {
    std::stringstream source;
    source << "Index " << index << " is out of bound!";
    return source.str();
}