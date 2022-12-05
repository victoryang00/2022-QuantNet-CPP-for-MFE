#include "Ltv.h"
// constructor and destructor
Ltv::Ltv() : value(1.5) {} // default constructor
Ltv::Ltv(double v) : value(v) {} // constructor with value parameter
Ltv::Ltv(const Ltv &f) : value(f.value) {} // copy constructor
Ltv::~Ltv() {} // destructor

// operators
Ltv &Ltv::operator=(const Ltv &f) // assignment operator
{
    if (this != &f) { // check whether itself
        value = f.value;
    }
    return *this;
}
bool Ltv::operator()(double num) // overloaded operator ()
{
    return num < value;
}

// Setter
void Ltv::Benchmark(double b) // get private data into passed value
{
    value = b;
}

// Getter
double Ltv::GetV() // get private member value
{
    return value;
}