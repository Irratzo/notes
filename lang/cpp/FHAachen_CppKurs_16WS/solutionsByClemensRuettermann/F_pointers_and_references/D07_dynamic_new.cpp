/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Dynamischen Speicher anfordern, nach neuer C++-Variante
 * 
 *  Stichworte:
 *      - new, delete
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
    
    // hier werden n*int reserviert (array! siehe delete)
    int* a = new int[n];
    
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
    cout << endl;
    
    // Speicher wieder freigeben!!!
    delete [] a;
    
    // es ist auch mgl, nur ein Element zu reservieren
    double* pd = new double;
    *pd = 3.14;
    tools_log(); cout << "*pd=" << *pd << endl;
    delete pd;
    
    // wo liegt der Vorteil new vs. malloc?

    return EXIT_SUCCESS;
}

