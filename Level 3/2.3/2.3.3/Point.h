#include <sstream>
#ifndef CLASS_POINT
#define CLASS_POINT
class Point
{
private:
	double m_x;
	double m_y;
public:
	//Constructor and Destructor
	Point(){};
	~Point(){};
	Point(const Point &P){};
	Point(double x,double y);

	//Selectors
	double X();//Access x value
	double Y();//Access y value

	//Modifiers
	void X(double newxval);//Set x value
	void Y(double newyval);//Set y value
	
	//Description
	std::string ToString();

	//Distance  function
	double Distance();
	double Distance(Point &p);//Call by referece
};
#endif