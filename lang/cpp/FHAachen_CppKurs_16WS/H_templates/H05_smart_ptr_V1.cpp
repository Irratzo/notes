/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema smart Pointers, unique_ptr
 */

// valgrind --tool=memcheck ./H05_smart_ptr_V1.out

#include <iostream>
#include <memory>
#include <cstdlib>
#include <vector>
using namespace std;

#include "../tools/tools.h"

class C {
public:
    int n;
    
    C(int N=0) : n(N) { 
        tools_log(); cout << "ctor(N) " << n << endl; 
    }
    C(const C& c) : n(c.n) { 
        tools_log(); cout << "ctor(C) " << n << endl; 
    }
    ~C() { 
        tools_log(); cout << "dtor " << n << endl; 
    }
    
    friend ostream & operator<<(ostream & os, const C & c) { 
        os << c.n; return os; 
    }
};

// some factory function
C * createC(int n) { return new C(n); }

int main() 
{
    tools_log(); cout << "some operations (1)..." << endl;
	// warum smart-Pointer ?
    {
        C* p = createC(2);
        tools_log(); cout << "*p=" << *p << endl;
        //... wirklich kompliziertes zeug...
        delete p;
    }
    //return 0;

    tools_log(); cout << "some operations (2)..." << endl;
    {
        unique_ptr<C> p1(createC(4));   // p1 gehoert (owns) das C-object
        unique_ptr<C> p2;				// p2 ist noch leer
     
     /* besser:
      *     make_unique ... siehe make_shared
      * erst ab C14, Zitat Herb Sutter, chair of the C++ standardization committee:
      *     That C++11 doesn’t include make_unique is partly an oversight, 
      *     and it will almost certainly be added in the future.
      */
   
        // Dereferenzierung nur fuer p1, nicht fuer p2!
        tools_log(); cout << "p1=" << (*p1) << " &p1:" << p1.get() << endl;
        tools_log(); cout << "p2=" << "-"   << " &p2:" << p2.get() << endl;
    //return 0;
        // ownership von p1 auf p2 transferiert
        p2 = move(p1);
        //p2 = p1;
        // p2 = p1;		// nicht definiert!
        tools_log(); cout << "p1=" << "-"   << " &p1:" << p1.get() << endl;
        tools_log(); cout << "p2=" << (*p2) << " &p1:" << p2.get() << endl;
        //return 0;
        // modify object
        p2->n = 5;
        tools_log(); cout << "p2=" << (*p2) << " &p2:" << p2.get() << endl;
        
        // what happens?
        //C* pp = createC(4);
        //unique_ptr<C> p3(pp);
        //unique_ptr<C> p4(pp);

    }
    
    return EXIT_SUCCESS;
}
