#include <iostream>
#include "Circle.h"
using namespace std;

int main() {

  double x1, y1, x2, y2;
  cout << "Input two points to construct a circle." << endl;
  cout << "One of the points is the centre of the circle, and the line between "
          "them the radius."
       << endl;
  cout << "Input the centre point:" << endl;
  cout << "x-coordinate: " << endl;
  cin >> x1;
  cout << "y-coodinate: " << endl;
  cin >> y1;
  cout << "Input the other point:" << endl;
  cout << "x-coordinate: " << endl;
  cin >> x2;
  cout << "y-coodinate: " << endl;
  cin >> y2;
  cout << endl;

  Point cent(x1, y1);
  Point circ(x2, y2);
  Line r(cent, circ);
  Circle O(cent, r);

  cout << O.ToString() << endl;
  cout << endl;

  cout << "The centre of the circle is " << O.CentrePoint().ToString() << endl;
  cout << "The radius of the circle is " << O.Radius().ToString() << endl;
  cout << endl;

  cout << "Input another point." << endl;
  cout << "This newly-assigned point would become the centre of a new circle."
       << endl;
  cout << "The previous centre would be a point on the circumferences of the "
          "new circle."
       << endl;
  cout << "x-coordinate: " << endl;
  cin >> x2;
  cout << "y-coodinate: " << endl;
  cin >> y2;
  cout << endl;

  circ.X(x2);
  circ.Y(y2);
  r.Stp(circ);
  r.Endp(cent);
  O.CentrePoint(circ);
  O.Radius(r);

  cout << O.ToString() << endl;
  cout << endl;

  cout << "The diameter of the new circle is: " << O.Diameter() << endl;
  cout << "The circumference of the new circle is: " << O.Circumference()
       << endl;
  cout << "The area of the new circle is: " << O.Area() << endl;
  cout << endl;
  cout << "End of Test" << endl;
}