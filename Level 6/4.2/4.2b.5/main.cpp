#ifndef STACK_CPP
#define STACK_CPP
#include "Stack.cpp"
#endif
using namespace std;
using namespace Cluster::Containers;
// this is a test program for class Stack (composition)
int main() {
    Stack<int> intstk1; // create with default constructor
    Stack<int> intstk2(4); // create with constructor with parameter

    for (int i = 0; i != 15; i++) {
        try {
            intstk1.Push(i + 1);
            cout << "Index = " << intstk1.GetCurrent() << "  Element:" << intstk1.GetEle() << "  with iterator:" << i
                 << endl;
        } catch (StackException &) // handle out-of-bound excpetion
        {
            int last = intstk1.Pop(); // drop an element
            cout << "The last element on stack is: " << last << "  with iterator:" << i << endl;
        } catch (...) // respond to unknow error
        {
            cout << "Unknown Error!" << endl;
        }
    }
    cout << endl; // print a new line

    cout << "100 has been pushed to the last element." << endl;
    intstk1.Push(100);
    cout << endl; // print a new line

    for (int i = 0; i != 15; i++) {
        try {
            int lastele = intstk1.Pop();
            cout << "The last element on stack is: " << lastele << "  with iterator:" << i << endl;
        } catch (StackException &) // handle out-of-bound excpetion
        {
            intstk1.Push(i + 1); // add an element
            cout << "Index = " << intstk1.GetCurrent() << "  Element:" << intstk1.GetEle() << "  with iterator:" << i
                 << endl; // get a clearer version(for debugging)
        } catch (...) // respond to unknow error
        {
            cout << "Unknown Error!" << endl;
        }
    }
    cout << endl; // print a new line

    // check if constructor with parameter works properly
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
    // try copy constructor and assignment operator
    Stack<int> c1_intstk2(intstk2);
    Stack<int> c2_intstk2 = intstk2;

    for (int i = 0; i != 7; i++) // trial for c1_intstk2
    {
        try {
            c1_intstk2.Push(i + 2); // push an element
            cout << "Index = " << c1_intstk2.GetCurrent() << "  Element:" << c1_intstk2.GetEle()
                 << "  with iterator:" << i << endl;
        } catch (StackException &) // handle out-of-bound excpetion
        {
            int last = c1_intstk2.Pop(); // drop an element
            cout << "The last element on stack is: " << last << "  with iterator:" << i << endl;
        } catch (...) // respond to unknow error
        {
            cout << "Unknown Error!" << endl;
        }
    }
    cout << endl; // print a new line

    for (int i = 0; i != 7; i++) // trial for c2_intstk2
    {
        try {
            c2_intstk2.Push(i + 3); // push an element
            cout << "Index = " << c2_intstk2.GetCurrent() << "  Element:" << c2_intstk2.GetEle()
                 << "  with iterator:" << i << endl;
        } catch (StackException &) // handle out-of-bound excpetion
        {
            int last = c2_intstk2.Pop(); // drop an element
            cout << "The last element on stack is: " << last << "  with iterator:" << i << endl;
        } catch (...) // respond to unknow error
        {
            cout << "Unknown Error!" << endl;
        }
    }
    cout << endl; // print a new line
}