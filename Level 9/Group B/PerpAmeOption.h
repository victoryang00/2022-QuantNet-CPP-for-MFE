//	PerpAmeOption.h

#ifndef PERPAMEOPTION_H
#define PERPAMEOPTION_H
#ifndef CMATH
#define CMATH
#include <cmath>
#endif
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif

class PerpAmeOption
{
private:
	char type;		//	'C'-call/'P'-put

	//	put Call price and Put price in seperated function as required
	double CallPrice(const double& S);
	double PutPrice(const double& S);
public:
	//	public data members
	double b;		//	cost of carry
	double K;		//	strike price
	double r;		//	risk-free interest rate
	double sig;		//	stock price volatility

	//	constructors and destructor
	PerpAmeOption();									//	default constructor
	PerpAmeOption(double& b1, double& K1, double& r1, double& sig1, char& type1);		//	constructor with parameters
	PerpAmeOption(const PerpAmeOption& source);			//	copy constructor
	virtual ~PerpAmeOption();							//	destructor

	//	price function
	double Price(const double& S);

	//	modifiers
	void Type(const char& Type);	//	modify type

	//	getters
	char Type();					//	see type

	//	operator
	PerpAmeOption& operator = (const PerpAmeOption& source);	//	assignment operator
};
#endif