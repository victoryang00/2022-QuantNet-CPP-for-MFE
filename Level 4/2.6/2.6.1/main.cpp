#include "Array.h"
#include "Circle.h"
#include "Cluster.h"
#include <iostream>

using namespace std;
using namespace Cluster::Containers;
using Cluster::CAD::Line;
using Cluster::CAD::Point;
namespace Circ = Cluster::CAD;

ostream &Cluster::operator<<(ostream &os, const Cluster::CAD::Point &p) {
    os << "Point(" << p.x << "," << p.y << ")";
    return os;
}
ostream &Cluster::operator<<(ostream &os, const Cluster::CAD::Line &l) {
    os << "A line between Point(" << l.stp.x << "," << l.stp.y << ") and Point(" << l.endp.x << "," << l.endp.y << ").";
    return os;
}
ostream &Cluster::operator<<(ostream &os, Circ::Circle &O) {
    os << O.ToString();
    return os;
}

// This is a test program for namspace
int main() {
    // Experiment with Array and Point first
    // Get the size of the array
    int s;
    cout << "Please assign the size of the array: ";
    cin >> s;

    Array arr1(s); // Create an array

    for (int i = 0; i < s; i++) // Modify arr1
    {
        arr1[i] = Point(i + 1, 0);
    } // modify each element with Point(full namespace)

    // See descriptions
    cout << "Array 1:" << endl;
    for (int i = 0; i < s; i++) {
        cout << arr1[i] << endl;
    }
    cout << endl;

    // Initiate coordinates to create points, then line, then circle
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

    // Create the objects
    Point p1(x1, y1);
    Point p2(x2, y2);
    Line r(p1, p2);
    Circ::Circle O(p1, r);

    // See descriptions
    cout << p1 << " and " << p2 << endl;
    cout << r << " with a lengh of " << r.Length() << endl;
    cout << O << ", whose circumference is " << O.Circumference() << " and whose area is " << O.Area() << endl;
}
