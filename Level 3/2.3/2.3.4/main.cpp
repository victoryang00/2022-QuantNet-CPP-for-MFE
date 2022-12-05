#include "Point.h"
#include <iostream>
using namespace std;

int main() {

  double x1, y1;
  cout << "Input x-coodinate" << endl;
  cin >> x1;
  cout << "Input y-coodinate" << endl;
  cin >> y1;

  const Point cp(x1, y1);
  cout << "Use X() to get the x-coordinate: ";
  cout << cp.X() << endl;

  cout << cp.ToString() << endl;

  cout << "The Distance between the point and the origin is " << cp.Distance()
       << endl;

  cout << "Please assign another point." << endl;
  double x2, y2;
  cout << "Input x-coodinate" << endl;
  cin >> x2;
  cout << "Input y-coodinate" << endl;
  cin >> y2;

  Point p2(x2, y2);

  cout << "The Distance between the two points is " << cp.Distance(p2) << endl;
}