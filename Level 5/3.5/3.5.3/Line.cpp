//Line.cpp
//Simple line class with start- and end-point.
//10-07-2016 AM
#ifndef LINE_H
#define LINE_H
#include "Line.h"
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
//constructors and destructor (using colon sytax)
Line::Line():Shape(){}//default constructor
Line::Line(Point &p1, Point &p2):Shape(),stp(p1),endp(p2){}//constructor with start- and end-point
Line::Line(const Line& l):Shape(l),stp(l.stp),endp(l.endp){}//copy constructor
Line::~Line(){std::cout<<"Line destructor called."<<std::endl;}//destructor

//Selector
Point Line::Stp() const
{
	return stp;
}
Point Line::Endp() const
{
	return endp;
}

//Modifier
void Line::Stp(Point &nstp)
{
	stp=nstp;//initialize start point
}
void Line::Endp(Point &nendp)
{
	endp=nendp;//initialize end point
}

//Description
std::string Line::ToString() const
{
	std::stringstream source;
	std::string s=Shape::ToString();
	source<<s<<". A line between ("<<stp.X()<<","<<stp.Y()<<") and ("<<endp.X()<<","<<endp.Y()<<").";
	return source.str();
}

//Length
double Line::Length()
{
	return stp.Distance(endp);//length of the line is the distance between start- and end-point
}

//Operator
Line& Line::operator = (const Line& source)
{
	if (&source!=this)//handle self-assignment
	{
		Shape::operator=(source);//call class Shape assignment operator
		stp=source.stp;//assign parameters
		endp=source.endp;//assign parameters
	}
	return *this;
}

//friend function
ostream& operator << (ostream& os, const Line& l)
{
	os<<"A line between Point("<<l.stp.x<<","<<l.stp.y<<") and Point("<<l.endp.x<<","<<l.endp.y<<").";
	return os;
}
}
}