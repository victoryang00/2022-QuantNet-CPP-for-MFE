
#include "Point.h"
#include <iostream>
#include <cmath>

// Constructors and Dectructors
Point::Point(double x, double y) {
  m_x = x;
  m_y = y; // Set the x- and y- coordinates
}

// Description
std::string Point::ToString() const {
  std::stringstream m_string;
  m_string << "Point(" << m_x << "," << m_y << ")";
  return m_string.str();
}

// Distance functions
double Point::Distance() const {
  return sqrt(m_x * m_x + m_y * m_y); // Distance to Origin=SquareRoot(x^2+y^2)
}
double Point::Distance(Point &p) const // Call by reference
{
  double a, b;
  a = m_x - p.X(); // Calculate the difference in x coordinates
  b = m_y - p.Y(); // Calculate the difference in y coordinates
  return sqrt(a * a + b * b);
}