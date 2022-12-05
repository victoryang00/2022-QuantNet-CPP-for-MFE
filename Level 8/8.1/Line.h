#include "Point.h"
#include "Shape.h"
#include <sstream>
using namespace std;
#ifndef CLASS_LINE
#define CLASS_LINE
namespace Cluster {
namespace CAD {

class Line : public Shape {
private:
    Point stp;
    Point endp;

public:
    // constructors and destructor
    Line(); // default constructor
    Line(const Point &p1, const Point &p2); // constructor with start- and end-point
    Line(const Line &l); // copy constructor
    virtual ~Line(); // destructor

    // Selector
    Point Stp() const;
    Point Endp() const;

    // Modifier
    void Stp(Point &nstp);
    void Endp(Point &nendp);

    // Description
    virtual std::string ToString() const;

    // Length
    double Length();

    // Operator
    Line &operator=(const Line &source);

    // Friend
    friend class Circle;
    friend ostream &operator<<(ostream &os, const Circle &O);
    friend ostream &operator<<(ostream &os, const Line &l);

    // Operation
    virtual void Draw() const;
};
} // namespace CAD
} // namespace Cluster
#endif