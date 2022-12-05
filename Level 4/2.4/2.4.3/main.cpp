#include <iostream>
#include "Point.h"
using namespace std;

int main()
{
    // Just use the default constructor.
	Point p(1.0, 1.0);
    // Compare with the copy constructor
	if (p==(Point)1.0) cout<<"Equal!"<<endl;
    // Else not equal!
	else cout<<"Not equal"<<endl;
}