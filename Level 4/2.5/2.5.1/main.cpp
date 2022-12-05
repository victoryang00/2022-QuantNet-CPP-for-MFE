#include "Point.h"
#include <iostream>
using namespace std;

// This is a program for testing the free store
int main() {
    // Get coordinates from user
    double x1, y1;
    cout << "Input two coordinates: " << endl;
    cout << "x: ";
    cin >> x1;
    cout << "y: ";
    cin >> y1;

    // Create a new point
    Point *pp1 = new Point; //  default constructor
    Point *pp2 = new Point(x1, y1);
    Point *pp3 = new Point(*pp2); //  copy constructor

    // See descriptions
    cout << "The description for point 1 " << (*pp1) << endl;
    cout << "The description for point 2 " << (*pp2) << endl;
    cout << "The description for point 3 " << (*pp3) << endl;

    // Calculate distance
    cout << "The distance between " << (*pp1) << " and " << (*pp2) << " is " << (*pp1).Distance(*pp2) << endl;
    cout << "The distance between " << (*pp2) << " and " << (*pp3) << " is " << (*pp2).Distance(*pp3) << endl;

    // free the memories allocated to Points.
    delete pp1;
    delete pp2;
    delete pp3;
    pp1 = NULL;
    pp2 = NULL;
    pp3 = NULL;

    // Get the size of the array
    int size;
    cout << "Array created." << endl;
    cout << "Please assign the size of the array: ";
    cin >> size;

    // Create an array on the heap
    Point *arr_point = new Point[size];
    // See the array entries
    cout << "The entries of the array are as follows:" << endl;
    for (int i = 0; i < size; i++) {
        cout << arr_point[i] << endl;
    }

    delete[] arr_point;
    arr_point = NULL; // free the memories
}
