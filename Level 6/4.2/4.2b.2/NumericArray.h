#include "Array.h"
namespace Cluster {
namespace Containers {
template <typename T> class NumericArray : public Array<T> {
public:
    // constructors and destrucotor
    NumericArray(); // default construcor
    NumericArray(int s); // constructor with size parameter
    NumericArray(const NumericArray<T> &n_arr); // copy constructor
    virtual ~NumericArray(); // destructor

    // operators
    NumericArray<T> &operator=(const NumericArray<T> &source); // assignment operator
    NumericArray<T> operator*(double factor) const; // scaling operator *
    NumericArray<T> operator+(const NumericArray<T> &source)
        const; // adding operator +, throw exception when two arrays are of different size

    // dot product
    double DotProduct(const NumericArray<T> &source);
};
} // namespace Containers
} // namespace Cluster