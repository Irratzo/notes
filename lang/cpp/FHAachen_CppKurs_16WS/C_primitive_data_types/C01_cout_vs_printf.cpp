/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Erste primitive Datentypen und Ausgabe via printf und cout.
 * 
 *  Stichworte:
 *      - printf, Formatstring, %d, %c
 *      - Datentypen, char,  int
 *      - cast
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "../tools/tools.h"

int main()
{
    tools_log(); printf("einfacher Text: \n");

    // einfacher Text mit printf (C)
    printf("\n");
    printf("     1 \n");
    printf("    1 1 \n");
    printf("   1 2 1 \n");
    printf("  1 3 3 1 \n");
    printf(" 1 4 6 4 1 \n");
    printf("\n");

    // simple text
    tools_log(); printf("sample text with new line constant -> '\\n' \n");
    tools_log(); printf("sample text "); printf("with new line constant -> '\\n' \n");

    tools_log(); cout << "sample text with new line constant -> '\\n'" << endl;
    tools_log(); cout << "sample text "; cout << "with new line constant -> '\\n'" << endl;

    // printf benutzt Platzhalter im Formatstring
    // einzelne Zeichen; Typ '%c' im Formatstring ist wichtig, danach die Argumente
    char c = 'A';
    tools_log(); printf("c=%c \n", c);        // C-Variante
    tools_log(); cout << "c=" << c << endl;   // C++-Variante

    // jetzt ganze Zahlen; Typ ist '%d'
    int k = 66;
    tools_log(); printf("k=%d \n",k);
    tools_log(); cout << "k=" << k << endl;
    
    // jetzt kombiniert
    tools_log(); printf("c=%c, k=%c, c=%d, k=%d \n",c,k,c,k);
    tools_log(); cout << "c=" << c << ", k=" << (char)k 
                      << ", c=" << (int)c << ", k=" << k << endl;
                      
    return EXIT_SUCCESS;
}

