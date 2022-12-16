//	EUoption.cpp
//
//	A class for European option consisting of pricing and sensitivity functions
//
//11-08-2016 PM

#include "EUoption.h"
using namespace boost::math;

//	constructors and destructor
EUoption::EUoption():K(0),T(0),r(0),sig(0),type('C'),b(0){}		//	default constructor
EUoption::EUoption(double& K1,double& T1, double& r1, double& sig1, char& type1):K(K1),T(T1),r(r1),sig(sig1),type(type1),b(r1){}	//	constructor with parameters
EUoption::EUoption(const EUoption& source):K(source.K),T(source.T),r(source.r),sig(source.sig),type(source.type),b(source.b){}	//	copy constructor
EUoption::~EUoption(){}											//	destructor

//	price function
double EUoption::Price(const double& S)				//	calculate option price
{
	//	declare parameters
	double price,d1,d2;					// price, parameter d1, parameter d2,cost of carry
	normal_distribution<> N(0.0,1.0);	// standard normal distribution
	
	//	calculate parameters
	d1=(log(S/K)+(b+(sig*sig/2))*T)/(sig*sqrt(T));
	d2=d1-sig*sqrt(T);

	//	calculate price according to different type
	if (type==67)	// call price
	{
		price=S*exp((b-r)*T)*cdf(N,d1)-K*exp(-r*T)*cdf(N,d2);
	}
	else            // put price
	{
		price=K*exp(-r*T)*cdf(N,-d2)-S*exp((b-r)*T)*cdf(N,-d1);
	}
	return price;
}

//	modifiers
void EUoption::ModelParameter(const double& para)	//	modify b for different model
{
	b=para;
}
void EUoption::Type(const char& Type)				//	modify type
{
	type=Type;
}

//	getters
double EUoption::ModelParameter()	//	see model used
{
	return b;
}
char EUoption::Type()				//	see type
{
	return type;
}

//	sensitivities
double EUoption::Delta(const double& S)			//	delta
{
	//	necessary parameters
	double delprice;
	normal_distribution<> N(0.0,1.0);
	
	//	calculate parameter
	double d1=(log(S/K)+(b+(sig*sig/2))*T)/(sig*sqrt(T));

	//	calculate delta price according to different type
	if (type==67)	//	call delta
	{
		delprice=exp((b-r)*T)*cdf(N,d1);
	}
	else            //	put delta
	{
		delprice=-exp((b-r)*T)*cdf(N,-d1);
	}
	return delprice;
}
double EUoption::Gamma(const double& S)			//	gamma
{
	//	necessary parameters
	double gammaprice;
	normal_distribution<> N(0.0,1.0);
	
	//	calculate parameters
	double d1=(log(S/K)+(b+(sig*sig/2))*T)/(sig*sqrt(T));
	gammaprice=(pdf(N,d1)*exp((b-r)*T))/(S*sig*sqrt(T));

	return gammaprice;
}
double EUoption::ApprxDelta(const double& S, const double& h)		//	approximate delta
{
	return (Price(S+h)-Price(S-h))/(2*h);
}
double EUoption::ApprxGamma(const double& S, const double& h)		//	approximate gamma
{
	return (Price(S+h)-2*Price(S)+Price(S-h))/(h*h);
}

//	operator
EUoption& EUoption::operator = (const EUoption& source)				//	assignment operator
{
	if (&source!=this)	//	handle self-assignment
	{
		//	assign corresponding parameters
		b=source.b;
		type=source.type;
		K=source.K;
		T=source.T;
		r=source.r;
		sig=source.sig;
	}
	return *this;
}

//	friend
double ParityPrice(const double& S, EUoption& source)		//	calculate price according to put-call parity
{
	if (source.type==67)	//	original type=call
	{
		return (source.Price(S)+source.K*exp(-source.r*source.T)-S);	//	return parity pull price
	}
	else                    //	original type=put
	{
		return (source.Price(S)+S-source.K*exp(-source.r*source.T));	//	return parity call price
	}
}