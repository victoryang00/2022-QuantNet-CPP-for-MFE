#include "Visitor.h"
namespace Cluster {
namespace CAD {
// constructors and distructor
Visitor::Visitor() : boost::static_visitor<void>(), x_offset(0.5), y_offset(0.5) {} // default constructor
Visitor::Visitor(double x, double y)
    : boost::static_visitor<void>(), x_offset(x), y_offset(y) {} // constructor with parameters
Visitor::Visitor(const Visitor &source)
    : boost::static_visitor<void>(source), x_offset(source.x_offset), y_offset(source.y_offset) {} // copy constructor
Visitor::~Visitor() {} // destructor

// getters
double Visitor::XO() // get x_offset
{
    return x_offset;
}
double Visitor::YO() // get y_offset
{
    return y_offset;
}

// modifiers
void Visitor::XO(double x) // modify x_offset
{
    x_offset = x;
}
void Visitor::YO(double y) // modify y_offset
{
    y_offset = y;
}

// operators
Visitor &Visitor::operator=(const Visitor &source) // assignment operator
{
    if (this != &source) // handle self-assignment
    {
        // get base class assignment operator
        boost::static_visitor<void>::operator=(source);

        // assign corresponding data members
        x_offset = source.x_offset;
        y_offset = source.y_offset;
    }
    return *this;
}
// The operator to get the point.
void Visitor::operator()(Point &p) const {
    p.X(p.X() + x_offset); // get class Point modifier and selector for x coordinate
    p.Y(p.Y() + y_offset); // get class Point modifier and selector for y coordinate
}
// The operator to get the line.
void Visitor::operator()(Line &l) const {
    l.Stp(l.Stp() + Point(x_offset, y_offset)); // get start-point modifier of class Line and operator + of class Point
    l.Endp(l.Endp() + Point(x_offset, y_offset)); // get end-point modifier of class Line and operator + of class Point
}
// The operator to get the circle.
void Visitor::operator()(Circle &O) const {
    // get centre point modifier of class Circle and operator + of class Point
    O.CentrePoint(O.CentrePoint() + Point(x_offset, y_offset));
}
} // namespace CAD
} // namespace Cluster