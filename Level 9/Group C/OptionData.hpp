// OptionData.hpp
//
// Encapsulate option data.
//
// (C) Datasim Education BV 2008-2011

#ifndef AF41808F_4D28_41DB_AAAE_5910C26BC5AB
#define AF41808F_4D28_41DB_AAAE_5910C26BC5AB

#ifndef OptionData_HPP
#define OptionData_HPP

#include <algorithm> // for max()
using namespace std;

// Encapsulate all data in one place
struct OptionData
{ // Option data + behaviour

	double K;
	double T;
	double r;
	double sig;

	// Extra data 
	double H;		// down and out barrier
	double D;		// dividend
	double betaCEV;	// elasticity factor (CEV model)
	double scale;	// scale factor in CEV model

	int type;		// 1 == call, -1 == put

	double myPayOffFunction(double S)
	{ // Payoff function

		if (type == 1)
		{ // Call

			return max(S - K, 0.0);
		}
		else
		{ // Put
		
			return max (K - S, 0.0);
		}
	}
};


#endif


#endif /* AF41808F_4D28_41DB_AAAE_5910C26BC5AB */
