/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Verwendung von Classen
 * 
 *  Stichworte:
 *      - class ctor, dtor, copy-ctor
 */

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "../tools/tools.h"

class C {           // from here all private
    int n;
    
public:             // from here all public, use public, protected, private as required

    // default ctor with member init.
    C() : n(12)  { tools_log(); cout << "ctor C() n=" << n << endl; }

    // ctor with one argument
    C(int N) : n(N) { tools_log(); cout << "ctor C(int) n=" << n << endl; }

    // copy-ctor
    C(const C & c) : n(c.n) { tools_log(); cout << "ctor copy C(int) n=" << n << endl; }

    C& operator=(const C & c) { tools_log(); n=c.n; 
        cout << "op= n=" << this->n << endl; 
        return *this; } 
        
    // dtor    
    ~C()            { tools_log(); cout << "dtor ~C() n=" << n << endl; }
};

int f();

int main()
{
    C c1;     // -> init with n=0
    C c2(42);   // -> init with n=42
    C c3(c2);   // -> init with c2.n
    C c4=c3;    // -> init with c3.n
    
    tools_log(); cout << "start" << endl;

    c3=c4;

/*    if (true) {
        tools_log(); cout << "  in if" << endl;
        C c(23);
    }*/
    

    tools_log(); cout << "ende" << endl;
        
    return EXIT_SUCCESS;
}

