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
    char c = 'A'; //65
    int n = 66, m = 67;
    tools_log(); cout << "bool b=" << b << ",char c=" << c << ",int n=" << n << ",int m=" << m << endl;
    
    // Beispiele fuer boolsche Ops
    tools_log(); cout << "b == !b: " << (b == !b) << endl;
    tools_log(); cout << "(c=='A'): " << (c=='A') << endl;
    tools_log(); cout << "(n>0) && (n<100): " << ((n>0) && (n<100)) << endl << endl;
    
    // Beispiele fuer int-Ops
    //in Kommentaren: gdb -tui > 'print c' / print n - Outputs
    // NACH gdb command 'step' AUF der entspr. linie (dh VOR Execution)
    c++; // 66 'A'
    c = '0'+1; // 49 '1' (note: '0' has ASCII value 48)
    n = n+1; //67
    ++n; //68
    n++; //69
    n += 1;//70
    n = 1+2+3;  // n = (1+2)+3      von links  // gdb: n = 6
    n = m = 68; // n = (m = 68)     von rechts // gdb: n = 68
    n = 1 | 8; //9
    m = n & 3; //1
    tools_log(); cout << "b=" << b << ", c=" << c << ", n=" << n << ", m=" << m << endl;
    
    // das geht auch: kommatrennung
    n=1,m=2;
    tools_log(); cout << "n=" << n << ", m=" << m << endl << endl;
    
    //int ii=(n=1,n=2);
    //cout << "ii=" << ii << endl;

    // es folgen nun ein paar unerlaubte Ausdruecke; Hintergruende findet man
    // unter dem Stichwort "sequence point"

//#pragma GCC diagnostic ignored "-Wsequence-point"
//#pragma GCC diagnostic ignored "-Wunused-value"
    
    int i,rc;
    
    // Problem? JW: Nein.
    i = 1;
    rc = ++i + ++i; //3+3 = 6, i=3 ist doch nachvollziehbar!
    tools_log(); cout << "result rc=" << rc << ", i=" << i << endl;

    //Zum Vergleich:
    i = 1;
    rc = i++ + i++; //1+1=2, i=3
    tools_log(); cout << "result rc=" << rc << ", i=" << i << endl;

    // Problem? JW: Nein.
    i = 1;
    i = ++i + 1; //3, ist doch nachvollziehbar!
    tools_log(); cout << "result i=" << i << endl;
    i = 1;
    i = i++ + 1; //2, ist doch nachvollziehbar!
    tools_log(); cout << "result i=" << i << endl;

    // Problem? JW: Nein.
    i = 1;
    rc= 32,++i,i++; //rc=32, i=3, ist doch nachvollziehbar!
    tools_log(); cout << "result rc=" << rc << ", i=" << i << endl;
    
    // Problem? JW: Ja!
    i = 1;
    rc = (32,++i,i++); //rc=2, i=3, ersteres ist für mich nicht nachvollziehbar..
    tools_log(); cout << "result rc=" << rc << ", i=" << i << endl;

    // Problem? JW: Nein.
    i = 1;
    rc = (++i>2) || (i++<2); // rc=0, i=3, ist doch nachvollziehbar (0 || 0)!
    //(bei beiden vergleichen ist i=2)
    tools_log(); cout << "result rc=" << rc << ", i=" << i << endl;
   
    return EXIT_SUCCESS;
}

