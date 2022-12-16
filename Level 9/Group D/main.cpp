// HardCoded.cpp
//
// C++ code to price an option, essential algorithms.
//
// We take CEV model with a choice of the elaticity parameter
// and the Euler method. We give option price and number of times
// S hits the origin.
//
// (C) Datasim Education BC 2008-2011
//

#include "OptionData.hpp" 
#include "NormalGenerator.hpp"
#include "Range.cpp"
#include "ArrayMechanisms.cpp"
#include <cmath>
#include <iostream>

template <class T> void print(const std::vector<T>& myList)
{  // A generic print function for vectors
	
	std::cout << std::endl << "Size of vector is " << myList.size() << "\n[";

	// We must use a const iterator here, otherwise we get a compiler error.
	for (auto i = myList.begin(); i != myList.end(); ++i)
	{
			std::cout << *i << ",";

	}

	std::cout << "]\n";
}

namespace SDEDefinition
{ // Defines drift + diffusion + data

	OptionData* data;				// The data for the option MC

	double drift(double t, double X)
	{ // Drift term
	
		return (data->r)*X; // r - D
	}

	
	double diffusion(double t, double X)
	{ // Diffusion term
	
		double betaCEV = 1.0;
		return data->sig * pow(X, betaCEV);
		
	}

	double diffusionDerivative(double t, double X)
	{ // Diffusion term, needed for the Milstein method
	
		double betaCEV = 1.0;
		return 0.5 * (data->sig) * (betaCEV) * pow(X, 2.0 * betaCEV - 1.0);
	}
} // End of namespace

namespace Batch1
{double T = 0.25; double K = 65; double sig = 0.30; double r = 0.08; double S = 60;};
namespace Batch2
{double T = 1.0; double K = 100; double sig = 0.2; double r = 0.0; double S = 100;};
namespace Batch4
{double T = 30.0; double K = 100.0; double sig = 0.30; double r = 0.08; double S = 100.0;};

//

template<typename T1, typename T2, typename T3>
double StDev(T1 M,T2 r, T3 T)
{
	double SumCsqare=0; double SumC=0; double S=M.size();

	for (auto i=M.begin();i!=M.end();++i)
	{
		SumCsqare+=(*i)*(*i);
		SumC+=(*i);
	}

	double para1=sqrt(SumCsqare-((SumC*SumC)/S));
	double para2=para1*exp(-2*r*T);
	return (para2/sqrt(S-1));
}

template<typename T1, typename T2, typename T3>
double StErr(T1 M,T2 r, T3 T)
{
	double sqrS=sqrt(M.size());
	return (StDev(M,r,T)/sqrS);
}
int main()
{
	//	using namespace Batch1;	//result: call:2,13337, put: 5.84628
	//	using namespace Batch2; //result: call:7.96557, put:7.96557
		using namespace Batch4; //result: call:92.1757, put:1.2475

	std::cout <<  "1 factor MC with explicit Euler\n";
	OptionData myOption;
	myOption.K = K;
	myOption.T = T;
	myOption.r = r;
	myOption.sig = sig;
	myOption.type = -1;	// Put -1, Call +1
	double S_0 = S;
	
	long N = 100;
	std::cout << "Number of subintervals in time: ";
	std::cin >> N;

	// Create the basic SDE (Context class)
	Range<double> range (0.0, myOption.T);
	double VOld = S_0;
	double VNew;

	Vector<double, long> x = range.mesh(N);
	

	// V2 mediator stuff
	long NSim = 50000;
	std::cout << "Number of simulations: ";
	std::cin >> NSim;

	double k = myOption.T / double (N);
	double sqrk = sqrt(k);

	// Normal random number
	double dW;
	double price = 0.0;	// Option price

	// NormalGenerator is a base class
	NormalGenerator* myNormal = new BoostNormal();

	using namespace SDEDefinition;
	data = &myOption;

	Vector<double> res;
	int coun = 0; // Number of times S hits origin

	std::vector<double> result;
	result.reserve(NSim);

	// A.
	for (long i = 1; i <= NSim; ++i)
	{ // Calculate a path at each iteration
			
		if ((i/10000) * 10000 == i)
		{// Give status after each 1000th iteration

				std::cout << i << std::endl;
		}

		VOld = S_0;
		for (long index = x.MinIndex()+1; index <= x.MaxIndex(); ++index)
		{

			// Create a random number
			dW = myNormal->getNormal();
				
			// The FDM (in this case explicit Euler)
			VNew = VOld  + (k * drift(x[index-1], VOld))
						+ (sqrk * diffusion(x[index-1], VOld) * dW);

			VOld = VNew;

			// Spurious values
			if (VNew <= 0.0) coun++;
		}
			
		

		double tmp = myOption.myPayOffFunction(VNew);
		result.push_back(tmp);
		price += (tmp)/double(NSim);
	}
	
	// D. Finally, discounting the average price
	price *= exp(-myOption.r * myOption.T);
	double STDEV=StDev(result,myOption.r,myOption.T);
	double STERR=StErr(result,myOption.r,myOption.T);

	// Cleanup; V2 use scoped pointer
	delete myNormal;

	std::cout << "Price, after discounting: " << price << ", " << std::endl;
	std::cout<<"Standard deviation: "<<STDEV<<std::endl;
	std::cout<<"Standard Error: "<<STERR<<std::endl;
	std::cout << "Number of times origin is hit: " << coun << endl;
	
	return 0;
}