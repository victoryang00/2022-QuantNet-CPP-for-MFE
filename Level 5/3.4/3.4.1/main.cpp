#include "Circle.h"
#include <iostream>
using namespace std;
using namespace Cluster::CAD;
int main() {
    Line l;
// The default constructor and destructor for Point are called twice each when colon syntax is used.
// In this scenario, the assignment operator is not invoked.


// The default constructor and destructor for Point are called twice in class Line's colon syntax, respectively.
// The same number of times as in the preceding scenario, the constructor and destructor are called.
// In this instance, the class Point's assignment operator is not used.

// The situation is the same as the previous / case because class Point and class Circle also use colon syntax.
}