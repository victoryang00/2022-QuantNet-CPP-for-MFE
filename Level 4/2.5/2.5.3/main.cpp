#include "Array.h"
#include "Point.h"
#include <iostream>
using namespace std;

// This is a program for testing array class
int main() {
    // Get the size of the array
    int s;
    cout << "Assign size of the array: ";
    cin >> s;

    // Test for constructors
    Array arr1; // default constructor
    Array arr2(s); // constructor with size 
    Array arr3(arr2); // copy constructor

    // See descriptions
    cout << "Array 1:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << arr1[i] << endl;
    }
    cout << endl;
    cout << "Array 2:" << endl;
    for (int i = 0; i < s; i++) {
        cout << arr2[i] << endl;
    }
    cout << endl;
    cout << "Array 3:" << endl;
    for (int i = 0; i < s; i++) {
        cout << arr3[i] << endl;
    }
    cout << endl;

    // Test for setter
    int index;
    double x1, y1;
    cout << "A point will be created to test the setter. Array 1 will be modified." << endl;
    cout << "Assign x-coordinate: ";
    cin >> x1;
    cout << "Assign y-coordinate: ";
    cin >> y1;
    cout << "Assign index of the element which you want to modify." << endl;
    cout << "Note: The index should satisfy the condition: 0<=index<10. Otherwise the first element would be modified."
         << endl;
    cout << "Index: ";
    cin >> index;
    Point p1(x1, y1); // Create a point
    arr1.SetElement(index, p1); // Modify the corresponding element
    if (index >= 0 && index < 10) {
        cout << "Element " << index + 1 << " of Array 1 is now: " << arr1[index] << endl;
    } // check the setter works
    else {
        cout << "Setter is ignored becouse the index is out of bound." << endl;
    } // check the setter works
    cout << endl;

    // Test for getters
    for (int i = 0; i < 10; i++) // Modify arr1 to get a clearer version
    {
        arr1[i] = Point(i + 1, 0);
    } //For write to the currect point
    cout << "Array 1 is modified to get a clearer result." << endl;
    cout << "Input the index of element you want to get: ";
    cin >> index;
    cout << "The first element will be desplayed if the index is out of bound." << endl;
    cout << arr1.GetElement(index) << endl;
    cout << "The size of Array 1 is: " << arr1.Size() << endl;
    cout << endl;

    // Test for operator = and [](for read)
    Array arr4;
    arr4 = arr1;
    cout << "Array 4 is created via '= Array 1'" << endl;
    cout << "Array 4:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << arr4[i] << endl;
    }
    cout << endl;

    // Test for const version of [], this is used for const objects
    cout << "A const point and a const array is initiallized for [] test." << endl;
    const Point cp = p1;
    arr2[0] = cp;
    const Array arr5(s);
    cout << "Element 1 of Array 2 is now: const " << arr2[0] << endl;
    cout << "Array 5:" << endl;
    for (int i = 0; i < s; i++) {
        cout << arr5[i] << endl;
    }

    cout << "End of Test." << endl;
}
