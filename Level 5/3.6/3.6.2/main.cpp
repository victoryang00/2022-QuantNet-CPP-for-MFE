#include "Array.h"
using namespace std;
using namespace Cluster::CAD;
using namespace Cluster::Containers;
// this is a program for testing bounds checking for class Array
int main() {
    int index; // declare the index variable
    Array arr_p; // create an array
    cout << "Input the index of the element you want to get: ";
    cin >> index; // get the index from user
    try {
        cout << arr_p[index] << endl;
        // the above line gives a debug error R6010: abort() has been called(without keywords "try" and "catch"), if
        // index is out of bound
    } catch (ArrayException &err) {
        cout << err.GetMessage() << endl; // print error message
    } catch (...) {
        cout << "An unknown error has occurred." << endl; // unexpected error message
    }
}