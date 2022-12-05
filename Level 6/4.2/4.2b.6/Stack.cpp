#include "Stack.h"
#include "StackException.h"
namespace Cluster {
namespace Containers {
// constructors and destructor
template <typename T, int size>
Stack<T, size>::Stack() : arr(Array<T>(size)), current(0) {} // default constructor,set default size with size parameter

template <typename T, int size>
Stack<T, size>::Stack(const Stack<T, size> &source) : arr(source.arr), current(source.current) {} // copy constructor

template <typename T, int size> Stack<T, size>::~Stack() {} // destructor

// operator
template <typename T, int size>
Stack<T, size> &Stack<T, size>::operator=(const Stack<T, size> &source) // assignment operator
{
    if (this != &source) // handle self-assignment
    {
        arr = source.arr; // copy the embedded array
        current = source.current; // copy the Index
    }
    return *this;
}

// getter(for debug use)
template <typename T, int size> int Stack<T, size>::GetCurrent() const {
    return current - 1;
} // get the index of first "non-empty" element from the top

template <typename T, int size> T Stack<T, size>::GetEle() const {
    return arr[current - 1];
} // return the first "non-empty" element from the top

// functions
template <typename T, int size>
void Stack<T, size>::Push(T CurrentEle) // store current object and push one place forward
{
    try {
        arr[current] =
            CurrentEle; // store the current object(and to make sure that the first element can be initialized)
        /*T temp=arr[current+1;]*/ // add this line if data member current's upper bound is (size-1)(check if the next
                                   // place is empty)
        current++; // push one place forward
    } catch (ArrayException &) {
        throw StackFullException(); // throw a stack exception
        // in the try block, "current" is able to hit size of the underlying array
        // if there is a need to restrict the bound to (size-1), add the following code
        // current=arr.Size()-1;
    }
}

template <typename T, int size>
T Stack<T, size>::Pop() // push one place backward and return object at that place
{
    try {
        T ThrowAwayEle = arr[current - 1]; // return the element on that position
        current--; // decrement the current position
        return ThrowAwayEle;
    } catch (ArrayException &) {
        throw StackEmpException(); // throw a stack exception
        // in the try block, "current" will not decrement under zero. Therefore there's no need to set current back to
        // zero
    }
}
} // namespace Containers
} // namespace Cluster