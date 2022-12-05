#include "Point.h"
#include <cmath>
#include <iostream>

Point::Point(double x, double y) {
  m_x = x;
  m_y = y;
}

double Point::X() const { return m_x; }
double Point::Y() const { return m_y; }

void Point::X(double newxval) { m_x = newxval; }
void Point::Y(double newyval) { m_y = newyval; }

std::string Point::ToString() const {
  std::stringstream m_string;
  m_string << "Point(" << m_x << "," << m_y << ")";
  return m_string.str();
}

double Point::Distance() const { return sqrt(m_x * m_x + m_y * m_y); }
double Point::Distance(Point &p) const {
  double a, b;
  a = m_x - p.X();
  b = m_y - p.Y();
  return sqrt(a * a + b * b);
}