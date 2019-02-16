/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema Initialisierung in C++11 !
 * 
 *  Stichworte:
 *      - initializer_list
 */

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

#include "../tools/tools.h"

/* Initialisierung in C++11
 * hier am Beispiel in einer Klasse; funktioniert auch bei lokalen Vars.
 */
class C {
public:
    // default initializers
    int n = 23;             // default value 
    int m {42};             // andere Syntax
    int y,z{};              // y nicht initialisiert, z ist Null (0) 
    int a[3] = { 1,2,3 };   // statt C() : a{1,2,3}
    int b[2] { 11,12 };     // mit oder ohne '='
    int *p = new int[2] { -2,-3 };  // auch fuer dynamische arrays
    
    // wenn explizit angegeben, dann werden diese verwendet
    C() : b{3,4} { }
    ~C() { delete [] p; }
};

/*	initializer lists
 */
class D {
public:
    vector<double> v;
    
    // initializer_list template mit korrektem T
    D(const initializer_list<double>& l) // * Alternative ?
    // : v(l)
    
    {
        // als Beispiel hier manuell
        for (double x: l)
            v.push_back(x);
    }
    
};

int main()
{
    C c;
    tools_log(); cout << "c.n=" << c.n << ", c.m=" << c.m << ", c.y=" << c.y << ", c.z=" << c.z << endl;
    tools_log(); cout << "c.a[2]=" << c.a[2] << ", c.b[1]=" << c.b[1] << endl << endl;
    
    // analog zu: vector<int> v = { 7,8,9 };      
    
    D d = { 1.1, 2.2, 4.4 };        // in eigener Klasse
    tools_log(); cout << "d[0]=" << d.v[0] << ", d[1]=" << d.v[1] << endl;

    return EXIT_SUCCESS;
}

