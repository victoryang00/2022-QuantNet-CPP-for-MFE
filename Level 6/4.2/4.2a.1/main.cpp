
#include "Array.h"
#include "Point.h"
using namespace std;
using namespace Cluster::CAD;
using namespace Cluster::Containers;

// this is a test program for template array
int main() {
    int size;
    cout << "Input the size of the array: ";
    cin >> size; // get size from the user
    Array<Point> points(size); // create an array of point as asked in the prompt

    // print the original array on screen
    for (int i = 0; i != size; i++) {
        cout << "Element " << i + 1 << " of the array is: " << points[i] << endl;
    }

    for (int i = 0; i != size; i++) {
        points[i] = Point(i + 1); // modify the array clearer results in later tests
    }
    cout << endl; // print a new line

    // test for getter
    int index;
    cout << "Input the index of element which you want to get: ";
    cin >> index; // get index from user for more flexible test
    try // in case the index is out of bound
    {
        cout << points.GetElement(index)
             << endl; // print the corresponding element on screen, can also use this to test exception handling
        cout << "The size of the array is: " << points.Size() << endl;

        // test for settet
        points.SetElement(index, Point(index + 1, 0)); // modify the corresponding element of the input index
        cout << "Element " << index + 1 << " of the array is now: " << points[index] << endl;
    }

    catch (ArrayException &err) // incorporate exception handling
    {
        cout << err.GetMessage() << endl; // print error message
    } catch (...) {
        cout << "An unknown error has occurred." << endl; // unexpected error message
    }

    cout << endl; // print a new line

    // test for assignment operater and copy constructor
    Array<Point> arr_p1 = points; // create an array with assignment operator
    Array<Point> arr_p2(points); // create an array with assignment operator

    // print both array on screen
    for (int i = 0; i != size; i++) {
        cout << "Element " << i + 1 << " of the arr_p1 is: " << arr_p1[i] << endl;
    }
    cout << endl; // print a new line
    for (int i = 0; i != size; i++) {
        cout << "Element " << i + 1 << " of the arr_p2 is: " << arr_p2[i] << endl;
    }
}