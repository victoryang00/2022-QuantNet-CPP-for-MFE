#include "Circle.h"
#include <iostream>
using namespace std;

// This is a file for testing the operator <<
// ToString() functions is incorporated in << and are not used in the main funciton
void Same(Point &p1, Point &p2); // Test for == is incorporated in this function
int main() {
    // Initiate coordinates
    double x1, x2, y1, y2;
    cout << "Two points will be initiated." << endl;
    cout << "The first point: " << endl;
    cout << "Input x coordinate: ";
    cin >> x1;
    cout << "Input y coordinate: ";
    cin >> y1;
    cout << "The second point: " << endl;
    cout << "Input x coordinate: ";
    cin >> x2;
    cout << "Input y coordinate: ";
    cin >> y2;

    // Initiate 2 Points
    Point p1(x1, y1);
    Point p2(x2, y2);

    // See descriptions
    cout << p1 << " and " << p2 << endl;
    // To see whether they are the same
    Same(p1, p2);
    cout << endl;

    Point pt;
    double factor;
    cout << "A new point is created for test." << endl;
    // To find the point has been created for test
    pt = p1 + p2; // test for +
    cout << p1 << "+" << p2 << "=" << pt << endl;
    pt = -p1; // test for -
    cout << "-" << p1 << "=" << pt << endl;
    cout << endl;

    cout << "Input a multiplicative factor: ";
    cin >> factor;
    cout << endl;
    pt = p1 * factor; // test for *
    cout << p1 << "*" << factor << "=" << pt << endl;
    pt = p2; // test for =
    Same(pt, p2);
    pt *= factor; // test for *=
    cout << pt << "=" << p2 << "*=" << factor << endl;
    cout << endl;

    Line r(p1, p2);
    cout << p1 << " and " << p2 << endl;
    cout << r << endl;
    Line l;
    l = r; // Test for = of Line class
    cout << "A copy of the line is created." << endl;
    cout << l << endl;
    Circle O(p1, r);
    cout << "A circle is created." << endl;
    cout << O << endl;
    Circle O1;
    O1 = O; // Test for = of Circle class
    cout << "A copy of the circle is created." << endl;
    cout << O1 << endl;
    cout << endl;

    cout << "End of Test" << endl;
}
void Same(Point &p1, Point &p2) {
    // Test for ==
    if (p1 != p2) {
        cout << p1 << " and " << p2 << " have different coordinates." << endl;
    } else {
        cout << p1 << " and " << p2 << " have identical coordinates." << endl;
    }
}
ostream &operator<<(ostream &os, const Point &p) {
    os << p.ToString();
    return os;
}
ostream &operator<<(ostream &os, const Line &l) {
    os << l.ToString();
    return os;
}
ostream &operator<<(ostream &os, Circle &O) {
    os << O.ToString();
    return os;
}