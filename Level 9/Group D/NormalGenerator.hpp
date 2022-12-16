// NormalGenerator.hpp
//
// A class hierarchy for generating random numbers, 
// vectors and matrices.
// 
// This hierarchy uses the Template Method Pattern and it
// delegates to a Strategy pattern for generating uniform
// random numbers.
//
// The solution is object-oriented and uses run-time polymorphic
// functions. In another chapter we use policy classes and templates.
//
// 2012-17 DD restrict to Boost
//
// (C) Datasim Education BV 2008-2012
//

#ifndef AAD611BD_143E_49CC_A7C4_C6897A6F5A32
#define AAD611BD_143E_49CC_A7C4_C6897A6F5A32

#ifndef B310CC4F_DFDE_4BD0_853C_D4ECB83AF5DC
#define B310CC4F_DFDE_4BD0_853C_D4ECB83AF5DC

#ifndef NormalGenerator_HPP
#define NormalGenerator_HPP

// boost
#include <boost/random.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/variate_generator.hpp>

class NormalGenerator
{

public:

	// Empty at the moment
	virtual double getNormal() const = 0;
};


class BoostNormal : public NormalGenerator
{
private:

	boost::lagged_fibonacci607 rng;
	boost::normal_distribution<> nor;
//
	boost::variate_generator<boost::lagged_fibonacci607&, boost::normal_distribution<> >* myRandom;


public:
	BoostNormal();	// NB no uniform parameters

	// Implement (variant) hook function
	double getNormal() const;

	~BoostNormal();
};


#endif


#endif /* B310CC4F_DFDE_4BD0_853C_D4ECB83AF5DC */


#endif /* AAD611BD_143E_49CC_A7C4_C6897A6F5A32 */
