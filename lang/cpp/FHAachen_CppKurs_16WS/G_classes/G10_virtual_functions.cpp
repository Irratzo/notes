/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema Vererbung, inheritance
 * 
 *  Stichworte:
 *      - inheritance, virtual functions
 *      - virtual, override, final
 */

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

#include "../tools/tools.h"

#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"

// f is not virtual, g is
class A
{
public:
    void f()               { tools_log(); cout << "A::f" << endl; }
    virtual void g()       { tools_log(); cout << "A::g" << endl; }
};

// note: g is still virtual
class B : public A
{
public:
    void f()               { tools_log(); cout << "B::f" << endl; }
    void g()               { tools_log(); cout << "B::g" << endl; }
};

// note: "final" and "override" are C++11-features!

// empty class but with one virtual function
class D
{
public:
    // virtual ~D() {}
    void f1()               { tools_log(); cout << "D::f1" << endl; }
    virtual void f2()       { tools_log(); cout << "D::f2" << endl; }
    virtual void f3(int n)  { tools_log(); cout << "D::f3 n=" << n << endl; }
    virtual void f4() final { tools_log(); cout << "D::f4" << endl; }
};

// empty class inheriting virtual functions;
// class is marked as final thus it is not possible to inherit from
class E final : public D
{
public:
    void f1()               { tools_log(); cout << "E::f1" << endl; }
    void f2()               { tools_log(); cout << "E::f2" << endl; }
    virtual void f3(int n) { tools_log(); cout << "E::f3 n=" << n << endl; }

// note: overriding needs exact the same parameters ..
// use "override" to emphasize your intention, this results in an error 
// if declarations differ
 //   virtual void f3(unsigned int n)  override  { cout << "E::f3 n=" << n << endl; }

// the following is not possible as f4 is declared as "final"
//    virtual void f4() final { cout << "D::f4" << endl; }
};


int main()
{
    tools_log(); cout << "example 1" << endl;
    A a;
    B b;
    
    // virtual plays no role! an object of type A calls functions of class A
    tools_log(); cout << "  a:" << endl;
    a.f();
    a.g();
    tools_log(); cout << "  b:" << endl;
    b.f();
    b.g();

    cout << endl;
    tools_log(); cout << "example 2" << endl;
    A *pa = new A(), *pb = new B();
    
    // virtual is important because we have ptrs of type A but
    // in fact one object of type A and one of type B (is also A)
    // -> virtual functions are needed to call the correct function g
    tools_log(); cout << "  pa:" << endl;
    pa->f();
    pa->g();
    tools_log(); cout << "  pb:" << endl;
    pb->f();
    pb->g();
    delete pa;
    delete pb;
/*
    cout << endl;
    tools_log(); cout << "example 3" << endl;
    A &ra = a, &rb = b;
    
    // virtual is important because we have refs of type A but
    // in fact one object of type A and one of type B (is also A)
    // -> virtual functions are needed to call the correct function g
    // this is exactly the ptrs situation (example 2) but with refs
    tools_log(); cout << "  ra:" << endl;
    ra.f();
    ra.g();
    tools_log(); cout << "  rb:" << endl;
    rb.f();
    rb.g();

    cout << endl;

    tools_log(); cout << "example 4" << endl;
    D d;
    E e;
    
    tools_log(); cout << "d:" << endl;
    d.f1();
    d.f2();
    tools_log(); cout << "e:" << endl;
    e.f1();
    e.f2();
    
    // this is a D-reference to an E-obj (remember: E is D)
    D & r = e;
    tools_log(); cout << "r:" << endl;
    r.f1();
    r.f2();
    r.f3(1);
   
    // same principle
    tools_log(); cout << "v:" << endl;
    vector<D*> v = { new D(), new E(), new D(), new E() };
    for (D* p : v)
        p->f2();

//#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"
    // delete pointers -> this is a problem, why?
    for (D* p : v)
        delete p;
    v.clear(); 
    // consider a virtual descructor for classes being inherited
    // ie. here: add to D: virtual ~D() {}
*/
    return EXIT_SUCCESS;
}

