#include "Circle.h"
#include "Visitor.h"
#include <boost/variant.hpp>
#include <iostream>
#include <string>

using namespace std;
using namespace Cluster::CAD;
using boost::variant;

// typedef boost::variant for shapes
typedef variant<Point, Line, Circle> ShapeType;

// declare the function that asks input type from the user and returns a ShapeType object
ShapeType WhatToCreate();

// please run the program for multiple times to carry out test for different shapes
int main() {
    ShapeType mshape;
    mshape = WhatToCreate(); // call the function and ask user to specify a type to return

    // print the variant
    cout << "Input Type: " << mshape << endl;

    // test exception handling of boost::get<T>
    try {
        Line l; // create a line
        l = boost::get<Line>(mshape); // try to assign mshape to l
        cout << l << endl; // see result
    } catch (boost::bad_get &err) {
        cout << "Error: " << err.what() << " Not Line!" << endl; // print error message
    }

    // test for class Visitor
    Visitor VShape; // create a visitor object
    cout << "Modification parameters:\nX: " << VShape.XO() << " Y: " << VShape.YO() << endl; // see parameters

    boost::apply_visitor(VShape, mshape); // modify the variant
    cout << "After modification: " << mshape << endl; // see results
}

// function body
ShapeType WhatToCreate() {
    ShapeType Proto; // create a variant
    int type;
    cout << "What kind of shape to create?\nInput 1 for Point, 2 for Line and 3 for Circle: ";
    cin >> type; // User Input
    switch (type) {
    case 1: // case specifies a Point
    {
        Proto = Point(0); // assign a Point to variant
        break;
    }
    case 2: // case specifies a Line
    {
        Proto = Line(Point(0), Point(1)); // assign a Line to variant
        break;
    }
    case 3: // case specifies a Circle
    {
        Proto = Circle(Point(0), Line(Point(0), Point(1))); // assign a Circle to variant
        break;
    }
    default: // Bad Input
    {
        cout << "Wrong input, fall back to Point(0)" << endl;
        Proto = Point(0);
        break;
    }
    }
    return Proto;
}