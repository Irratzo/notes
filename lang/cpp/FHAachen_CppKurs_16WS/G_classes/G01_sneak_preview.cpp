/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Preview wichtiger C++-Features
 */

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

#include "../tools/tools.h"

// classes
class C {
public:
    int n;

    C() : n(-1) 
    { 
        tools_log(); cout << "cstr C() n=" << n << endl; 
    }
     
    C(int _n) : n(_n) 
    { 
        tools_log(); cout << "cstr C(n) n=" << n << endl; 
    }
     
    C(const C& c) : n(c.n) 
    { 
        tools_log(); cout << "cstr C(c) n=" << n << endl; 
    }
     
    ~C() { 
        tools_log(); cout << "dstr ~C() n=" << n << endl; 
    } 
    
    // try C c
    friend ostream& operator<<(ostream& os, const C& c)
    {
        os << c.n; 
        return os; 
    }
    
    // add some objects
    friend C operator+(const C& c1, const C& c2) 
    { 
        return C(c1.n+c2.n); 
    }

};

// multiple inheritance
class D { int n; };
class E1 : D { };
class E2 : D { };
class F : public E1, public E2 { };

// generics with more than types
template <class T, int D>
class Memory {
public:
    T t;
    enum { dim = D };

    Memory(T _t) : t(_t) { }
};

int main()
{
    tools_log(); cout << "before" << endl;
    if (true)
    {
        C c(12);
        tools_log(); cout << "op<< like ToString: " << c << endl;
    }
    tools_log(); cout << "after" << endl << endl;
           
    C c1(5),c2(7),c3;
    tools_log(); cout << "3 Objects allocated" << endl << endl;
    
    c3 = c1+c2; 
    tools_log(); cout << "op+ " << c3 << endl << endl;
    
    // malloc is forbidden, use new and delete
    C* pc = new C(12345);
    tools_log(); cout << "pc lives ... " << (*pc) << endl;
    delete pc;

    cout << endl;

    // standard library
    vector<int> v;
    v.push_back(42);
    v.push_back(112);
    tools_log(); cout << "size vector: " << v.size() 
                      << " [0]=" << v[0] << " [1]=" << v[1] << endl;
         
    // generic programming
    Memory<int,2> m(1);
   
    return EXIT_SUCCESS;
}

