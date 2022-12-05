#include <sstream>
#ifndef CLASS_POINT
#define CLASS_POINT
class Point {
private:
  double m_x;
  double m_y;

public:
  // Constructor and Destructor
  Point();
  ~Point();
  Point(const Point &P);
  Point(double x, double y);

  // Selectors
  double GetX() const;
  double GetY() const;

  // Modifiers
  void SetX(double newxval);
  void SetY(double newyval);

  // Description
  std::string ToString();

  // Distance  function
  double DistanceOrigin();
  double Distance(const Point &p); // Call by referece
};
#endif