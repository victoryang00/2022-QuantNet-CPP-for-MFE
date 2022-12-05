#include "Ltv.h"
#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>
using namespace std;
// this is a program for practicing using STL algorithms
double val = 4.5; // declare a global value to act as a benchmark in global function LessThan()
bool LessThan(double num) { return num < val; } // global function that compare double num with a certain number
int main() {
    vector<double> dbv; // create a vector with double element
    dbv.reserve(10); // reserve 10 places

    // initialize the vector
    for (int i = 0; i != 10; ++i) {
        dbv.push_back(i + i / 10);
    }

    // use count_if algorithm to count the element less than certain number
    int NumLess = count_if(dbv.begin(), dbv.end(), LessThan);

    // check the result
    cout << "We got that the # of elements in vector that is less than " << val << " is: " << NumLess << "." << endl;

    // try Ltv object
    Ltv ltv(6); // create a Ltv object with bencnmark of 6
    int Less1 = count_if(dbv.begin(), dbv.end(), ltv); // call count_if to count the number of elements less than 6
    cout << "We got that the # of elements in vector that is less than " << ltv.GetV() << " is: " << Less1 << "."
         << endl; // see result
    ltv.Benchmark(4.6); // modify the benchmark to 4.6
    int Less2 = count_if(dbv.begin(), dbv.end(), ltv); // call count_if to count the number of elements less than 4.6
    cout << "We got that the # of elements in vector that is less than " << ltv.GetV() << " is: " << Less2 << "."
         << endl; // see result
}