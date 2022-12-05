#include "Point.h"
#include <cmath>
#include <iostream>
namespace Cluster {
namespace CAD {
// Constructors and Dectructors (using colon sytax)
Point::Point()
    : x(0), y(0) // default constructor
{
    cout << "Point default constructor called." << endl;
}
Point::Point(double newx, double newy)
    : x(newx), y(newy) // constructor with initial value of coordinates
{
    cout << "Point constructor with parameters called." << endl;
}
Point::Point(double coordinate) : x(coordinate), y(coordinate) {
    cout << "Point constructor with single parameter called." << endl;
}
Point::Point(const Point &P)
    : x(P.x), y(P.y) // copy constructor
{
    cout << "Point copy constructor called." << endl;
}
Point::~Point() { cout << "Point destructor called." << endl; } // destructor

// Selectors
double Point::X() const // Access x value
{
    return x;
}
double Point::Y() const // Access y value
{
    return y;
}

// Modifiers
void Point::X(double newxval) // Initiate m_x
{
    x = newxval;
}
void Point::Y(double newyval) // Initiate m_y
{
    y = newyval;
}

// Description
std::string Point::ToString() const {
    std::stringstream m_string;
    m_string << "Point(" << x << "," << y << ")";
    return m_string.str();
}

// Distance functions
double Point::Distance() const {
    return sqrt(x * x + y * y); // Distance to Origin=SquareRoot(x^2+y^2)
}
double Point::Distance(Point &p) // Call by reference
{
    double a, b;
    a = x - p.x; // Calculate the difference in x coordinates
    b = y - p.y; // Calculate the difference in y coordinates
    return sqrt(a * a + b * b);
}

// Operators
Point Point::operator-() const // Negate the coordinates
{
    return Point(-x, -y);
}
Point Point::operator*(double factor) const // Scale the coordinates
{
    return Point(factor * x, factor * y);
}
Point Point::operator+(const Point &p) const // Add coordinates
{
    return Point(x + p.x, y + p.y);
}
bool Point::operator==(const Point &p) const // Equally compare operator
{
    return (x == p.x && y == p.y);
}
Point &Point::operator=(const Point &source) // Assignment operator
{
    if (&source != this) {
        x = source.x;
        y = source.y; // assign parameters
    }
    cout << "Point assignment operator called." << endl;
    return *this;
}
Point &Point::operator*=(double factor) // Scale the coordinates & assign
{
    factor *= x;
    factor *= y; // scale the coordinates
    return *this;
}
ostream &operator<<(ostream &os, const Point &p) // The friend function of operator <<
{
    os << "Point(" << p.x << "," << p.y << ")"; // Put string in to ostream object
    return os;
}
} // namespace CAD
} // namespace Cluster