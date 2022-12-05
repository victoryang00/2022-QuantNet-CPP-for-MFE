#include <iostream>
#ifndef CLASS_Ltv
#define CLASS_Ltv
class Ltv {
private:
    double value;

public:
    // constructor and destructor
    Ltv(); // default constructor
    Ltv(double v); // constructor with value parameter
    Ltv(const Ltv &f); // copy constructor
    ~Ltv(); // destructor

    // operators
    Ltv &operator=(const Ltv &f); // assignment operator
    bool operator()(double num); // overloaded operator ()

    // Setter
    void Benchmark(double b); // set private data number value

    // Getter
    double GetV(); // get private member value
};
#endif