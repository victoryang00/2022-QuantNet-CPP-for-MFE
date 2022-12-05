#include "Line.h"
#include <iostream>

using namespace std;
int main() {
  double x1, y1, x2, y2;
  cout << "Input a start point." << endl;
  cout << "x-coordinate: ";
  cin >> x1;
  cout << "y-coordinate: ";
  cin >> y1;
  cout << "Please assigh an end point." << endl;
  cout << "x-coordinate: ";
  cin >> x2;
  cout << "y-coordinate: ";
  cin >> y2;
  Point stp(x1, y1);
  Point endp(x2, y2);
  Line l(stp, endp);
  Line l2;

  cout << "Default Start Point: " << l2.Stp().ToString() << endl;
  cout << "Default End Point: " << l2.Endp().ToString() << endl;

  cout << l.ToString() << endl;

  Line l3(l);
  cout << "A copy of the line is created." << endl;
  cout << l3.ToString() << endl;

  cout << "Please re-assign a start point." << endl;
  cout << "x-coordinate: ";
  cin >> x1;
  cout << "y-coordinate: ";
  cin >> y1;
  cout << "Please re-assigh an end point." << endl;
  cout << "x-coordinate: ";
  cin >> x2;
  cout << "y-coordinate: ";
  cin >> y2;
  stp.X(x1);
  stp.Y(y1);
  endp.X(x2);
  endp.Y(y2);
  l.Stp(stp);
  l.Endp(endp);

  cout << l.ToString() << endl;

  cout << "The length of l is: " << l.Length() << endl;
}