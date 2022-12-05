#ifndef POINT_H
#define POINT_H
#include "Point.h"
#endif
using namespace std;
using namespace Cluster::CAD;
// this is a test program for virtual function in base class
int main() {
    Point pt; // declare a point
    Shape *sp; // declare a pointer to class shape object
    sp = &pt; // initialize the pointer

    cout << sp->ToString() << endl; // To see which function is called

    // Without keyword virtual, Shape::ToString() is called.
    // With keyword virtual, Point::ToString() is called.
}