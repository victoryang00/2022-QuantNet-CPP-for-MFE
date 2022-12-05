#ifndef ARRAY_H
#define ARRAY_H
#include "Array.h"
#endif
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
    } catch (int err) {
        if (err == -1)
            cout << "Index out of bound!" << endl; // out-of-bound error message
    } catch (...) {
        cout << "An unknown error has occurred." << endl; // unexpected error message
    }
}