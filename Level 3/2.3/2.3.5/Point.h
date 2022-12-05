
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
	Point();
	~Point(){};
	Point(const Point& P);
	Point(double x,double y);

	//Selectors
	double X() const;//Access x value
	double Y() const;//Access y value

	//Modifiers
	void X(double newxval);//Set x value
	void Y(double newyval);//Set y value
	
	//Description
	std::string ToString() const;

	//Distance  function
	double Distance() const;
	double Distance(Point &p) const;//Call by referece
};
#endif