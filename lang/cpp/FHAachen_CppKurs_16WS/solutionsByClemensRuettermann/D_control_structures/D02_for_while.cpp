/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	for- und while-Kontrollstruktur
 * 
 *  Stichworte:
 *      - for, while, continue, break
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

int main()
{
	int i,sum;
    const int min = 0, max = 5;
	
	// einfache Schleife von 0 bis inkl. 5 
	for (i=min,sum=0; i<=max; ++i)
	{
		sum += i;
	}
    tools_log(); cout << "einfach: sum " << min << ".." << max << " = " << sum 
                      << "  (i=" << i << ")" << endl;

	// einfache Schleife von -2*max bis 2*max -> continue und break
	for (i=-2*max,sum=0; i<=2*max; ++i)
    {
        if (i<min)
            continue;
        if (i>max)
            break;
        sum += i;
    }
		;
    tools_log(); cout << "zu lang: sum " << min << ".." << max << " = " << sum 
                      << "  (i=" << i << ")" << endl;

	// kurze Version
	for (i=min,sum=0; ++i<=max; sum+=i)
		;
    tools_log(); cout << "kurz:    sum " << min << ".." << max << " = " << sum 
                      << "  (i=" << i << ")" << endl;

	// verschiedene Versionen
	i = min;
    sum = 0;
	while (i<=5)
	{
		sum += i;
		++i;
	}
    tools_log(); cout << "while:   sum " << min << ".." << max << " = " << sum 
                      << "  (i=" << i << ")" << endl;

	// noch eine Variante
	i = min;
    sum = 0;
	do {
		sum+=i;
	} while (++i<=5);
    tools_log(); cout << "do while:sum " << min << ".." << max << " = " << sum 
                      << "  (i=" << i << ")" << endl;

	// was auch geht ... bitte wieder schnell vergessen 
    i = min;
    sum = 0;
label:
    sum+=i;
	if ( ++i<=max)
		goto label;
    tools_log(); cout << "goto:    sum " << min << ".." << max << " = " << sum 
                      << "  (i=" << i << ")" << endl;

    cout << endl;
    
    // geschachtelte Schleifen
    tools_log(); printf("for geschachtelt:\n");
	for (i=min; i<max; ++i)
	{
        tools_log(); 
		for (int j=i; j<max; ++j)
			printf(" %u",j);
		printf("\n");
	}

    return EXIT_SUCCESS;
}

