// point.hpp
#include <sstream>
#ifndef CLASS_POINT
#define CLASS_POINT
class Point {
private:
  double m_x;
  double m_y;

public:
  // Constructor and Destructor
  Point(){};
  ~Point(){};

  // Selectors
  double GetX(); // Access x value
  double GetY(); // Access y value

  // Modifiers
  void SetX(double newxval); // Set x value
  void SetY(double newyval); // Set y value

  // Description
  std::string ToString();
};
#endif