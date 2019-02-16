/*
 * Example for overloading operator ()
 * UseCase: element access for class with array/container member
 * Source: http://www.learncpp.com/cpp-tutorial/99-overloading-the-parenthesis-operator/
 */

/* 
 * File:   Matrix.h
 * Author: johannesw
 *
 * Created on 11. Juli 2017, 14:40
 */

#ifndef MATRIX_H
#define MATRIX_H

#define M_SIZE 4

class Matrix {
private:
    double data[M_SIZE][M_SIZE];
public:

    Matrix() {
        // Set all elements of the matrix to 0.0
        for (int row = 0; row < 4; ++row)
            for (int col = 0; col < 4; ++col)
                data[row][col] = 0.0;
    }

    double& operator()(int row, int col);
    const double& operator()(int row, int col) const; // for const objects
};


#endif /* MATRIX_H */

