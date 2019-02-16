/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Zeiger oder Referenzen auf lokale Variablen.
 * 
 *  Stichworte:
 *      - local pointer, local references
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

#pragma GCC diagnostic ignored "-Wreturn-local-addr"

unsigned int* calc_cross(unsigned int n);
unsigned long& calc_cross(unsigned long n);

int main()
{
    // berechne die Quersumme und lese den Wert jewiels direkt aus
    unsigned int* p1 = calc_cross(123u);
    unsigned int  s1 = *p1;
    tools_log(); cout << "s1=" << s1 << ", *p1=" << *p1 << endl;

    // gleiches mit Referenzen
    unsigned long& r2 = calc_cross(456ul);
    unsigned long s2 = r2;
    calc_cross(789ul);
    tools_log(); cout << "s2=" << s2 << ", r2=" << r2 << endl;
    
    // was passiert?

    return EXIT_SUCCESS;
}

unsigned int* calc_cross(unsigned int n)
{

    tools_log(); cout << "qs(" << n << ")=";
    unsigned int s=0;
    while (n)
    {
        s += (n % 10);
        n /= 10;
    }
    cout << s << endl;
    
    return &s;
}

unsigned long& calc_cross(unsigned long n)
{
    unsigned int* pi = calc_cross((unsigned int)n);
    unsigned long s = *pi;
    return s;
}
