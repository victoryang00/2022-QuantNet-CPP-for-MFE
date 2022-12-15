#include <cmath>
#include <iostream>
#include <vector>

#include <boost/math/distributions/normal.hpp>

#ifndef EUOPTION_H
#define EUOPTION_H

class EUoption {
private:
    double b; //	varies according to different models
    char type; //	'C'-call/'P'-put
    std::vector<std::vector<double>> parameter_matrix; // Parameter Matrix for better inputing
    std::vector<double> delta_vector;
    std::vector<double> gamma_vector;
    std::vector<double> price_vector;

public:
    //	public data members
    double K; //	strike price
    double T; //	time to maturity
    double r; //	risk-free interest rate
    double sig; //	stock price volatility

    //	constructors and destructor
    EUoption(); //	default constructor
    EUoption(double &K1, double &T1, double &r1, double &sig1, char &type1); //	constructor with parameters
    EUoption(const std::vector<std::vector<double>> parameter_matrix, char &opt_type); // construct by matrix
    EUoption(const EUoption &source); //	copy constructor
    virtual ~EUoption(); //	destructor

    //	price function
    double Price(const double &S); //	calculate option price

    //	modifiers
    void ModelParameter(const double &para); //	modify b for different model
    void Type(const char &Type); //	modify type

    //	getters
    double ModelParameter(); //	see model used
    char Type(); //	see type

    //	sensitivities
    double Delta(const double &S); //	delta
    double Gamma(const double &S); //	gamma
    double ApprxDelta(const double &S, const double &h); //	approximate delta
    double ApprxGamma(const double &S, const double &h); //	approximate gamma

    //	operator
    EUoption &operator=(const EUoption &source); //	assignment operator

    //	friend
    friend double ParityPrice(const double &S, EUoption &source); //	calculate price according to put-call parity
    void showMatrixPriceResult();
};

#endif