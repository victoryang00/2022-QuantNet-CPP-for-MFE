#include "Point.h"
#include <cmath>
#include <iostream>

// Constructors and Dectructors
Point::Point(double x, double y) {
    m_x = x;
    m_y = y; // Set the x- and y- coordinates
}

// Selectors
double Point::X() { return m_x; }
double Point::Y() { return m_y; }

// Modifiers
void Point::X(double newxval) { m_x = newxval; }
void Point::Y(double newyval) { m_y = newyval; }

// Description
std::string Point::ToString() {
    std::stringstream m_string;
    m_string << "Point(" << m_x << "," << m_y << ")";
    return m_string.str();
}

// Distance functions
double Point::Distance() { return sqrt(m_x * m_x + m_y * m_y); }
double Point::Distance(Point &p) {
    double a, b;
    a = m_x - p.X();
    b = m_y - p.Y();
    return sqrt(a * a + b * b);
}