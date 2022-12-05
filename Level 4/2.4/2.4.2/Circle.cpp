//Circle.cpp
//Class Circle with centre and radius
//09-25-2016 PM
#ifndef CMATH
#define CMATH
#define _USE_MATH_DEFINES
#include <cmath>
#endif
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#ifndef CIRCLE_H
#define CIRCLE_H
#include "Circle.h"
#endif
//constructors and destructor
Circle::Circle(){}//default constructor
Circle::Circle(Point& p1, Line& l1)
{
	centre=p1;
	radius=l1;
}
Circle::Circle(const Circle& O)//copy constructor
{
	centre=O.centre;
	radius=O.radius;
}
Circle::~Circle(){}//destructor

//Selectors
Point Circle::CentrePoint() const
{
	return centre;
}
Line Circle::Radius() const
{
	return radius;
}

//Modifier
void Circle::CentrePoint(Point& p)
{
	centre=p;
}
void Circle::Radius(Line& l)
{
	radius=l;
}

//Geometric property functions
double Circle::Diameter()
{
	return (radius.Length()*2);
}
double Circle::Circumference()
{
	return (radius.Length()*2*M_PI);
}
double Circle::Area()
{
	return (radius.Length()*radius.Length()*M_PI);
}

//Description
std::string Circle::ToString()
{
	std::stringstream source;
	source<<"A circle centered at point("<<centre.X()<<","<<centre.Y()<<") with a radius of "<<radius.Length();
	return source.str();
}

//Operator
Circle& Circle::operator = (const Circle& O)
{
	centre=O.centre;
	radius=O.radius;
	return *this;
}