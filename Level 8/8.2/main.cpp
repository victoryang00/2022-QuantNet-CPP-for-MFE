#include <boost/tuple/tuple.hpp> // Tuple class
#include <boost/tuple/tuple_io.hpp> // I/O for tuples
#include <iostream>
#include <string>
using namespace std;

typedef boost::tuple<string, int, double> Person; // typedef for a Person tuple

void Print(const Person &p); // declare the function to print a Person tuple

int main() {
    // create some person tuple instance
    Person A(string("Apple"), 21, 176.5);
    Person B = boost::make_tuple(string("Yiwei"), 22, 184.1);
    Person C = boost::make_tuple(string("Bazinga"), 23, 170);
    Person D(string("Toy"), 24, 160.0);

    // print them
    Print(A);
    Print(B);
    Print(C);
    Print(D);

    D.get<1>() += 1;
    cout << "Increment the age of the person: ";
    Print(D);
}

void Print(const Person &p) // function body
{
    // print the records in tuple on screen
    cout << "Name: " << p.get<0>() << " Age: " << p.get<1>() << " Length: " << p.get<2>() << "." << endl;
    cout << endl; // print a new line
}