#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <vector>
using namespace std;
// this is a program for practicing using STL Containers
int main() {
    list<double> dbl; // create a list of doubles

    // add data to the list
    dbl.push_back(1.5);
    dbl.push_back(2.5);
    dbl.push_back(3.5);
    dbl.push_front(4.5);

    // print the list, using front() and back() to access first and last element
    cout << dbl.front() << endl; // print the first element
    cout << dbl.back() << endl; // print the last element

    copy(dbl.begin(), dbl.end(), std::ostream_iterator<double>(cout, "\n")); // print the list
    dbl.clear(); // clear list

    vector<double> dbv; // create a vector of doubles
    dbv.reserve(15); // reserve space for 15 elements

    // add data to the vector
    dbv.push_back(1.);
    dbv.push_back(2.);
    dbv.push_back(3.);
    dbv.push_back(4.);

    // access element with index operator
    cout << "Element 0: " << dbv[0] << endl; // print the first element
    cout << "Element 1: " << dbv[1] << endl; // print the last element
    cout << "Element 2: " << dbv[2] << endl; // print the last element
    cout << "Element 3: " << dbv[3] << endl; // print the last element
    cout << "Size: " << dbv.size() << endl; // get size of the current vector
    cout << "Capacity: " << dbv.capacity() << endl; // get capacity of the current vector
    dbv.clear(); // clear vector

    map<const char *, double> Info; // create a map that maps strings to doubles

    // add data
    Info["CountryNumber"] = 01;
    Info["ZipCode"] = 95060;
    Info["DistrictNumber"] = 0777;

    // access element with []
    cout << Info["CountryNumber"] << endl;
    cout << Info["ZipCode"] << endl;
    cout << Info["DistrictNumber"] << endl;
}