#include "Line.h"
#include <iostream>
using namespace std;

// friend class testing
// ToString() functions is incorporated in << and are not used in the main funciton
void Same(Point &p1, Point &p2); // Test file for == is incorporated in this function
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
    cout << endl; // print a new line

    // Initiate 2 Points
    Point p1(x1, y1);
    Point p2(x2, y2);

    // See descriptions
    cout << p1 << " and " << p2 << endl;
    cout << endl; // print a new line
    Same(p1, p2);
    cout << endl;

    Point pt;
    double factor;
    cout << "A new point is created for test." << endl;
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
    cout << endl;

    cout << "End of Test" << endl;
}
void Same(Point &p1, Point &p2) {
    // Test for ==
    if (p1 == p2) {
        cout << p1 << " and " << p2 << " have identical coordinates." << endl;
    } else {
        cout << p1 << " and " << p2 << " have different coordinates." << endl;
    }
}

// substitudes of ToString() function
ostream &operator<<(ostream &os, const Point &p) {
    os << "Point(" << p.x << "," << p.y << ")";
    return os;
}
ostream &operator<<(ostream &os, const Line &l) {
    os << "A line between Point(" << l.stp.x << "," << l.stp.y << ") and Point(" << l.endp.x << "," << l.endp.y << ").";
    return os;
}
