#include "Array.h"
#include <iostream>
namespace Cluster {
namespace Containers {
// constructors and destructor
Array::Array() // default constructor
{
    size = 10; // default size is 10
    data = new CAD::Point[size]; // create an array of 10 points
}
Array::Array(int s) // constructor with size
{
    size = s; // size is s
    data = new CAD::Point[s]; // create an array of s points
}
Array::Array(const Array &a) // copy constructor
{
    size = a.size; // assign size
    data = new CAD::Point[a.size]; // create an array on the heap
    for (int i = 0; i < size; i++) // initialize elements in the array
    {
        data[i] = a.data[i]; // assign corresponding element in the operand
    }
}
Array::~Array() // destructor
{
    delete[] data; // free the memories allocated
}

// operators
Array &Array::operator=(const Array &source) {
    if (&source == this) // handle self-assignment
    {
        return *this;
    } else // not the same object
    {
        delete[] this->data; // free the memory in data of this object
        size = source.size; // re-assign the size
        data = new CAD::Point[source.size]; // re-assign the data
        for (int i = 0; i < size;
             i++) // initialize every element this->data with the corresponding element in source.data
        {
            data[i] = source.data[i];
        }
        return *this;
    }
}
CAD::Point &Array::operator[](int index) {
    if (index > size - 1 || index < 0) // if the index is out of bound
    {
        throw OutOfBoundsException(index);
    } // throw an error information
    else {
        return data[index];
    } // otherwise return the corresponding element of the index
}
const CAD::Point &Array::operator[](int index) const // use to handle const objects
{
    if (index > size - 1 || index < 0) // if the index is out of bound
    {
        throw OutOfBoundsException(index);
    } // throw an error information
    else {
        return data[index];
    } // otherwise return the corresponding element of the index
}

// Getters
int Array::Size() const { return size; }

CAD::Point &Array::GetElement(int i) const {
    if (i > size - 1 || i < 0) // if the index is out of bound
    {
        throw OutOfBoundsException(i);
    } // throw an error information
    else {
        return data[i];
    } // otherwise return the corresponding element of the index
}

// Setter
void Array::SetElement(int &i, CAD::Point &p) {
    if (i >= 0 && i < size) // if the index is inside the bound
    {
        data[i] = p;
    } // set the corresponding element
    else {
        throw OutOfBoundsException(i);
    } // otherwise throw an error information
}
} // namespace Containers
} // namespace Cluster