/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "learncpp_6arr-ptr-ref.h"

void
sec61_fixedsizearray() {

    /*declaration: length must be compile-time constant. Examples:*/

    // using a literal constant
    int ar1[5]; // Ok

    // using a macro symbolic constant
#define ARRAY_LENGTH 5
    int ar2[ARRAY_LENGTH]; // Syntactically okay, but don't do this

    // using a symbolic constant
    const int arrayLength = 5;
    int ar3[arrayLength]; // Ok

    // using an enumerator

    enum ArrayElements {
        MAX_ARRAY_LENGTH = 5
    };
    int ar4[MAX_ARRAY_LENGTH]; // Ok

//    // using a non-const variable
//    int length;
//    std::cin >> length;
//    int ar5[length]; // Not ok -- length is not a compile-time constant!

//    // using a runtime const variable
//    int temp = 5;
//    const int length = temp;
//    int ar6[length]; // Not ok -- length is a runtime constant, not a compile-time constant!

}

void
BestPractice_IO_handleCinFail() {
    // First, read in valid input from user
    int number = 0;
    do {
        std::cout << "Enter a number between 1 and 9: ";
        std::cin >> number;

        // if the user entered an invalid character
        if (std::cin.fail())
            std::cin.clear(); // reset any error flags

        std::cin.ignore(32767, '\n'); // ignore any extra characters in the input buffer

    } while (number < 1 || number > 9);
}

