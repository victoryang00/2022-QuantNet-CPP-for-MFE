#include "Array.h"
#include <iostream>
// constructors and destructor
Containers::Array::Array() // default constructor
{
    size = 10;
    data = new CAD::Point[size];
}
Containers::Array::Array(int s) // constructor with size
{
    size = s;
    data = new CAD::Point[s];
}
Containers::Array::Array(const Containers::Array &a) // copy constructor
{
    size = a.size;
    data = new CAD::Point[a.size];
    for (int i = 0; i < size; i++) {
        data[i] = a.data[i];
    }
}
Containers::Array::~Array() // destructor
{
    delete[] data;
    data = NULL;
}

// operators
Containers::Array &Containers::Array::operator=(const Containers::Array &source) {
    if (size == source.size && data == source.data) {
        return *this;
    } else {
        delete[] this->data;
        this->data = NULL;
        size = source.size;
        data = new CAD::Point[source.size];
        for (int i = 0; i < size; i++) {
            data[i] = source.data[i];
        }
        return *this;
    }
}
CAD::Point &Containers::Array::operator[](int index) {
    if (index > size - 1 || index < 0) {
        return data[0];
    } else {
        return data[index];
    }
}
const CAD::Point &Containers::Array::operator[](int index) const {
    if (index > size - 1 || index < 0) {
        return data[0];
    } else {
        return data[index];
    }
}

// Getters
int Containers::Array::Size() { return size; }

CAD::Point &Containers::Array::GetElement(int i) {
    if (i > size - 1 || i < 0) {
        return data[0];
    } else {
        return data[i];
    }
}

// Setter
void Containers::Array::SetElement(int &i, CAD::Point &p) {
    if (i >= 0 && i < size) {
        data[i] = p;
    }
}