/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * Simple tutorial on C++ templates
 * Source: https://www.youtube.com/watch?v=W0aoAm6eYSk
 * Videos 58-61
 * 
 * File:   main.cpp
 * Author: johannesw
 *
 * Created on 9. Juli 2017, 17:56
 */

#include <cstdlib>
#include <iostream>
#include "../../tools/tools.h"

using namespace std;

/*================Vid 58 Func Template T=================================*/
template <typename bucky>
bucky addCrap(bucky a, bucky b) {
    return a + b;
}

/*================Vid 59 Func Template U,V=================================*/
template <typename FIRST, typename SECOND>
FIRST addDifferentCrap(FIRST a, SECOND b) {
    return a + b;
}

/*================Vid 60 Class Template=================================*/
template <typename T>
class Bucky {
    T a, b;
public:
    /*Ctor: WRONG*/
    //    Bucky(T inita, T initb) : T(inita), T(initb) {
    //    }

    /*Ctor: CORRECT*/
    Bucky(T inita, T initb) : a(inita), b(initb) {
    }

    /*sample function, compares class init members*/
    T bigger();

};

template <typename T> //MANDATORY firstline for EVERY declaration outside resp. Class!
T Bucky<T>::bigger() { //<T>: MANDATORY!
    return (a > b ? a : b);
}

/*================Vid 61 Tplt Specialization=================================*/
/* class handles all types equally, except char*/
template <typename U>
class Spunky{
    public:
        Spunky (U x){
            cout << x << " is not a char!" << endl;
        }
};

/*specialization: */
template <> //MEANS: empty diamond operator = specialization
class Spunky<char>{ //specialized class definition for char
    public:
        Spunky(char x){
            cout << x << " is a char!" << endl;
        }
};

template <typename T, int N> //note: local T, not the same as the T above
class Spec2 {
    public:
        Spec2(T x){cout << "Spec2 inited with " << x << "and int N=" << N << endl;}
};

///* does not work for me, shell: "Spec3 no class Template"...*/
//template<int N>
//class Spec3<double, N>{
//    public:
//        Spec3(){cout << "Spec3 declared with double and int N = " << N << endl;}
//};

///* does not work for me, shell: "Spec4 no class Template"...*/
//template <typename T>
//class Spec4<T,3>{
//    public:
//        Spec4(T x){cout << "Spec4 inited with " << x << endl;}
//};



void vid58_functionTplt();
void vid59_functionTplt_multipleTypes();
void vid60_classTplt();
void vid61_tpltSpecialization();

/*
 * 
 */
int main(int argc, char** argv) {

    vid58_functionTplt();
    vid59_functionTplt_multipleTypes();
    vid60_classTplt();
    vid61_tpltSpecialization();


    return 0;
}

void vid58_functionTplt() {
    cout << "vid58: -------------------------------" << endl;
    int a = 2, b = 5;
    tools_log(); cout << addCrap(a, b) << endl << endl;
}

void vid59_functionTplt_multipleTypes() {
    cout << "vid59: -------------------------------" << endl;
    double a = 2.5;
    int b = 5;
    tools_log(); cout << addDifferentCrap(a, b) << endl << endl;

}

void vid60_classTplt() {
    cout << "vid60: -------------------------------" << endl;
    Bucky<int> bucky(4,90);
    tools_log(); cout << "bigger: " << bucky.bigger() << endl << endl;
}

void vid61_tpltSpecialization() {
    cout << "vid61: -------------------------------" << endl;
    tools_log(); Spunky<int> sint(5);
    tools_log(); Spunky<char> schar('c');
    tools_log(); Spec2<double,42> spec2(2.1781);
//    tools_log(); Spec3<42> spec3(); //shell: "Spec3 not a class template"
//    tools_log(); Spec4<string> spec3("bla"); //shell: "Spec4 not a class template"
}

