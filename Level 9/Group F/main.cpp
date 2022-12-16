// TestBSPDE1.cpp
//
// Testing 1 factor BS model.
//
// (C) Datasim Education BV 2005-2011
//

#include "FDMDirector.hpp"

#include <string>
#include <iostream>
#include <cmath>
using namespace std;

#include "UtilitiesDJD/ExcelDriver/ExcelMechanisms.cpp"

namespace BS // Black Scholes
{
double sig = 0.3;
double K = 100.0;
double T = 30.0;
double r = 0.08;
double D = 0.0; // aka q

double mySigma(double x, double t) {

    double sigmaS = sig * sig;

    return 0.5 * sigmaS * x * x;
}

double myMu(double x, double t) { return (r - D) * x; }

double myB(double x, double t) { return -r; }

double myF(double x, double t) { return 0.0; }

double myBCL(double t) {
    // Put
    return K * exp(-r * t);
}

double myBCR(double t) {

    // Put
    return 0.0; // P
}

double myIC(double x) { // Payoff

    // Put
    return max(K - x, 0.0);
}

} // namespace BS

int main() {
    using namespace ParabolicIBVP;

    // Assignment of functions
    sigma = BS::mySigma;
    mu = BS::myMu;
    b = BS::myB;
    f = BS::myF;
    BCL = BS::myBCL;
    BCR = BS::myBCR;
    IC = BS::myIC;

    int J = 5 * BS::K;
    int N = 1000000; // k = O(h^2) !!!!!!!!!

    double Smax = 5 * BS::K; // Magix

    cout << "start FDM\n";
    FDMDirector fdir(Smax, BS::T, J, N);

    fdir.doit();

    cout << "Finished\n";

    // Have you Excel installed (ExcelImports.cpp)
    printOneExcel(fdir.xarr, fdir.current(), string("Value"));

    return 0;
}
