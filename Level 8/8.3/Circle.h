#include "Line.h"
#include <sstream>
using namespace std;
#ifndef CLASS_CIRCLE
#define CLASS_CIRCLE
namespace Cluster {
namespace CAD {
class Circle : public Shape {
private:
    Point centre;
    Line radius;

public:
    // constructors and destructor
    Circle(); // default constructor
    Circle(const Point &p1, const Line &l1); // constructor with parameters
    Circle(const Circle &O); // copy constructor
    ~Circle(); // destructor

    // Selectors
    Point CentrePoint() const;
    Line Radius() const;

    // Modifiers
    void CentrePoint(const Point &p);
    void Radius(Line &l);

    // Geometric Property Functions
    double Diameter();
    double Circumference();
    double Area();

    // Description
    std::string ToString() const;

    // Operator
    Circle &operator=(const Circle &O);

    // friends
    friend ostream &operator<<(ostream &os, const Circle &O);

    // Operations
    virtual void Draw() const;
};
} // namespace CAD
} // namespace Cluster
#endif