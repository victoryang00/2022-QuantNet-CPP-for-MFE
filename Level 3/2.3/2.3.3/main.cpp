#include "Point.h"
#include <iostream>
using namespace std;

int main() {

  double x1, y1;
  cout << "Input x-coodinate" << endl;
  cin >> x1;
  cout << "Input y-coodinate" << endl;
  cin >> y1;

  Point pt(x1, y1);

  cout << pt.ToString() << endl;

  cout << "x coordinate of the point is " << pt.X() << endl;
  cout << "y coordinate of the point is " << pt.Y() << endl;

  cout << "The Distance between the point and the origin is " << pt.Distance()
       << endl;

  cout << "Please assign another point." << endl;
  double x2, y2;
  cout << "Input x-coodinate" << endl;
  cin >> x2;
  cout << "Input y-coodinate" << endl;
  cin >> y2;

  Point p2(x2, y2);

  cout << "The Distance between the two points is " << pt.Distance(p2) << endl;
}