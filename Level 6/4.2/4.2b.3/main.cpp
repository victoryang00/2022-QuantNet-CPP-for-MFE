
#include "PointArray.h"
using namespace std;
using namespace Cluster::CAD;
using namespace Cluster::Containers;
// this is a test program for concrete inheritance
int main() {
    PointArray p_arr(5); // create an array of 5 points
    for (int i = 0; i != 5; i++) {
        p_arr[i] = Point(i, 0); // initiate every element. If initiate with types other than Point(e.g. int), a compiler
                                // error will be genenrated(C2679)
        cout << p_arr[i] << endl; // and display it on screen
    }
    cout << endl; // print a new line

    cout << "Test for function Length()." << endl;
    cout << "Length of p_arr is: " << p_arr.Length() << endl; // call Length() function
    cout << "End of Test" << endl;
}
