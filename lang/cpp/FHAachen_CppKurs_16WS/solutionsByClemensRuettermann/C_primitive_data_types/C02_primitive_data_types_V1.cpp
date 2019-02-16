/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Primitive Datentypen und ihre jeweilige Groesse.
 * 
 *  Stichworte:
 *      - Datentypen, int, int8_t, size_t, signed, unsigned
 *      - Praeprozessordirektiven, #pragma
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

#pragma GCC diagnostic ignored "-Wuninitialized"

int main()
{   
    // ganzzahlige Typen
    
    int i;      // nicht initialisiert (Zufallswert)!
    tools_log(); cout << "i=" << i << endl;
    i = -1;
    tools_log(); cout << "i=" << i << endl;

    // mit oder ohne Vorzeichen? -> signed oder unsigned

    unsigned int j = 2;    // ohne Vorzeichen
    tools_log(); cout << "j=" << j << endl;

    signed int k = -3;     // mit Vorzeichen
    tools_log(); cout << "k=" << k << endl;
    
    // konstant oder nicht? -> const
    
    const int l = -4;       // als Konstante
    tools_log(); cout << "l=" << l << endl;
    // l = 12;              // Fehler!

    cout << endl;
   
    // wie gross ist 'int' in Bytes? (Achitekturabhaengig)
    tools_log(); cout << "sizeof(int)=" << sizeof(int) << endl;
    tools_log(); cout << "sizeof(i)=" << sizeof(i) << endl;

    cout << endl;
    
    // seit C++11 in cstdint
    int32_t m = -5;
    uint32_t n = 6;
    tools_log(); cout << "m=" << m << ", n=" << n << endl;
    tools_log(); cout << "sizeof(int32_t)=" << sizeof(int32_t) << endl;
    // int8_t, int16_t, int64_t, uint8_t, ... entsprechend

    cout << endl;
    
    // die Groesse ist selbst wieder ein Typ
    size_t sz = sizeof(int32_t);
    tools_log(); cout << "sizeof(size_t)=" << sizeof(sz) << endl;

    return EXIT_SUCCESS;
}

