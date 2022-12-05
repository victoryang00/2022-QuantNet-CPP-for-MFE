#include "ExHandle.h"
#include "Point.h"
#include <sstream>
#ifndef CLASS_ARRAY
#define CLASS_ARRAY
namespace Cluster {
namespace Containers {
class Array {
private:
    CAD::Point *data;
    int size;

public:
    // constructors and destructor
    Array(); // default constructor
    Array(int s); // constructor with size
    Array(const Array &a); // copy constructor
    ~Array(); // destructor

    // operators
    Array &operator=(const Array &source);
    CAD::Point &operator[](int index);
    const CAD::Point &operator[](int index) const;

    // Getters
    int Size() const;
    CAD::Point &GetElement(int i) const;

    // Setter
    void SetElement(int &i, CAD::Point &p);
};
} // namespace Containers
} // namespace Cluster
#endif