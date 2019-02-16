/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	if-Kontrollstruktur
 * 
 *  Stichworte:
 *      - if
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

#pragma GCC diagnostic ignored "-Wparentheses"
#pragma GCC diagnostic ignored "-Wempty-body"

int main()
{
	int n = 1;
	
	// print value of n to std-out
    tools_log(); cout << "n=" << n << endl;

    // "compare"
	if (n=2)       
    {
        tools_log(); cout << "n=2? true, n=" << n << endl;
	} 
    else 
    {
        tools_log(); cout << "n=2? false, n=" << n << endl;
    }

	// oops, try again 
	
    // compare!
	if (n==3) 
    {
        tools_log(); cout << "n=3? true, n=" << n << endl;
	} 
    else 
    {
        tools_log(); cout << "n=3? false, n=" << n << endl;
    }
	

	// Abhilfe: immer den konstanten Ausdruck zu Beginn
	if (4==n)
		;
	
    // vgl. boolsche Ausdruecke (und Java)
	if (n>1 && n<4)
		;

    // Test auf 0
	if (n) 
    {
        tools_log(); cout << "n!=0? true, n=" << n << endl;
    }
	
	// Test mit not-Operator '!' 
	n = 0;
    tools_log(); printf("current value of n: %d \n", n);	
	if (!n) 
    {
        tools_log(); cout << "(!n)!=0? true, n=" << n << ", !n=" << !n << endl;
    }
	
    // was passiert?
	if ( n=3*4+5 > 0 )
	{
        tools_log(); cout << "n=" << n << endl;
	}

	// so geht's richtig
	if ( (n=3*4+5) > 0 )
	{
        tools_log(); cout << "n=" << n << endl;
	}

    return EXIT_SUCCESS;
}

