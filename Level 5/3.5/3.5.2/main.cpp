#include "Circle.h"
using namespace std;
using namespace Cluster::CAD;
// this is a programm for testing using base class functionality in derived classes
int main() {
    // declare and initialize the objects
    Point pt;
    Line r(pt, Point(1, 1));
    Circle O(pt, r);

    // see descriptions
    cout << pt.ToString() << endl; // description for point pt
    // no ID print if Shape::ToString() is not called in Point::ToString()
    cout << r.ToString() << endl; // description for line r
    cout << O.ToString() << endl; // description for circle O
}