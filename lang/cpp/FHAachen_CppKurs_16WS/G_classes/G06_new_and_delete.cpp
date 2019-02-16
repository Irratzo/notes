/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Verwendung von dynamischem Speicher mit Klassen
 * 
 *  Stichworte:
 *      - new, delete, class
 */

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "../tools/tools.h"

// a very simple class
class C {
public:
    int n;
    
    C(int N=123) : n(N) { }     // default par.
};

int main()
{
    cout << "size " << sizeof(C) << endl;
    
    int* pn = (int*)malloc( 1*sizeof(int) );    // no init!
    tools_log(); cout << "*pn = " << (*pn) << endl;
    *pn = 42;
    tools_log(); cout << "*pn = " << (*pn) << endl << endl;
        
    // what about pointers to objects?
    C* pc;                                      // an uninitialized ptr
    
    pc = (C*)malloc( 1*sizeof(C) );             // no ctor.call! wrong!!!
    tools_log(); cout << "pc.n = " << (*pc).n << " or pc->n " << pc->n << endl;
    free(pc);
    
    // do not use malloc and free with objects!!!

    pc = new C(23);                             // alloc and ctor-call!
    tools_log(); cout << "pc.n = " << (*pc).n << endl;
    delete pc;
    
    pc = new C[10];                  
    tools_log(); cout << "pc.n = " << pc[0].n << endl;
    // delete does not know whether this is a pointer to a single C or
    // to an array of C's -> but we know, in case of arrays use delete [] 
    delete [] pc;
    
    return EXIT_SUCCESS;
}
