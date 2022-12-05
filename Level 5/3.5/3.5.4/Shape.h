//Shape.h
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#ifndef STDLIB
#define STDLIB
#include <stdlib.h>
#endif
#ifndef SSTREAM
#define SSTREAM
#include <sstream>
#endif
#ifndef CLASS_SHAPE
#define CLASS_SHAPE
namespace Cluster
{
namespace CAD
{
class Shape
{
private:
	int id;
public:
	//constructors and destructor
	Shape();//default constructor
	Shape(const Shape& S);//copy constructor
	virtual ~Shape();//destructor

	//Description
	virtual std::string ToString() const;//get the description of id

	//Getter
	int ID() const;//get the id

	//operators
	Shape& operator = (const Shape& source);//Assignment operator

	//operations
	virtual void Draw()=0;
};
}
}
#endif