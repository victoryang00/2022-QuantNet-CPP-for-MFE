//Point.cpp
//Simple two-dimentional point with x and y coordinates
//10-07-2016 AM
#ifndef POINT_H
#define POINT_H
#include "Point.h"
#endif
#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#ifndef CMATH
#define CMATH
#include <cmath>
#endif
namespace Cluster
{
namespace CAD
{
//Constructors and Dectructors (using colon sytax; without text printed on screen)
Point::Point():Shape(),x(0),y(0){}//default constructor
Point::Point(double newx, double newy):Shape(),x(newx),y(newy){}//constructor with initial value of coordinates
Point::Point(double coordinate):Shape(),x(coordinate),y(coordinate){}//constructor with single parameter
Point::Point(const Point& P):Shape(P),x(P.x),y(P.y){}//copy constructor
Point::~Point(){}//destructor

//Selectors
double Point::X() const//Access x value
{
	return x;
}
double Point::Y() const//Access y value
{
	return y;
}

//Modifiers
void Point::X(double newxval)//Initiate m_x
{
	x=newxval;
}
void Point::Y(double newyval)//Initiate m_y
{
	y=newyval;
}

//Description
std::string Point::ToString() const
{
	std::stringstream m_string;
	std::string s=Shape::ToString();
	m_string<<s<<"Point("<<x<<","<<y<<")";
	return m_string.str();
}

//Distance functions
double Point::Distance() const
{
	return sqrt(x*x+y*y);//Distance to Origin=SquareRoot(x^2+y^2)
}
double Point::Distance(Point &p)//Call by reference
{
	double a,b;
	a=x-p.x;//Calculate the difference in x coordinates
	b=y-p.y;//Calculate the difference in y coordinates
	return sqrt(a*a+b*b);
}

//Operators
Point Point::operator - () const// Negate the coordinates
{
	return Point(-x,-y);
}
Point Point::operator * (double factor) const // Scale the coordinates
{
	return Point(factor*x,factor*y);
}
Point Point::operator + (const Point& p) const // Add coordinates
{
	return Point(x+p.x,y+p.y);
}
bool Point::operator == (const Point& p) const // Equally compare operator
{
	return (x==p.x&&y==p.y);
}
Point& Point::operator = (const Point& source) // Assignment operator
{
	if (&source!=this)//handle self-assignment
	{
		Shape::operator=(source);//call class Shape assignment operator
		x=source.x; y=source.y;//assign parameters
	}
	return *this;
}
Point& Point::operator *= (double factor) // Scale the coordinates & assign
{
	factor*=x; factor*=y;//scale the coordinates
	return *this;
}
ostream& operator << (ostream& os, const Point& p)//The friend function of operator <<
{
	os<<"Point("<<p.x<<","<<p.y<<")";//Put string in to ostream object
	return os;
}
//operations
void Point::Draw()
{
	std::cout<<"."<<std::endl;
}
}
}