/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Undefiniertes Verhalten von Ausdruecken
 * 
 *  Stichworte:
 *      - sequencing points
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

#pragma GCC diagnostic ignored "-Wsequence-point"
#pragma GCC diagnostic ignored "-Wunused-value"

int f(int a, int b) { return a+b; }

int main()
{    
    int i,rc;
    
    // Problem?
    i = 1;
    rc = f(++i,++i); 
    tools_log(); cout << "result rc=" << rc << ", i=" << i << endl;

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

    // Problem?
    int Q[3];
    i = 1;
    Q[i] = Q[i++];
        
    return EXIT_SUCCESS;
}

