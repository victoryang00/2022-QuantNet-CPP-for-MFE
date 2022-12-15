// OptionElements.h
//
// This file contains the batches, struct and global function declarations required in the prompt
//
// Namespaces are used to contain batches for programming convenience
//
// 11-07-2016 PM

#ifndef OPTIONELE_H
#define OPTIONELE_H
#include <boost/math/distributions/normal.hpp>
#include <cmath>
#include <iostream>
#include <vector>

// namespaces and structs
namespace Batch1 {
auto T = 0.25;
auto K = 65.0;
auto sig = 0.30;
auto r = 0.08;
auto S = 60.0;
}; // namespace Batch1
namespace Batch2 {
auto T = 1.0;
auto K = 100.0;
auto sig = 0.2;
auto r = 0.0;
auto S = 100.0;
}; // namespace Batch2
namespace Batch3 {
auto T = 1.0;
auto K = 10.0;
auto sig = 0.50;
auto r = 0.12;
auto S = 5.0;
}; // namespace Batch3
namespace Batch4 {
auto T = 30.0;
auto K = 100.0;
auto sig = 0.30;
auto r = 0.08;
auto S = 100.0;
}; // namespace Batch4

struct OptionData {
    double K; // strike price
    double T; // time to maturity
    double r; // risk-free interest rate
    double sig; // stock price volatility
};

// global functions declarations option-pricing Call-option price
double BSCallPrice(const OptionData &OptD, const double &S); // with struct as input
// Put-option price
double BSPutPrice(const OptionData &OptD, const double &S); // with struct as input
double PCParity(const OptionData &OptD, const double &S, const double &price, const char &type); // with struct as input

// container modifying
std::vector<double> CutVec(const double &start, const double &h,
                           const double &size); // produces a mesh array of doubles separated by a mesh size h

#endif