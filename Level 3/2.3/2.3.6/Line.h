#include "Point.h"
#include <sstream>
#ifndef CLASS_LINE
#define CLASS_LINE
class Line {
private:
  Point stp;
  Point endp;

public:
  // constructors and destructor
  Line(){};                   // default constructor
  Line(Point &p1, Point &p2); // constructor with start- and end-point
  Line(const Line &l);        // copy constructor
  ~Line(){};                  // destructor

  // Selector
  Point Stp() const;
  Point Endp() const;

  // Modifier
  void Stp(const Point &nstp);
  void Endp(const Point &nendp);

  // Description
  std::string ToString() const;

  // Length
  double Length() const;
};
#endif