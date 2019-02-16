/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema Vererbung
 * 
 *  Stichworte:
 *      - multiple inheritance
 */

#include <iostream>
#include <cstdlib>
using namespace std;

#include "../tools/tools.h"

class A 
{
//protected:
public:
    int n;
    
public: 
    // no std-cstr
    A(int N) : n(N) { tools_log(); cout << "ctor A(" << n << ")" << endl; }
    ~A()            { tools_log(); cout << "dtor A(" << n << ")" << endl; }
    
    int getn() const { return n; }
};

class B1 : public A
{
public:
    B1(int N) : A(N) { tools_log(); cout << "ctor B1(" << n << ")" << endl; }
    ~B1()            { tools_log(); cout << "dtor B1(" << n << ")" << endl; }
};

class B2 : public A
{
public:
    B2(int N) : A(N) { tools_log(); cout << "ctor B2(" << n << ")" << endl; }
    ~B2()            { tools_log(); cout << "dtor B2(" << n << ")" << endl; }
};

class C : public B1, public B2
{
public:
    C(int N) : B1(N+1),B2(N+2) { tools_log(); cout << "ctor C(" << B1::n << "," << B2::n << ")" << endl; }
    ~C()                       { tools_log(); cout << "dtor C(" << B1::n << "," << B2::n << ")" << endl; }
};

int main()
{
    tools_log(); cout << "define objects" << endl;

    tools_log(); cout << "b1:" << endl;
    B1 b1(1);
    tools_log(); cout << "b2:" << endl;
    B2 b2(2);
    tools_log(); cout << "c:" << endl;
    C c(3);

    tools_log(); cout << "c.B1.n:" << c.B1::n 
                      << ", c.B2::n:" << c.B2::n << endl;
    tools_log(); cout << "&c.B1.n:" << &c.B1::n 
                      << ", &c.B2::n:" << &c.B2::n << endl;
    
    tools_log(); 
    cout << "size B1 = " << sizeof(B1) 
         << ", size B2 = " << sizeof(B2) 
         << ", size C = " << sizeof(C) << endl;
    
    tools_log(); cout << "dstr..." << endl;
    
    return EXIT_SUCCESS;
}

