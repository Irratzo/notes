/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Zeichen-Datentypen und ihre jeweilige "Groesse".
 * 
 *  Stichworte:
 *      - Datentypen, char, char*, char[], string, C-String
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "../tools/tools.h"

int main()
{   
    // C-Strings und Zeiger
    
    // als C++-string und C-String im string
    string s = "sample text with new line constant -> '\\n'";
    tools_log(); printf("%s\n",s.c_str());
    tools_log(); cout << s << endl;
    tools_log(); cout << "sizeof(string)=" << sizeof(string) << endl;

    // ein Zeiger
    const char* pc = "sample text with new line constant -> '\\n'";
    tools_log(); printf("%s\n",pc);
    tools_log(); cout << pc << endl;
    tools_log(); cout << "sizeof(char*)=" << sizeof(char*) << endl;

    // ein Feld
    char ca[] = "sample text with new line constant -> '\\n'";
    tools_log(); printf("%s\n",ca);
    tools_log(); cout << ca << endl;
    tools_log(); cout << "sizeof(char[])=" << sizeof(ca) << endl;

    // nochmal als Feld, Laenge?
    char a[] = "12345";
    tools_log(); cout << "sizeof(char[])=" << sizeof(a) << endl;
    
    return EXIT_SUCCESS;
}

