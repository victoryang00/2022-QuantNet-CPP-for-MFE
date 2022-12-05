#include "Line.h"
#include <sstream>
using namespace std;
#ifndef CLASS_CIRCLE
#define CLASS_CIRCLE
namespace Cluster {
namespace CAD {
class Circle {
private:
    Point centre;
    Line radius;

public:
    // constructors and destructor
    Circle(); // default constructor
    Circle(Point &p1, Line &l1); // constructor with parameters
    Circle(const Circle &O); // copy constructor
    ~Circle(); // destructor

    // Selectors
    Point CentrePoint() const;
    Line Radius() const;

    // Modifiers
    void CentrePoint(Point &p);
    void Radius(Line &l);

    // Geometric Property Functions
    double Diameter();
    double Circumference();
    double Area();

    // Description
    std::string ToString();

    // Operator
    Circle &operator=(const Circle &O);

    // friends
    friend ostream &operator<<(ostream &os, Circle &O);
};
} // namespace CAD
} // namespace Cluster
#endif