#include "Array.cpp"
using namespace std;
using namespace Cluster::Containers;
// this is a test program for static data member
int main() {
    Array<int> intArray1;
    Array<int> intArray2;
    Array<double> doubleArray;

    // default size is 10 in the first place (df_size=10 in Array.cpp)

    cout << intArray1.DefaultSize() << endl; // 10
    cout << intArray2.DefaultSize() << endl; // 10
    cout << doubleArray.DefaultSize() << endl; // 10

    intArray1.DefaultSize(15);

    cout << intArray1.DefaultSize() << endl; // 15
    cout << intArray2.DefaultSize() << endl; // 15
    cout << doubleArray.DefaultSize() << endl; // 10. This is an array of a different type(double, not int)
    // default size of Array<double> is still 10
    // while default size of Array<int> is altered to 15
}