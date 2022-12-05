#include "Circle.h"
using namespace std;
using namespace Cluster::CAD;
// this is a test program for class inheritance
int main() {
    Shape s; // Create shape.
    Point p(10, 20); // Create point.
    Line l(Point(1, 2), Point(3, 4)); // Create line.

    cout << s.ToString() << endl; // Print shape.
    cout << p.ToString() << endl; // Print point.
    cout << l.ToString() << endl; // Print line

    cout << "Shape ID: " << s.ID() << endl; // ID of the shape.
    cout << "Point ID: " << p.ID()
         << endl; // ID of the point. Does this work? It does work. (print "ID:18467" on screen in trial)
    cout << "Line ID: " << l.ID() << endl; // ID of the line. Does this work? It does work.

    Shape *sp; // Create pointer to a shape variable.
    sp = &p; // Point in a shape variable. Possible?: No compiler error popped out. Taken as possible.
    cout << sp->ToString() << endl; // What is printed?:"ID:18467",as in the previous command

    // Create and copy Point p to new point.
    Point p2;
    p2 = p;
    cout << p2 << ", " << p2.ID() << endl; // Is the ID copied if you do not call
    // the base class assignment in point?
    // the ID is not copied if assignment operator of shape class is not called in assignment operator of point class
}