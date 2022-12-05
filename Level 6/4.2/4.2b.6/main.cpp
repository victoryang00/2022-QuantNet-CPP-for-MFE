#ifndef STACK_CPP
#define STACK_CPP
#include "Stack.cpp"
#endif
using namespace std;
using namespace Cluster::Containers;
// this is a test program for class Stack<T,size>
int main() {
    Stack<int, 4> intstk2;
    // the following block check if Push() and Pop() of Stack<T,size> works properly
    for (int i = 0; i != 7; i++) {
        try {
            intstk2.Push(i + 1);
            cout << "Index = " << intstk2.GetCurrent() << "  Element:" << intstk2.GetEle() << "  with iterator:" << i
                 << endl;
        } catch (StackException &) // handle out-of-bound excpetion
        {
            int last = intstk2.Pop(); // drop an element
            cout << "The last element on stack is: " << last << "  with iterator:" << i << endl;
        } catch (...) // respond to unknow error
        {
            cout << "Unknown Error!" << endl;
        }
    }
    cout << endl; // print a new line

    cout << "100 has been pushed to the last element." << endl;
    intstk2.Push(100);
    cout << endl; // print a new line

    for (int i = 0; i != 7; i++) {
        try {
            int lastele = intstk2.Pop();
            cout << "The last element on stack is: " << lastele << "  with iterator:" << i << endl;
        } catch (StackException &) // handle out-of-bound excpetion
        {
            intstk2.Push(i + 1); // add an element
            cout << "Index = " << intstk2.GetCurrent() << "  Element:" << intstk2.GetEle() << "  with iterator:" << i
                 << endl; // get a clearer version(for debugging)
        } catch (...) // respond to unknow error
        {
            cout << "Unknown Error!" << endl;
        }
    }
    cout << endl;

    // try to assign stack of different size argument
    Stack<int, 3> intstk1;
    // intstk1=intstk2;
    // the above line gives a C2679: no operator found which takes a right-hand operand of type
    // Cluster::Containers::Stack<T,size>
}