#ifndef ARRAY_CPP
#define ARRAY_CPP
#include "Array.cpp"
#endif
#ifndef NA_CPP
#define NA_CPP
#include "NumericArray.cpp"
#endif
using namespace std;
using namespace Cluster::Containers;
// this is a program for testing generic inheritance
int main() {
    // NumericArray is designed for array of classes in which operator +, *(product(for two objects) sign, not scaling
    // sign)
    int size;
    cout << "Input a size parameter: ";
    cin >> size; // get size parameter from the user

    NumericArray<int> intarr(size); // create Numeric Array of int of size size
    NumericArray<double> dbarr(size); // create Numeric Array of double of size size
    NumericArray<double> dfdbarr; // create Numeric Array of double with default constructor

    // initialize and display the arrays
    for (int i = 0; i != size; i++) {
        intarr[i] = i + 1; // initialize the member of intarr
        cout << "Element " << i + 1 << " of intarr is: " << intarr[i] << endl; // and display it on screen
    }

    for (int i = 0; i != size; i++) {
        dbarr[i] = i + 0.5; // initialize the member of dbarr
        cout << "Element " << i + 1 << " of dbarr is: " << dbarr[i] << endl; // and display it on screen
    }

    for (int i = 0; i != dfdbarr.DefaultSize(); i++) {
        dfdbarr[i] = i + 0.3; // initialize the member of intarr
        cout << "Element " << i + 1 << " of dfdbarr is: " << dfdbarr[i] << endl; // and display it on screen
    }

    cout << "Test for copy constructor." << endl;
    NumericArray<double> copydbarr(dbarr); // create a numeric array with copy constructor
    for (int i = 0; i != copydbarr.Size(); i++) {
        cout << "Original element: " << dbarr[i] << " Copy: " << copydbarr[i]
             << endl; // display and compare with the original array
    }

    NumericArray<double> result = dbarr * 2; // test operator *
    cout << "test for operator *" << endl;
    for (int i = 0; i != dbarr.Size(); i++) {
        cout << "Original element: " << dbarr[i] << ", after *2= " << result[i]
             << endl; // display and compare with the original array
    }

    try {
        cout << "test for operator +" << endl;
        dbarr = copydbarr + copydbarr; // test for operator +
        for (int i = 0; i != dbarr.Size(); i++) // display the result
        {
            cout << copydbarr[i] << " + " << copydbarr[i] << " = " << dbarr[i] << endl;
        }

        cout << "test for DotProduct()" << endl;
        double sum1, sum2;
        sum1 = intarr.DotProduct(intarr); // test for DotProduct()
        cout << "intarr.DotProduct(intarr)=" << sum1 << endl;
        sum2 = copydbarr.DotProduct(copydbarr); // test for different type
        cout << "copydbarr.DotProduct(copydbarr)=" << sum2 << endl;

        cout << "test exception handling" << endl;
        dbarr = copydbarr + dfdbarr; // add two arrays of different size
        double sum3;
        sum3 = copydbarr.DotProduct(dfdbarr); // dot prodoct arrays of different size
    } catch (NAException &err) // catch the exception message thrown
    {
        cout << err.GetMessage() << endl;
    } catch (...) // handle unknown error
    {
        cout << "Unknown error!" << endl;
    }
}