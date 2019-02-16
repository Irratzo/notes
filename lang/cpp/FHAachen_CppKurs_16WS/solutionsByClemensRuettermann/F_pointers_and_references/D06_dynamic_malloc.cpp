/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Dynamischen Speicher anfordern, nach alter C-Variante
 * 
 *  Stichworte:
 *      - malloc, free
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

int main()
{
    tools_log(); cout << "fib 1 ... fib n, bitte n eingeben (n>2): ";
    
    size_t n;
    cin >> n;
    cout << endl;

    // ggf Abbruch
    if (n<=2)
        return EXIT_FAILURE;
    
    // hier werden n*sizeof(int) Bytes reserviert
    // malloc/free sind C !!! fuer C++ bitte new/delete benutzen
    int* a = (int*)malloc( n*sizeof(int) );
    
    tools_log(); cout << "Adr.a=" << a << ", Adr.n" << &n << endl << endl;
    
    // Fibonacci Werte berechnen
    a[0] = a[1] = 1;
    for (size_t i=2; i<n; ++i)  // was passiert bei '<=n'?
    {
        a[i] = a[i-2]+a[i-1];
    }

    for (size_t i=0; i<n; ++i)
    {
        tools_log(); cout << "fib " << i+1 << "=a[" << i << "]=" << a[i] << endl;	
    }
    
    // Speicher wieder freigeben!!!
    free(a);

    return EXIT_SUCCESS;
}

