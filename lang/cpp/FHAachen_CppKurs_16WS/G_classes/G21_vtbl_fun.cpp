/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema vtables
 * 
 *  Stichworte:
 *      - vtbl
 */

#include <iostream>
#include <cstdlib>
using namespace std;

#include "../tools/tools.h"

// this only works in 32-bit systems as sizeof(void*)==size(long)
class C1 { 
public: 
    long n = 1; 
};

class C2 { 
public: 
    long n = 2; 
    virtual void f(int m) { 
        tools_log(); 
        cout << "C2::f, n=" << n << ", par m=" << m << ", this=" 
        << hex << this << dec << endl; 
    } 
};

/* dump of g++ -fdump-class-hierarchy ...  => .class file

Class C1
   size=4 align=4
   base size=4 base align=4
C1 (0xb6002e00) 0

Vtable for C2
C2::_ZTV2C2: 3u entries
0     (int (*)(...))0
4     (int (*)(...))(& _ZTI2C2)
8     (int (*)(...))C2::f

Class C2
   size=8 align=4
   base size=8 base align=4
C2 (0xb6002e38) 0
    vptr=((& C2::_ZTV2C2) + 8u)
*/

// note: an instance of a class with virtual functions always contains
//       an additional member being a ptr to the vtable of the class
//       in order to resolve virtual function calls


void g(C2* p,int m)
{
    tools_log(); 
    cout << "in g, n=" << p->n << ", par m=" << m << ", this=" 
         << hex << p << dec << endl; 
}

int main()
{
    tools_log(); cout << "define objects" << endl;

    // consider the following vector with base class objects (D) and 
    // derived ones (E), both have a virtual function f2 (see understand_virtual() );
    // how is the concept of virtual functions implemented, i.e. how does 
    // the compiler manage to call the correct function f2 at run-time?
    //
    // vector<D*> v = { new D(), new E(), new D(), new E() };
    // for (D* p : v)
    //     p->f2();

    // compare classes with and without virtual functions
    C1 c1;  // no virtual function
    C2 c2;  // one virtual function

    tools_log(); 
    cout << "c1.n = " << c1.n 
         << ", sizeof c1 = " << sizeof(c1) 
         << ", &c1 = " << hex << (&c1) << dec << endl;
    tools_log(); 
    cout << "c2.n = " << c2.n 
         << ", sizeof c2 = " << sizeof(c2) 
         << ", &c2 = " << hex << (&c2) << dec << endl << endl;
    
    long* p;
    
    // here the first "member" is the int-member n
    p = (long*)(&c1);
    tools_log(); cout << "content of &c1: " << p[0] << endl;

    // here (!) the first "member" is a pointer to the vtable
    // and the second one is n
    p = (long*)(&c2);
    tools_log(); cout << "content of &c2: " << p[1] << ", vtable at " 
                      << hex << (void*)(p[0]) << dec << endl << endl;
    
    
    // call a member via func-ptr, here we need a slightly different syntax
    typedef void (C2::*c2_member_func)(int);
 
    tools_log(); cout << "orig-call c2.f: " << endl;
    c2_member_func pf = &C2::f;     // this is a function pointer to C2::f
    (c2.*pf)(123);                  // we need some object to call it!
    
    // now call the virtual function f as a non-member function ptr
    tools_log(); cout << "sim.-call c2.f: " << endl;
    long* vtable = (long*)(p[0]);   // begin of vtable
    typedef void (*sim_func)(C2*,int);
    sim_func f = (sim_func)(vtable[0]);
    // treat first entry as a function with one additional parameter,
    // the objects-ptr this -> in fact call (c2.f)
    f(&c2,246);

    // now call the member-function with another type of object
    struct { long* ptr=0; long n=3; } c3;
    tools_log(); cout << "sim.-obj. c3.f: " << hex << (void*)(&c3) << dec << endl;
    f((C2*)(&c3),369);              // later, this is: reinterpret_cast<C2*>

    // now verify behaviour by inserting a vtable ptr. into c3-struct
    C2 & c2r = *(C2*)(&c3);     // reinterpret c3 as C2 object
    c3.ptr = vtable;            // set the vtable on first position 'ptr'
    c2r.f(468);                 // call virtual member

    // can we modify functions in the vtable?
    // vtable[0] = ...
    // -> this is impossible as vtable is read-only
    
    // but we can replace objects vtable with our own ...
    sim_func myTable[] = { g };
    
    cout << endl;
    tools_log(); cout << "change vtables: " << endl;

    // p[0] points to the first entry in c2
    p[0] = reinterpret_cast<long>(myTable);
    tools_log(); cout << "content of &c2: " << p[1] << ", " 
                      << hex << (void*)(p[0]) << dec << endl;

	// lets try
    c2.f(5);        // should call h, but calls f instead ???
    (&c2)->f(6);    // same here

    C2* ppp = &c2;  // indirectly
    ppp->f(7);      // success
    
    // -> do not try this at home!

    return EXIT_SUCCESS;
}

