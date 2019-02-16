/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Felder/Arrays
 * 
 *  Stichworte:
 *      - op[]
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

void output(double D[], size_t len)
{
    tools_log(); cout << "sizeof(D)=" << sizeof(D) << endl; //1*8 = 8 bytes, nicht 40, da D[] copy-by-ref!
    tools_log(); cout << "D={ ";
    for (size_t i=0; i<len; ++i)
        cout << D[i] << " ";
    cout << "}" << endl << endl;
}

int main()
{
    char a[5];      // Platz fuer 5 chars, char-Werte nicht initialisiert!

    // Felder belegen
    a[0] = 'H';
    a[1] = 'u';
    a[2] = 'h';
    a[3] = 'u';
    a[4] = '\0';
    
	tools_log(); cout << "a=" << a << endl;	
    
    // Ausgabe aller Elemente
    tools_log(); cout << "a={ ";
    for (char c : a)
        cout << "'" << c << "'(" << (int)c << ") ";
    cout << "}" << endl;
    
    // Achtung: Laenge von a ist fix und sizeof gibt Laenge in Bytes
    tools_log(); cout << "a={ ";
    for (size_t i=0; i<sizeof(a)/sizeof(char); ++i)
        cout << "'" << a[i] << "'(" << (int)a[i] << ") ";
    cout << "}" << endl << endl;
   
    double d[5];
    d[0] = 1.1;
    d[1] = 2.2;
    d[100] = 3.3;
    //for (int i=0; i<6; ++i)
    //    d[i]=42.0;
    tools_log(); cout << "sizeof(d)=" << sizeof(d) << endl; //5*8 = 40 bytes
    tools_log(); cout << "d={ ";
    for (size_t i=0; i<sizeof(d)/sizeof(double); ++i)
        cout << d[i] << " ";
    cout << "}" << endl << endl;

    output(d,3);
    
    // best practise
    const size_t e_len = 3;
    float e[e_len];
    e[1]=1.2f; // etc.
    tools_log(); cout << "e={ ";
    for (auto x : e)
        cout << x << " ";
    cout << "}" << endl;
       
    return EXIT_SUCCESS;
}

