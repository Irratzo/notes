/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	die Regel der Drei: copy-ctor, copy assignment op (=), dtor
 * 
 *  Stichworte:
 *      - rule of three
 */

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "../tools/tools.h"

#pragma GCC diagnostic ignored "-Wunused-parameter"

class C {
public:
	int n;
	
    C(int _n=0) : n(_n)    { tools_log(); cout << "ctor C() n=" << n << endl; }
    ~C()   { tools_log(); cout << "dtor ~C() n=" << n << endl; }

// so-called copy-constructor 
    C(const C & c)  { 
		n = c.n;
        tools_log(); cout << "ctor C(C) n=" << n << endl; /* copy from c */ 
    }

// so-called copy assignment operator
    C & operator=(const C & c)  { 
        tools_log(); cout << "op=(C) old-n=" << n << " new-n=" << c.n << endl; /* copy from c */ 
		n = c.n;
        return *this; 
    }
};

void f(C c1, C c2) {
}

int main()
{
    tools_log(); cout << "define C objects" << endl;
    
    C c1(1);
    C c2 = c1;     // what function is called?
    C c3(c1);
    tools_log(); cout << "done" << endl << endl;
   
    c1.n = 1;
    c2.n = 2;
    c3.n = 3;
    tools_log(); cout << "case 1" << endl;
    c3 = c2 = c1;
    tools_log(); cout << "done" << endl << endl;

    c1.n = 1;
    c2.n = 2;
    c3.n = 3;
    tools_log(); cout << "case 2" << endl;
    c3.operator=(c2.operator=(c1));
    tools_log(); cout << "done" << endl << endl;

    c1.n = 1;
    c2.n = 2;
    c3.n = 3;
    tools_log(); cout << "case 3" << endl;
    f(c1,c2);
    tools_log(); cout << "done" << endl << endl;

    tools_log(); cout << "free all" << endl;
    
    return EXIT_SUCCESS;
}

