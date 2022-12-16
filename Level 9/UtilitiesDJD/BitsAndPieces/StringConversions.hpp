// StringConversions.hpp
//
// Handy string functions
//
// (C) Datasim Education BV 2006
//

#ifndef StringConversions_HPP
#define StringConversions_HPP

#include "UtilitiesDJD/VectorsAndMatrices/Vector.cpp"
#include <string>
#include <list>
using namespace std;
#include <stddef.h>

std::string getString(long j)
{
    char str[200];
    sprintf(str, "%d", j);
    std::string result(str);
    return result;
}

std::string getString(int j)
{
    char str[200];
    sprintf(str, "%d", j);
    std::string result(str);
    return result;
}
std::string getString(size_t j)
{
    char str[200];
    sprintf(str, "%d", j);
    std::string result(str);
    return result;
}

std::string getString(double d)
{
    char str[200];
    sprintf(str, "%f", d);
    std::string result(str);
    return result;
}

std::list<std::string> convertToString(const Vector<double, long>& arr)
{

    std::list<std::string> result;

    for (long j = arr.MinIndex(); j <= arr.MaxIndex(); j++)
    {
        result.push_back(getString(arr[j]));
    }
    return result;
}
#endif