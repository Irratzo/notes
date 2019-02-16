/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: johannesw
 *
 * Created on 12. Juli 2017, 20:26
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

void ex1402_mostBasicTryCatch();
void ex1402_slightlyBetterTryCatch();
int tryConvertStringToInt(string s);
double tryConvertStringToDouble(string s);

/*
 * 
 */
int main(int argc, char** argv) {
    //    ex1402_mostBasicTryCatch();
    ex1402_slightlyBetterTryCatch();

    return 0;
}

void ex1402_mostBasicTryCatch() {
    try {
        //statements that might throw exceptions
        throw -1; //in this form, always thrown!
    } catch (int x) {
        cerr << "Caught exception with value " << x << endl;
    }
}

void ex1402_slightlyBetterTryCatch() {
    cout << "Enter non-numeric characters to throw exception" << endl;
    try {
        /*Statements that might throw exception:*/
        /*Try converting input to integer*/
        string s;
        cin >> s;
        char* p;
        long converted = strtol(s.c_str(), &p, 10);
        if (*p) {
            // conversion failed because the input wasn't a number
            throw -1;
        } else {
            // use converted
            cout << "Read in number: " << converted << endl;
        }


    }    catch (int x) {
        // Any exceptions of type int thrown within the above try block get sent here
        std::cerr << "We caught an int exception with value: " << x << std::endl;
    }    catch (double) // no variable name since we don't use the exception itself in the catch block below
    {
        // Any exceptions of type double thrown within the above try block get sent here
        std::cerr << "We caught an exception of type double" << std::endl;
    }    catch (const std::string &str) // catch classes by const reference
    {
        // Any exceptions of type std::string thrown within the above try block get sent here
        std::cerr << "We caught an exception of type std::string" << std::endl;
    }
}

