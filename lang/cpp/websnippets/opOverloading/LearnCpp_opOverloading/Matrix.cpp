/*
 * Example for overloading operator ()
 * UseCase: element access for class with array/container member
 * Source: http://www.learncpp.com/cpp-tutorial/99-overloading-the-parenthesis-operator/
 */

#include <cassert> // for assert()

#include "Matrix.h"

double& Matrix::operator()(int row, int col) {
    assert(col >= 0 && col < M_SIZE);
    assert(row >= 0 && row < M_SIZE);
    return data[row][col];
}

const double& Matrix::operator()(int row, int col) const
{
    assert(col >= 0 && col < M_SIZE);
    assert(row >= 0 && row < M_SIZE);
 
    return data[row][col];
}