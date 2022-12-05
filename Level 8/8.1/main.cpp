// This is a test program for smart pointer in boost lib.
#include "Array.h"
#include "Circle.h"
#include <boost/shared_ptr.hpp>
#include <iostream>
#ifndef ARRAY_CPP
#define ARRAY_CPP
#include "Array.cpp"
#endif
using namespace std;
using namespace Cluster::CAD;
using namespace Cluster::Containers;

typedef boost::shared_ptr<Shape> ShapePtr; // Type def for shape sharedptr
typedef Array<ShapePtr> ShapeArray;

int main() {

    // See how RAII on shared pointer of classes works
    ShapePtr mpoint(new Point(1));
    ShapePtr mline(new Line(Point(1), Point(2)));
    ShapePtr mcircle(new Circle(Point(0), Line(Point(0), Point(1))));

    { // create a new scope

        // create an array of shared pointers for shapes
        ShapeArray arr_shape(6);

        // fill the array
        arr_shape[0] = mpoint;
        cout << "# of Point Reference: " << mpoint.use_count() << endl;
        arr_shape[1] = mline;
        cout << "# of Line Reference: " << mline.use_count() << endl;
        arr_shape[2] = mpoint;
        cout << "# of Point Reference: " << mpoint.use_count() << endl;
        arr_shape[3] = mcircle;
        cout << "# of Circle Reference: " << mcircle.use_count() << endl;
        arr_shape[4] = mline;
        cout << "# of Line Reference: " << mline.use_count() << endl;
        arr_shape[5] = mcircle;
        cout << "# of Circle Reference: " << mcircle.use_count() << endl;

        // print the array
        for (int i = 0; i != 6; ++i) {
            (*arr_shape[i]).Print();
        }
    } // end of the scope

    // chece if the shapes are deleted automatically
    // See how RAII on shared pointer of classes array works
    cout << "Point Reference Count: " << mpoint.use_count() << endl;
    cout << "Line Reference Count: " << mline.use_count() << endl;
    cout << "Circle Reference Count: " << mcircle.use_count() << endl;

    // The output shows the shapes are deleted autometically.
}