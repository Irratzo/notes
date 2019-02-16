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

class C {
public:
    C()    { tools_log(); cout << "ctor C()" << endl; }
    ~C()   { tools_log(); cout << "dtor ~C()" << endl; }

// so-called copy-constructor 
    C(const C & /*c*/)  { 
        tools_log(); cout << "ctor C(C)" << endl; /* copy from c */ 
    }

// so-called copy assignment operator
    C & operator=(const C & /*c*/)  { 
        tools_log(); cout << "op=(C)" << endl; /* copy from c */ 
        return *this; 
    }
};

// understand different cstr and op= calls, and prepare for rule of three:
// Stroustrup: if a class defines one of the following it should probably explicitly 
// define all three: destructor, copy constructor, copy assignment operator

void f(C)     { tools_log(); cout << "in f" << endl; }

void g(C &)   { tools_log(); cout << "in g" << endl; }

void h(C *)   { tools_log(); cout << "in h" << endl; }

C k(C c)      { tools_log(); cout << "in k" << endl; return c; }

int main()
{
    tools_log(); cout << "define C objects" << endl;
    
    C c1;
    C c2 = c1;     // what function is called?
    C c3(c1);
    tools_log(); cout << "done" << endl << endl;
    
    tools_log(); cout << "make some assignements" << endl;
    c2 = c3;
    tools_log(); cout << "done" << endl << endl;

    tools_log(); cout << "call functions f,g,h" << endl;
    f(c1);
    g(c1);
    h(&c1);
    tools_log(); cout << "done" << endl << endl;
    
    tools_log(); cout << "free all" << endl;
    
    return EXIT_SUCCESS;
}

