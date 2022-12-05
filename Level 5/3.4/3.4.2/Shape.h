#include <iostream>
#include <sstream>
#include <stdlib.h>
#ifndef CLASS_SHAPE
#define CLASS_SHAPE
namespace Cluster {
namespace CAD {
class Shape {
private:
    int id;

public:
    // constructors and destructor
    Shape(); // default constructor
    Shape(const Shape &S); // copy constructor
    ~Shape(); // destructor

    // Description
    std::string ToString() const; // get the description of id

    // Getter
    int ID() const; // get the id

    // operators
    Shape &operator=(const Shape &source); // Assignment operator
};
} // namespace CAD
} // namespace Cluster
#endif