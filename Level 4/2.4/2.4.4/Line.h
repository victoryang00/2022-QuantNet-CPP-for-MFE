#include "Point.h"
#include <string>
#include <sstream>
using namespace std;
#ifndef CLASS_LINE
#define CLASS_LINE
class Line {
private:
    Point stp;
    Point endp;

public:
    Line(); // default constructor
    Line(Point &p1, Point &p2); // constructor with start- and end-point
    Line(const Line &l); // copy constructor
    ~Line(); // destructor

    // Selector
    Point Stp() const;
    Point Endp() const;

    // Modifier
    void Stp(Point &nstp);
    void Endp(Point &nendp);

    // Description
    std::string ToString() const;

    // Length
    double Length();

    // Operator
    Line &operator=(const Line &source);

    // Friend
    friend ostream &operator<<(ostream &os, const Line &l);
};

#endif