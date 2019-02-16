/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	switch-Kontrollstruktur
 * 
 *  Stichworte:
 *      - switch, case, break, default, fall through
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

int main()
{
	// case Struktur, gueltig fuer int-Werte
    
	int n = 3;
	switch(n)
	{
	case 3: // Achtung, break fehlt
        tools_log(); cout << "case 3, n=" << n << endl;
	case 4:
        tools_log(); cout << "case 4, n=" << n << endl;
		break;
	}
    
    char c = 'A';
	switch(c)
	{
	case 'a':
        tools_log(); cout << "case 'a', c=" << c << endl;
		break;
	default:
        tools_log(); cout << "case default, c=" << c << endl;
	}

    return EXIT_SUCCESS;
}

