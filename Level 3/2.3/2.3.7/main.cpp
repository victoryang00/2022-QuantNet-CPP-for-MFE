#ifndef IOSTREAM
#define IOSTREAM
#include <iostream>
#endif
#ifndef POINT_H
#define POINT_H
#include "Point.h"
#endif
using namespace std;

int main() {

  double x1, y1;
  cout << "Input x-coodinate" << endl;
  cin >> x1;
  cout << "Input y-coodinate" << endl;
  cin >> y1;
  cout << endl;

  Point p1(x1, y1);
  cout << "Use X() to get the x-coordinate: ";
  cout << p1.X() << endl;
  cout << "Use Y() to get the y-coordinate: ";
  cout << p1.Y() << endl;

  cout << p1.ToString() << endl;
  cout << endl;

  cout << "Please re-assign the point." << endl;
  cout << "Input x-coodinate" << endl;
  cin >> x1;
  cout << "Input y-coodinate" << endl;
  cin >> y1;
  cout << endl;

  p1.X(x1);
  p1.Y(y1);

  cout << p1.ToString() << endl;
  cout << endl;
  cout << "End of Test." << endl;
}