#include "Array.h"
#include <iostream>
// constructors and destructor
Array::Array() // default constructor
{
    size = 10;
    data = new Point[size];
}
Array::Array(int s) // constructor with size
{
    size = s;
    data = new Point[s];
}
Array::Array(const Array &a) // copy constructor
{
    size = a.size;
    data = new Point[a.size];
    for (int i = 0; i < size; i++) {
        data[i] = a.data[i];
    }
}
Array::~Array() // destructor
{
    delete[] data;
    data = NULL;
}

// operators
Array &Array::operator=(const Array &source) {
    if (size == source.size && data == source.data) {
        return *this;
    } else {
        delete[] this->data;
        this->data = NULL;
        size = source.size;
        data = new Point[source.size];
        for (int i = 0; i < size; i++) {
            data[i] = source.data[i];
        }
        return *this;
    }
}
Point &Array::operator[](int index) {
    if (index > size - 1 || index < 0) {
        return data[0];
    } else {
        return data[index];
    }
}
const Point &Array::operator[](int index) const {
    if (index > size - 1 || index < 0) {
        return data[0];
    } else {
        return data[index];
    }
}

// Getters
int Array::Size() { return size; }

Point &Array::GetElement(int i) {
    if (i > size - 1 || i < 0) {
        return data[0];
    } else {
        return data[i];
    }
}

// Setter
void Array::SetElement(int &i, Point &p) {
    if (i >= 0 && i < size) {
        data[i] = p;
    }
}