/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Aufruf einer Funktion, undefiniertes Auswertungsreihenfolge
 * 
 *  Stichworte:
 *      - Funktionsaufruf, call by value, Rekursion
 *      - Funktionsdeklaration, Signatur
 *      - sequencing points
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

// Deklaration, wofuer?
int faculty(int n);
int f(int a, int b);

int main()
{
    // call faculty 0! .. 4!
    for (int i=0; i<=4; ++i)
    {
        int f = faculty(i);
        tools_log(); cout << i << "!=" << f << endl;
    }

    cout << endl;
    
#pragma GCC diagnostic ignored "-Wsequence-point"
    // Problem?
    int i = 1;
    int rc = f(++i,++i); 
    tools_log(); cout << "result rc=" << rc << ", i=" << i << endl;

    return EXIT_SUCCESS;
}

// calc n!
int faculty(int n)
{
    cout << endl;
    tools_log(); cout << "param  n=" << n << endl;
    
    int f = 1;
    while (n>1)
    {
        f *= (n--);
    }

    tools_log(); cout << "Ergebnis f=" << f << endl;
    return f;
}

int f(int a, int b) { return a+b; }
