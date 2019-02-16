/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Statische Daten bzw. Variablen in Funktionen
 * 
 *  Stichworte:
 *      - static
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

// if n<0 return function call counter 
int fib(int n) 
{
    static int count = 0;   // variable is initialized and exists only once
    if (n<0)                // this is one way to read its value 
        return count;
    
    ++count;                // count calls
    
    return (1<n) ? fib(n-2)+fib(n-1) : n;
}


int main()
{
    tools_log(); cout << "fib 10: " << fib(10) << endl;
    tools_log(); cout << "count:  " << fib(-1) << endl;

    return EXIT_SUCCESS;
}

