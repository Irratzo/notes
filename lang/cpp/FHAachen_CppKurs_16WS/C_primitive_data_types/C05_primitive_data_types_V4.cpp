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
    
    //ersma die primitiven char-typen
    char c = 'c';
    tools_log(); printf("A simple char: %c\n",c);
    tools_log(); cout << "sizeof(char)=" << sizeof(char) << endl;
    tools_log(); cout << "sizeof(char16_t)=" << sizeof(char16_t) << endl; //C++11
    tools_log(); cout << "sizeof(char)=" << sizeof(char32_t) << endl; //C++11
    tools_log(); cout << "sizeof(wchar_t)=" << sizeof(wchar_t) << endl; //wide char, size on this machine!
    tools_log(); cout << "sizeof(signed char)=" << sizeof(signed char) << endl << endl;

    // ein Zeiger
    const char* pc = "Lorem ipsum avec la constant du change de la ligne:  '\\n'";
    tools_log(); printf("%s\n",pc);
    tools_log(); cout << pc << endl;
    tools_log(); cout << "sizeof(char*)=" << sizeof(char*) << endl;
    tools_log(); cout << "sizeof(this specific char*)=" << sizeof(pc) << endl << endl;

    // ein Feld
    char ca[] = "Lorem ipsum avec la constant du change de la ligne:  '\\n'";
    tools_log(); printf("%s\n",ca);
    tools_log(); cout << ca << endl;
    tools_log(); cout << "sizeof(this specific char[])=" << sizeof(ca) << endl << endl;
    tools_log(); cout << "Conclusion: sizeof(ca), ca is a char[], returns no. of chars including null-termination, but NOT bit/byte-size!" << endl << endl;

    // als C++-string und C-String im string
    string s = "Lorem ipsum avec la constant du change de la ligne:  '\\n'";
    tools_log(); printf("%s\n",s); //zeigt string so an: "▒"
    tools_log(); printf("%s\n",s.c_str()); //korrekt: umwandlung in char*
    tools_log(); cout << s << endl;
    tools_log(); cout << "sizeof(string)=" << sizeof(string) << endl; // 8
    tools_log(); cout << "sizeof(this specific string)=" << sizeof(s) << endl; // 8
    tools_log(); cout << "no. chars in this specific string: " << s.size() << endl << endl; // 57 == s.length())
    
    return EXIT_SUCCESS;
}

