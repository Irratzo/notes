/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Typumwandlungen 
 * 
 *  Stichworte:
 *      - cast, static_cast, cmath, round, lround
 */

#include <iostream>
#include <cmath>
using namespace std;

#include "../tools/tools.h"

int main() {
    
    //#pragma GCC diagnostic ignored "-Wconversion"
    // Das GCC-pragma hier unterdrückt Compiler-Warnungen des aktivierten Compiler-Flags "-Wconversion"
    // wirkt file-lokal (glaub?)
    
    char c = 'A';
    int n = 66;
    unsigned int u = 97;

    tools_log();
    cout << "c=" << c << ", n=" << n << endl;

    // Umwandlungen hier ohne weitere Massnahmen moeglich
    c = 67;
    n = 'D';
    tools_log();
    cout << "c=" << c << ", n=" << n << endl;

    c = u; // warning: conversion to 'char' from 'unsigned int' may alter its value [-Wconversion]
    n = u; // keine Warnung
    tools_log();
    cout << "c=" << c << ", n=" << n << endl;

    // folgende aequivalente Moeglichkeiten zum expliziten cast ohne Warnung
    c = (char) u;
    c = char(u);
    c = static_cast<char> (u);

    cout << endl;

    double d = 3.1415;
    float f = 2.71f;

    tools_log();
    cout << "f=" << f << ", d=" << d << endl;

    //#pragma GCC diagnostic ignored "-Wfloat-conversion"
    f = d; // warning: conversion to 'float' from 'double' may alter its value [-Wfloat-conversion]
    f = (float) d;
    f = float(d);
    f = static_cast<float> (d);

    cout << endl;

    //implizites double-to-int-Casting schneidet ab (floor):
    d = 1.9999;
    n = d; // warning: conversion to 'int' from 'double' may alter its value [-Wfloat-conversion]
    tools_log();
    cout << "n=" << n << endl;

    // korrekter Weg seit C++11: nimmt ceiling oder floor
    n = (int) lround(d); //einfach nur lround(d) reicht auch
    tools_log();
    cout << "n=" << n << endl;

    //Lehre hier: n=d rundet 1.999 auf 1, lround(1.999) rundet auf 2.

    return EXIT_SUCCESS;
}

