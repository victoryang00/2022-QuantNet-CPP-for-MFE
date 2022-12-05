#include "Circle.h"
using namespace std;
using namespace Cluster::CAD;
// this is a program for testing PVMF and ABC
int main() {
    // initialze a pointer to array and each element of the array
    Shape *shapes[10];
    shapes[0] = new Line;
    shapes[1] = new Point;
    shapes[2] = new Circle;
    shapes[3] = new Point(1, 1);
    shapes[4] = new Circle(Point(0, 0), Line(Point(0, 0), Point(1, 1)));
    shapes[5] = new Line;
    shapes[6] = new Point;
    shapes[7] = new Circle;
    shapes[8] = new Point;
    shapes[9] = new Line(Point(1.0, 2.5), Point(3.4, 5.2));

    // try Draw() function for each class
    for (int i = 0; i != 10; i++)
        shapes[i]->Draw();
    for (int i = 0; i != 10; i++)
        delete shapes[i];

    // Shape s;
	// Unimplemented pure virtual method 'Draw' in 'Shape' object of abstract class type "Cluster::CAD::Shape" is not allowed:

}