/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Verwendung eigener Typdefinitionen
 * 
 *  Stichworte:
 *      - typedef
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

// hier wird der float-Typ definiert, mit dem das Programm arbeiten soll
typedef double float_t;

// in C findet man haeufig diese Form, da in altem C 
// 'struct telnr' geschrieben werden musste
typedef struct telnr_tag {
    int PreSel;
    int Number;
} telnr_t;

int main()
{
    float_t f1 = 1.23, f2 = 3.45;
    tools_log(); cout << "f1=" << f1 << ", f2=" << f2 << endl;
    
    telnr_t t = { 241, 80232 };
    tools_log(); cout << "t={" << t.PreSel << "," << t.Number << "}" << endl;
    
    return EXIT_SUCCESS;
}

