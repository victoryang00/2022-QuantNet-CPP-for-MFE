
#define _USE_MATH_DEFINES
#include "Circle.h"
#include <cmath>
#include <iostream>
// constructors and destructor
Circle::Circle(Point &p1, Line &l1) {
  centre.X(p1.X());
  centre.Y(p1.Y());
  radius.Stp(l1.Stp());
  radius.Endp(l1.Endp());
}
Circle::Circle(const Circle &O) {
  centre.X(O.CentrePoint().X());
  centre.Y(O.CentrePoint().Y());
  radius.Stp(O.Radius().Stp());
  radius.Endp(O.Radius().Endp());
}

// Selectors
Point Circle::CentrePoint() const { return centre; }
Line Circle::Radius() const { return radius; }

// Modifier
void Circle::CentrePoint(Point &p) {
  centre.X(p.X());
  centre.Y(p.Y());
}
void Circle::Radius(Line &l) {
  radius.Stp(l.Stp());
  radius.Endp(l.Endp());
}

// Geometric property functions
double Circle::Diameter() const { return (radius.Length() * 2); }
double Circle::Circumference() const { return (radius.Length() * 2 * M_PI); }
double Circle::Area() const {
  return (radius.Length() * radius.Length() * M_PI);
}

// Description
std::string Circle::ToString() const {
  std::stringstream source;
  source << "A circle centered at point(" << centre.X() << "," << centre.Y()
         << ") with a radius of " << radius.Length();
  return source.str();
}