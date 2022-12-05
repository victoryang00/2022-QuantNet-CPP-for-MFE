#include "Line.h"
using namespace std;
using namespace Cluster::CAD;
// this is a test program for virtual function in base class
int main() {
    Shape *shapes[3];
    shapes[0] = new Shape;
    shapes[1] = new Point;
    shapes[2] = new Line;
    for (int i = 0; i < 3; i++) {
        delete shapes[i];
        cout << endl; // add this to get a clearer view of the behavior of each element
    }
    // Without virtual destructor, destructor of base class is called three times.
    // However, no destructor of derived classes is called, which is incorrect.
    // With virtual destructor, desctructors of both base and derived class are called in a certain order(most derived -> most foundamental) as is shown in the test program.
}