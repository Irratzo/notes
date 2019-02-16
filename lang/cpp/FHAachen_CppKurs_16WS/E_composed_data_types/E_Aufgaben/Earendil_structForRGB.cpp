/*
 * FH Aachen Cpp 16WS
 * Aufgabe Duilin
 * Autor: Johannes Wasmer
 * Datum: 06.07.2017
 * 
 * Aufgabe: Implementieren Sie eine Struktur, die die Farbwerte eines Pixels be-
schreibt:
 * • Der struct enthält Farbwerte R,G,B sowie einen Alpha-Wert, jeweils
aus dem Bereich 0..255.
 * • Geben Sie die Größe Ihres structs in bytes aus.
 * 
 * 
 * Themen: struct
 */

#if defined(_WIN32) || (defined(__APPLE__) && defined(__MACH__))
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional> //for Lambdas
#include <memory>
#include <type_traits>
#include <initializer_list> //for AutoDeclType
#else
#include <bits/stdc++.h>
#endif

using namespace std;

typedef struct RGBAlpha_Cpp98 {
    uint8_t R; //byte-size: 1
    uint8_t G; //uint8_t range: [0,255]
    uint8_t B;
    uint8_t Alpha;
} rgba98;

typedef struct RGBA_Cpp14 {
    uint8_t R = 255; //now possible: default values!
    uint8_t G = 255;
    uint8_t B = 255;
} rgba14;

void testCxx98();
void testCxx11();
void testCxx14();

int main() {

    testCxx98();
    testCxx11();
    testCxx14();



    return 0;
}

/*
 * In Cxx14, default values for structs und uniform init can be used together.
 * 
 * Source: http://www.learncpp.com/cpp-tutorial/47-structs/
 */
void testCxx14() {
    rgba14 col; //has default values: white
    rgba14 col2 = {100, 100, 100, 0}; //uniform init: grey
    
    //re-assignment works like in Cxx11
}

/*
 * In Cxx11, have to decide: either use uniform init and have no 
 * default values (for structs), or use default values but don't use uniform init.
 * 
 * Both together cannot be used in Cxx11.
 * 
 * Source: http://www.learncpp.com/cpp-tutorial/47-structs/
 */
void testCxx11() {
    
    rgba98 col98;
    
//reassignment works with uniform init, though!
    
}

/*
 * Cxx98 does not allow structs to have default values.
 */
void testCxx98() {
    rgba98 s; //C98

    s.R = 65;
    s.G = 128;
    s.B = 230;
    s.Alpha = 50;

    cout << "RGBAlpha struct values: ";
    printf("R=%zu, G=%zu, B=%zu, Alpha=%zu\n", s.R, s.G, s.B, s.Alpha);
    cout << "byte-size of RGBAlpha struct member: " << sizeof (s.R) << endl;
    cout << "byte-size of RGBAlpha struct: " << sizeof (s) << endl << endl;

    cout << "What happens if we set values outside type-range?" << endl;
    cout << "Set R=260, G=-1." << endl;
    s.R = 260;
    s.G = -1;

    cout << "RGBAlpha struct values now: ";
    printf("R=%zu, G=%zu, B=%zu, Alpha=%zu\n", s.R, s.G, s.B, s.Alpha);
    cout << "Note: Result is the set value modulo the size type + 1 (256)" << endl << endl;


    cout << "Test: iteratively assign 0..-50 values to uint8_t variable:" << endl;
    uint8_t it = 0;
    cout << it << endl;
    for (int i = 0; i>-50; i--) {
        it = i;
        printf("%zu ", it);
    }
    cout << endl << endl;

    cout << "Note: cout does not work directly with uint8_t!" << endl;
    cout << "For comparison, here is the same loop again, this time using cout:" << endl;
    cout << it << endl;
    for (int i = 0; i>-50; i--) {
        it = i;
        cout << it << " ";
    }
    cout << endl << endl;
}

