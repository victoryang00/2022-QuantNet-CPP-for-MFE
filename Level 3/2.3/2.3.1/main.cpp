#include "Point.h"
#include <iostream>
using namespace std;
int main() {
  double x, y;
  cout << "Input x-coodinate" << endl;
  cin >> x;
  cout << "Input y-coodinate" << endl;
  cin >> y;

  Point pt;

  pt.SetX(x);
  pt.SetY(y);

  cout << pt.ToString() << endl;
  cout << "x coordinate of the point is " << pt.GetX() << endl;
  cout << "y coordinate of the point is " << pt.GetY() << endl;
}