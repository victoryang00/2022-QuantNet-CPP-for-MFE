#include "Point.h"
#include <cmath>
#include <iostream>
// Constructors and Dectructors
Point::Point() { // default constructor
    x = 0;
    y = 0;
}
Point::Point(double newx, double newy) { // constructor with initial value of coordinates
    x = newx;
    y = newy;
}
Point::Point(const Point &P) { // copy constructor
    x = P.x;
    y = P.y;
}
Point::~Point() {} // destructor

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
    bool a = 0;
    if (x == p.x && y == p.y) {
        a = 1;
    }
    return a;
}
Point &Point::operator=(const Point &source) // Assignment operator
{
    x = source.x;
    y = source.y;
    return *this;
}
Point &Point::operator*=(double factor) // Scale the coordinates & assign
{
    x = factor * x;
    y = factor * y;
    return *this;
}