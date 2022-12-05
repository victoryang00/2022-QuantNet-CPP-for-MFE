#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <vector>
using namespace std;
// this is a program for practicing using iterator
template <typename T> double Sum(const T &source); // declare the generic function Sum()(add all)

template <typename T1> double Sum(const map<T1, double> &source); // declare Sum()(add all), specialised for map

template <typename T2> double Sum(T2 start, T2 end); // declare partial Sum() function

template <>
double Sum(typename map<const char *, double>::const_iterator start,
           typename map<const char *, double>::const_iterator end); // declare partial Sum() for map

int main() {
    list<double> dbl; // create a list of doubles

    // push to the list
    for (int i = 0; i != 10; i++) {
        dbl.push_back(i * 2);
    }

    // calculate the sum and partial sum
    cout << Sum(dbl) << endl;
    auto start = dbl.begin()++;
    auto end = dbl.end()--;
    cout << Sum(start, end) << endl;
    dbl.clear(); // clear list

    vector<double> dbv; // create a vector of doubles
    dbv.reserve(15); // reserve space for 15 elements

    // push to the vector
    for (int i = 0; i != 15; i++) {
        dbv.push_back(i + 1.5);
    }

    // calculate the sum and partial sum
    cout << Sum(dbv) << endl;
    auto start1 = dbv.begin()++;
    auto end1 = dbv.end()--;
    cout << Sum(start1, end1) << endl;
    dbv.clear(); // clear vector

    map<const char *, double> Info; // create a map that maps strings to doubles

    // add data
    Info["CountryNum"] = 01;
    Info["ZipCode"] = 95060;
    Info["DistrictNum"] = 777;
    Info["BuildingNum"] = 286;
    Info["FlatNum"] = 125;

    // calculate the sum and partial sum
    cout << Sum(Info) << endl;
    map<const char *, double>::const_iterator start2 = ++Info.begin();
    map<const char *, double>::const_iterator end2 = --Info.end();
    cout << Sum(start2, end2) << endl;
}
// Sum() all
template <typename T> double Sum(const T &source) {
    double sum = 0; // initialize sum
    typename T::const_iterator end = source.end(); // get an iterator for the end
    typename T::const_iterator i; // declare an iterator
    for (i = source.begin(); i != end; ++i) {
        sum += (*i); // add element to the sum with dereferenced iterator
    }
    return sum;
}
// Sum() all for map
template <typename T1> double Sum(const map<T1, double> &source) {
    double sum = 0; // initialize sum
    typename map<T1, double>::const_iterator it; // declare a map iterator
    typename map<T1, double>::const_iterator end = source.end(); // get an iterator for the end
    for (it = source.begin(); it != end; ++it) {
        sum += it->second; // add to sum the double variable
    }
    return sum;
}
// Partial sum
template <typename T2> double Sum(T2 start, T2 end) {
    double sum = 0; // initialize sum
    T2 i; // declare an iterator
    for (i = start; i != end; ++i) {
        sum += (*i); // add every element inside range [start,end] to sum
    }
    return sum;
}
// Partial sum for map
template <>
double Sum(typename map<const char *, double>::const_iterator start,
           typename map<const char *, double>::const_iterator end) {
    double sum = 0; // initialize sum
    map<const char *, double>::const_iterator i; // declare an iterator for map<const char*,double>
    for (i = start; i != end; ++i) {
        sum = sum + i->second; // add to sum every double varialble to sum in range [start,end]
    }
    return sum;
}