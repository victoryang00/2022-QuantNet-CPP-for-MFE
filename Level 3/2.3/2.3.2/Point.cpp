// Point.cpp
// Simple two-dimentional point with x and y coordinates
#include "Point.h"
#include <iostream>
#include <cmath>

// Constructors and Dectructors
Point::Point() { std::cout << "A Point has been created." << std::endl; }
Point::~Point() { std::cout << "A Point has been destructed." << std::endl; }
Point::Point(const Point &P) {
  m_x = P.GetX();
  m_y = P.GetY();
  std::cout << "Copy constructor is called." << std::endl;
}
Point::Point(double x, double y) {
  m_x = x;
  m_y = y; // Set the x- and y- coordinates
  std::cout << "A Point has been created without Set() function." << std::endl;
}

// Selectors
double Point::GetX() const // Access x value
{
  return m_x;
}
double Point::GetY() const // Access y value
{
  return m_y;
}

// Modifiers
void Point::SetX(double newxval) // Initiate m_x
{
  m_x = newxval;
}
void Point::SetY(double newyval) // Initiate m_y
{
  m_y = newyval;
}

// Description
std::string Point::ToString() {
  std::stringstream m_string;
  m_string << "Point(" << m_x << "," << m_y << ")";
  return m_string.str();
}

// Distance functions
double Point::DistanceOrigin() {
  return sqrt(m_x * m_x + m_y * m_y); // Distance to Origin=SquareRoot(x^2+y^2)
}
double Point::Distance(const Point &p) // Call by reference
{
  double a, b;
  a = m_x - p.GetX();     // Calculate the difference in x coordinates
  b = m_y - p.GetY();     // Calculate the difference in y coordinates
  /*p.SetX(p.GetX()-1);*/ // results in a compiler error
  return sqrt(a * a + b * b);
}