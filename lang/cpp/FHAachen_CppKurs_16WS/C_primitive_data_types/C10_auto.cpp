/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Automatische Datentypenermittlung.
 * 
 *  Stichworte:
 *      - auto
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "../tools/tools.h"

string doppelt(string s)
{
    return s+s;
}

int main()
{   
    // aus dem Literal oder Ergebnistyp kann auf den Datentyp geschlossen werden
        
    auto f = 1.23f;     // float
    auto d = 2.34;      // double
    auto D = 3.45l;     // long double
    
    auto i = -12;       // int
    auto l = -23l;      // long
    auto u =  17;       // unsigned
    
    tools_log(); cout << "f=" << f << ", sizeof=" << sizeof(f) << endl;
    tools_log(); cout << "d=" << d << ", sizeof=" << sizeof(d) << endl;
    tools_log(); cout << "D=" << D << ", sizeof=" << sizeof(D) << endl;
    tools_log(); cout << "i=" << i << ",  sizeof=" << sizeof(i) << endl;
    tools_log(); cout << "l=" << l << ",  sizeof=" << sizeof(l) << endl;
    tools_log(); cout << "u=" << u << ",   sizeof=" << sizeof(u) << endl << endl;

    auto s = doppelt("12345");
    tools_log(); cout << "s=" << s << ", size s=" << s.size() << endl << endl;

    // Initialisierung im Vergleich
#pragma GCC diagnostic ignored "-Wmaybe-uninitialized"
    
    int a0;                 // nicht initialisiert (Zufallswert)
    int a1 = 23;            // init., alter Standard bzw. ueblich
    int a2 {42};            // andere Syntax, zukuenftig vorgeschlagen
    int a3{};               // mit Standardwert, hier (0) init. 
    
    tools_log(); cout << "a0=" << a0 << ", a1=" << a1 << ", a2=" << a2 << ", a3=" << a3 << endl;

    return EXIT_SUCCESS;
}

