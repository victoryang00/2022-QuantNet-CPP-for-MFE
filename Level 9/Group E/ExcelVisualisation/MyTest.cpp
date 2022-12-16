//	MyTest.cpp
//
//	Print option price for monotonically increasing stock price in excel
//
//	Using the data from batches
//
//	11-10-2016 AM

#include "EUoption.h"

#include "UtilitiesDJD/VectorsAndMatrices/Vector.cpp"
#include "UtilitiesDJD/ExcelDriver/ExcelMechanisms.hpp"
#include "UtilitiesDJD/Geometry/Range.cpp"
#include "UtilitiesDJD/ExceptionClasses/DatasimException.hpp"

#include <string>
#include <vector>

using namespace std;							//	For readability
using namespace boost::math;					//	For readability

namespace Batch1
{double T = 0.25; double K = 65; double sig = 0.30; double r = 0.08; double S = 60;};
namespace Batch2
{double T = 1.0; double K = 100; double sig = 0.2; double r = 0.0; double S = 100;};
namespace Batch3
{double T = 1.0; double K = 10; double sig = 0.50; double r = 0.12; double S = 5;};
namespace Batch4
{double T = 30.0; double K = 100.0; double sig = 0.30; double r = 0.08; double S = 100.0;};

//	container modifying
vector<double> CutVec(const double& start, const double& h, const int& size);									//	produces a mesh array of doubles separated by a mesh size h

int main()
{
	//	import parameters
	//	using namespace Batch1;	//result: call:2,13337, put: 5.84628
	//	using namespace Batch2; //result: call:7.96557, put:7.96557
	//	using namespace Batch3; //result: call:0.204058, put:4.07326
		using namespace Batch4; //result: call:92.1757, put:1.2475
	char type1='C'; char type2='P';

	EUoption EUcall(K,T,r,sig,type1);
	EUoption EUput(K,T,r,sig,type2);

	Vector<double,long> StockP(50,0);		

	//	containers of results
	Vector<double,long> Output1(50,0);
	Vector<double,long> Output2(50,0);

	for (int i=0;i!=50;i++)		//	initialize Stock Price
	{
		StockP[i]=i+10;
	}

	//	calculate option price for different stock prices (other parameters in batches remain the same as before)
	cout<<"Calculating data..."<<endl;
	for (int i=0;i!=50;i++)
	{
		Output1[i]=(EUcall.Price(StockP[i]));		//	calculate call price
		Output2[i]=(EUput.Price(StockP[i]));		//	calculate put price
	}
	cout<<endl;

	cout<<"Starting Excel..."<<endl;
	try 
	{
		printPairExcel(StockP,Output1, Output2, 
						string("Put and Call Price"), string("Stock Price"), string("Option Price"));
	}
	catch(DatasimException& e)
	{
		e.print();
	}
	cout<<"Finished."<<endl;
}

//	produces a mesh array of doubles separated by a mesh size h
vector<double> CutVec(const double& start, const double& h, const int& size)
{
	vector<double> Proto;				//	declare the vector to be returned
	Proto.reserve(size);				//	reserve places for elements
	for (int i=0;i!=size;i++)			//	initialize elements according to requirement
	{
		Proto.push_back(start+h*i);
	}
	return Proto;
}