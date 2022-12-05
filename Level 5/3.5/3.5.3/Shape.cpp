//Shape.cpp
//Base class for point, line and circle
//10-07-2016 AM
#ifndef SHAPE_H
#define SHAPE_H
#include "Shape.h"
#endif
namespace Cluster
{
namespace CAD
{
//constructors and destructor
Shape::Shape():id(rand()){}//default constructor
Shape::Shape(const Shape& S):id(S.id){}//copy constructor
Shape::~Shape(){std::cout<<"Shape destructor called."<<std::endl;}//destructor

//Description
std::string Shape::ToString() const//get the description of id
{
	std::stringstream source;
	source<<"ID:"<<id;
	return source.str();
}

//Getter
int Shape::ID() const//get the id
{
	return id;
}

//operators
Shape& Shape::operator = (const Shape& source)//Assignment operator
{
	if (&source!=this)//prevent self-assignment
	{
		id=source.id;//assign id
	}
	return *this;
}
}
}