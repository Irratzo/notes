/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Uebliche Operationen und ndefiniertes Verhalten von Ausdruecken.
 * 
 *  Stichworte:
 *      - Operationen
 *      - sequencing points
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

int main()
{
    bool b = true;
    char c = 'A';
    int n = 66, m = 67;
    tools_log(); cout << "b=" << b << ", c=" << c << ", n=" << n << ", m=" << m << endl;
    
    // Beispiele fuer boolsche Ops
    b = !b;
    b = (c=='A');
    b = (n>0) && (n<100);
    
    // Beispiele fuer int-Ops
    c++;
    c = '0'+1;
    n = n+1;
    ++n;
    n++;
    n += 1;
    n = 1+2+3;  // n = (1+2)+3      von links
    n = m = 68; // n = (m = 68)     von rechts
    n = 1 | 8;
    m = n & 3;
    tools_log(); cout << "b=" << b << ", c=" << c << ", n=" << n << ", m=" << m << endl;
    
    // das geht auch
    n=1,m=2;
    tools_log(); cout << "n=" << n << ", m=" << m << endl << endl;

    // es folgen nun ein paar unerlaubte Ausdruecke; Hintergruende findet man
    // unter dem Stichwort "sequence point"

#pragma GCC diagnostic ignored "-Wsequence-point"
#pragma GCC diagnostic ignored "-Wunused-value"
    
    int i,rc;
    
    // Problem?
    i = 1;
    rc = ++i + ++i;
    tools_log(); cout << "result rc=" << rc << ", i=" << i << endl;

    // Problem?
    i = 1;
    i = ++i + 1;
    tools_log(); cout << "result i=" << i << endl;
    i = 1;
    i = i++ + 1;
    tools_log(); cout << "result i=" << i << endl;

    // Problem?
    i = 1;
    rc= 32,++i,i++;
    tools_log(); cout << "result rc=" << rc << ", i=" << i << endl;
    
    // Problem?
    i = 1;
    rc = (32,++i,i++);
    tools_log(); cout << "result rc=" << rc << ", i=" << i << endl;

    // Problem?
    i = 1;
    rc = (++i>2) || (i++<2);
    tools_log(); cout << "result rc=" << rc << ", i=" << i << endl;
   
    return EXIT_SUCCESS;
}

