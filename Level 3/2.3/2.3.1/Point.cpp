// Point.cpp
// Simple two-dimentional point with x and y coordinates
// 09-13-2016 PM
#ifndef POINT_H
#define POINT_H
#include "Point.h"
#endif
// Selectors
double Point::GetX() // Access x value
{
  return m_x;
}
double Point::GetY() // Access y value
{
  return m_y;
}

// Modifiers
void Point::SetX(double newxval) { m_x = newxval; }
void Point::SetY(double newyval) { m_y = newyval; }

// Description
std::string Point::ToString() {
  std::stringstream m_string;
  m_string << "Point(" << m_x << "," << m_y << ")";
  return m_string.str();
}
