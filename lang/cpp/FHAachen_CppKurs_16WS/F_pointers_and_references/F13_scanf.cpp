/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Vorstellen der C-Methode, um Daten einzulesen
 * 
 *  Stichworte:
 *      - scanf
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

int main()
{
	int  n;
	
	tools_log(); cout << "Bitte Zahlen nacheinander eingeben (beenden mit -1): ";
    // scanf gibt die Anzahl eingegebener Args zurueck
	while (scanf("%d", &n)>0 && n>0)
    {
		tools_log(); cout << "verstanden n=" << n << ", weitere Zahl: ";
    }
    cout << endl;
		
	char a[5];
    
	tools_log(); cout << "Bitte Text eingeben (Laenge <5): ";
    // scanf ist anfaellig fuer format string Attacken, 
    // daher immer die max. Laenge angeben!
	scanf("%4s",a);				
	tools_log(); cout << "verstanden a=" << a << endl;

    return EXIT_SUCCESS;
}

