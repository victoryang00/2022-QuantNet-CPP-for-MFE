#include "Array.cpp"
#include "Point.h"
#ifndef CLASS_POINTARRAY
#define CLASS_POINTARRAY
namespace Cluster {
namespace Containers {
class PointArray : public Array<CAD::Point> {
public:
    // constructors and destructor
    PointArray(); // default constructor
    PointArray(int s); // constructor with size parameter
    PointArray(const PointArray &source); // copy constructor
    virtual ~PointArray(); // destructor

    // function
    double Length(); // calculate the total length between elements
};
} // namespace Containers
} // namespace Cluster
#endif