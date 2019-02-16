/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema ctor and op= Implementation
 * 
 *  Stichworte:
 *      - default, deleted, implicit, explicit
 */

#include <iostream>
#include <cstdlib>
using namespace std;

#include "../tools/tools.h"

#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#pragma GCC optimize "-fno-elide-constructors"

class A { 
public:
    A() = default;
    A(double) { }         // Wenn dieser ctor exist., dann gibt es keinen Default
    A(const A&) = delete; // Kein copy ctor
    
    A& operator=(const A&) = default;    // und default assignment
    
    // old style: private oder keine Implementation
    // A& operator=(const A&);
};

class B {
    int n;
public:
    B() = delete;
    
    B(int n) : n(n) { cout << "B::B(int n) n=" << n << endl; }
    B(const B& br) { n=br.n; cout << "B::B(B&) n=" << n << endl; }
    //B(const B& br) = delete;
};

class C {
public:
    // zumeist C++11 features
    
    C() = default;		// std ctor
    
    // Benutzt ctor C(string) 
    C(const char * pc) : C(string(pc))  { tools_log(); cout << "   C(pc) '" << pc << "'" << endl; }
    
    C(const string & s)                 { tools_log(); cout << "   C(s)  '" << s << "'" << endl; }
    
    // implizit verboten
    explicit C(int n)                   { tools_log(); cout << "   C(n)  '" << n << "'" << endl; }

	// in Verbindung mit move kann loeschen Sinn machen
    C(const C &) = default; 
            
    C& operator=(const C&) = delete;
};

int main()
{
    tools_log(); cout << "A objects" << endl << endl;

/*    A a1;
    A a2(2.3);
    // A a3(a2); // deleted
    a1=a2;       // default */

    tools_log(); cout << "B objects" << endl << endl;
    // B b;     // deleted
    B b1(5);
    B b2 = 5;   // how many ctors? note: pragma!
    
    cout << endl;

    tools_log(); cout << "C objects" << endl << endl;
    
    C c1;

    // Was wird aufgerufen?
    tools_log(); cout << "ctor str" << endl;
    C c2(string("c2"));
    tools_log(); cout << "ctor pc" << endl;
    C c3("c3");
    tools_log(); cout << "ctor pc" << endl;
    C c4 = "c4";
    
    tools_log(); cout << "ctor n" << endl;
    C c5(42);
    
    //C c6 = 23;    // Wo liegt das Problem?
    
    // c1 = c2; // does not work, why?

    tools_log(); cout << "end of main" << endl;
    
    return EXIT_SUCCESS;
}

