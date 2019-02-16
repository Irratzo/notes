/*
 * Examples for operatorOverloading mainly from LearnCpp.com
 */

/* 
 * File:   main.cpp
 * Author: johannesw
 *
 * Created on 11. Juli 2017, 13:22
 */

#include <cstdlib>
#include <iostream>

#include "Matrix.h" //for 09.09
#include "Fraction0915_1.h" //for 09.15

using namespace std;

void ex0909_overloadParenthesis_matrixElmAccess();
void ex0915_overloadAssiAndIOS_Fraction();
/*
 * 
 */
int main(int argc, char** argv) {
    
    cout << endl << "-------Example 9.9: Overload ParenthesisOp () for Matrix Elm Access -------" << endl;
    ex0909_overloadParenthesis_matrixElmAccess();
    
    cout << endl << "-------Example 9.9: Overload ParenthesisOp () for Matrix Elm Access -------" << endl;
    ex0915_overloadAssiAndIOS_Fraction();


    return 0;
}


void ex0909_overloadParenthesis_matrixElmAccess(){
    Matrix matrix;
    matrix(1, 2) = 4.5;
    std::cout << matrix(1, 2);
}

void ex0915_overloadAssiAndIOS_Fraction(){
    Fraction f = 6;
    /*6 -> Fraction(6,1) -> CCtor copy that anonymous obj to new object f (copyInit), called by assignmentOp*/
    cout << f << endl;
    cout << Fraction(f) << endl; //CCtor copy f to new anonymous object (copyInit), called directly
}
