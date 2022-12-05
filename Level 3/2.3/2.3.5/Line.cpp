
#include "Line.h"
#include <cmath>
#include <iostream>

Line::Line(Point &p1, Point &p2) {
  stp.X(p1.X());
  stp.Y(p1.Y());
  endp.X(p2.X());
  endp.Y(p2.Y());
}
Line::Line(const Line &l) {
  stp.X(l.Stp().X());
  stp.Y(l.Stp().Y());
  endp.X(l.Endp().X());
  endp.Y(l.Endp().Y());
}

Point Line::Stp() const { return stp; }
Point Line::Endp() const { return endp; }

void Line::Stp(Point &nstp) {
  stp.X(nstp.X());
  stp.Y(nstp.Y());
}
void Line::Endp(Point &nendp) {
  endp.X(nendp.X());
  endp.Y(nendp.Y());
}

std::string Line::ToString() const {
  std::stringstream source;
  source << "A line between (" << stp.X() << "," << stp.Y() << ") and ("
         << endp.X() << "," << endp.Y() << ").";
  return source.str();
}

double Line::Length() const {
  Point p1(stp);
  Point p2(endp);
  return p1.Distance(p2);
}