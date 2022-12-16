//	PerpAmeOption.h
#include <cmath>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

#ifndef PERPAMEOPTION_H
#define PERPAMEOPTION_H

class PerpAmeOption {
private:
    char type; //	'C'-call/'P'-put

    //	put Call price and Put price in seperated function as required
    double CallPrice(const double &S);
    double PutPrice(const double &S);

public:
    //	public data members
    double r; // risk-free interest rate
    double sig; // volatility
    double S; // asset price
    double K; // strike price
    double b; // cost of carry
    double price; // option price
    std::vector<std::vector<double>> parameter_matrix; // parameter matrix

    std::vector<double> price_vector; // calculated option price
    //	constructors and destructor
    PerpAmeOption(); //	default constructor
    PerpAmeOption(double &b1, double &K1, double &r1, double &sig1, char &type1); //	constructor with parameters
    PerpAmeOption(double r, double sig, double K, double b, double S, char &type); //	constructor with parameters
    PerpAmeOption(const PerpAmeOption &source); //	copy constructor
    PerpAmeOption(std::vector<std::vector<double>> parameter_matrix, char &type); // construct by matrix
    virtual ~PerpAmeOption(); //	destructor
    //	price function
    double Price(const double &S);
    std::vector<double> PriceWithMatrix();
    //	modifiers
    void Type(const char &Type); //	modify type\
    //	getters
    char Type() const; //	see type
    // Modifier functions
    void toggle(); // Change option type (C/P, P/C)
    //	operator=
    PerpAmeOption &operator=(const PerpAmeOption &source); //	assignment operator
    // helper function: show option price result
    void ShowPriceResult();
    void ShowMatrixPriceResult();
};
#endif