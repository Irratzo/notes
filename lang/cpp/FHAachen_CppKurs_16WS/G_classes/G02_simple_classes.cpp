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
    C() : n(0)      { tools_log(); cout << "ctor C() n=" << n << endl; }

    // ctor with one argument
    C(int N) : n(N) { tools_log(); cout << "ctor C(int) n=" << n << endl; }

    // copy-ctor
    C(const C & c) : n(c.n) { tools_log(); cout << "ctor copy C(int) n=" << n << endl; }

    // dtor    
    ~C()            { tools_log(); cout << "dtor ~C() n=" << n << endl; }

    // a getter method
    int getn() { return n; }        

    // a friend function is no part of the class
    friend std::ostream & operator<<(std::ostream & os, const C  & c ) {
        os << c.n;                  // a friend can access private members!
        return os;
    }
};

// see ctors and dtors
void output(C c) { tools_log(); cout << "c = " << c << endl; }

int main()
{
    C c1;       // -> init with n=0
    /*
    C c2(42);   // -> init with n=42
        
    // call a member function
    tools_log(); cout << "c1.n = " << c1.getn() << " c2.n = " << c2.getn() << endl;
    // or call the op<<
    tools_log(); cout << "c1.n = " << c1 << " c2.n = " << c2 << endl << endl;
        
    // note: there is no garbage collection, ctor and dtor are called
    tools_log(); cout << "define C objects in a loop" << endl;
    for (int i=1; i<3; ++i)
    {
        tools_log(); cout << "  i=" << i << endl;
        C c(i);     // here object is born
    }               // and here it dies
    tools_log(); cout << "end of loop" << endl << endl;
*/    
    tools_log(); cout << "call output before" << endl;
    output(c1);
    // why a dtor call ... ???
    tools_log(); cout << "call output after" << endl << endl;
    
    tools_log(); cout << "free all, note dtor output in reverse order" << endl;

    return EXIT_SUCCESS;
}

