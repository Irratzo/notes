/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Felder/Arrays
 * 
 *  Stichworte:
 *      - op[], Zeigerarithmetik
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

int main()
{
    char a[5];      // Platz fuer 5 chars, char-Werte nicht initialisiert!

    // Felder belegen
    a[0] = 'H';
    a[1] = 'u';
    a[2] = 'h';
    a[3] = 'u';
    a[4] = '\0';
	tools_log(); cout << "a=" << a << endl;	
    
    // Ausgabe aller Elemente
    tools_log(); cout << "a={ ";
    for (char c : a)
        cout << "'" << c << "'(" << (int)c << ") ";
    cout << "}" << endl;
    
    // Achtung: Laenge von a ist fix und sizeof gibt Laenge in Bytes
    tools_log(); cout << "a={ ";
    for (size_t i=0; i<sizeof(a)/sizeof(char); ++i)
        cout << "'" << a[i] << "'(" << (int)a[i] << ") ";
    cout << "}" << endl << endl;
   
    // was haben Felder und Zeiger gemeinsam?

    // was passiert hier?
    tools_log(); cout << "a={ ";
    for (char* p=a; *p; ++p)
        cout << "'" << *p << "'(" << (int)*p << ") ";
    cout << "}" << endl << endl;
    
    // jetzt langsam ...
    
    char* p = a;    // p zeigt auf erstes Element
    tools_log(); cout << "a[0]=" << *p << ", ab p:" << p << endl;
    
    p = a+2;        // p zeigt auf drittes Element (0,1,2), Zeigerarithmetik
	tools_log(); cout << "a[0]=" << *p << ", ab p:" << p << endl << endl;

    *p = '\0';      // terminiere C-string mit '\0'
	tools_log(); cout << "a=" << a << endl;
    
    // der Rest des Feldes ist immer noch da
    char* q = &(a[3]);
    tools_log(); cout << "a[3]=" << *q << endl;
 
 
    int b[3];
    b[0] = 10;
    b[1] = 11;
    b[2] = 12;
    int* pb = b;
    tools_log(); cout << "b[2]= " << b[2] << ", pb=" << pb << endl;
    tools_log(); cout << "*pb= " << *pb << ", pb=" << pb << endl;

    //pb -= 2;
    tools_log(); cout << "*pb= " << *pb << ", pb=" << pb << endl;

    char* pc;
    pc = (char*)pb;
    tools_log(); cout << "*pc= " << *pc << ", pc=" << (void*)pc << endl;

    *(pc+1) = 1;
    tools_log(); cout << "b[0]= " << b[0] << ", pb=" << pb << endl;
    
    
    return EXIT_SUCCESS;
}

