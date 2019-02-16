/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema smart Pointers, shared_ptr
 */

#include <iostream>
#include <memory>
#include <cstdlib>
#include <vector>
using namespace std;

#include "../tools/tools.h"

// http://ootips.org/yonat/4dev/smart-pointers.html

/* from cppreference:
    std::shared_ptr is a smart pointer that retains shared ownership of an object 
    through a pointer. Several shared_ptr objects may own the same object. The 
    object is destroyed and its memory deallocated when either of the following 
    happens:
        the last remaining shared_ptr owning the object is destroyed.
        the last remaining shared_ptr owning the object is assigned another 
        pointer via operator= or reset().
        The object is destroyed using delete-expression or a custom deleter that 
        is supplied to shared_ptr during construction.
        A shared_ptr can share ownership of an object while storing a pointer to 
        another object. This feature can be used to point to member objects while 
        owning the object they belong to.
        A shared_ptr may also own no objects, in which case it is called empty.
    
    std::weak_ptr is a smart pointer that holds a non-owning ("weak") reference 
    to an object that is managed by std::shared_ptr. It must be converted to 
    std::shared_ptr in order to access the referenced object.
    std::weak_ptr models temporary ownership: when an object needs to be accessed 
    only if it exists, and it may be deleted at any time by someone else, 
    std::weak_ptr is used to track the object, and it is converted to 
    std::shared_ptr to assume temporary ownership. If the original std::weak_ptr 
    is destroyed at this time, the object's lifetime is extended until the 
    temporary std::shared_ptr is destroyed as well.
    In addition, std::weak_ptr is used to break circular references of std::shared_ptr.
*/

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
    tools_log(); cout << "shared ptr usage..." << endl;

    shared_ptr<C> p1a( createC(1) );   // first ref 
    shared_ptr<C> p1b = p1a;           // second ref 
    
    /* besser:
        auto p2 = std::make_shared<int>(12);
        Idee, memory leaks in: 
            f(std::shared_ptr<int>(new int(42)), g())
    */
       
    tools_log(); cout << "*p1a:" << (*p1a) << " p1a:" << p1a.get() << " use_cnt: " << p1a.use_count() << endl;
    tools_log(); cout << "*p1b:" << (*p1b) << " p1b:" << p1b.get() << " use_cnt: " << p1b.use_count() << endl;

    p1a.reset();                       // nothing happens
    tools_log(); cout << "*p1a:" << "-"    << " p1a:" << p1a.get() << " use_cnt: " << p1a.use_count() << endl;
    tools_log(); cout << "*p1b:" << (*p1b) << " p1b:" << p1b.get() << " use_cnt: " << p1b.use_count() << endl;

    p1b.reset();                       // mem is gone
    tools_log(); cout << "*p1a:" << "-"    << " p1a:" << p1a.get() << " use_cnt: " << p1a.use_count() << endl;
    tools_log(); cout << "*p1b:" << "-"    << " p1b:" << p1b.get() << " use_cnt: " << p1b.use_count() << endl;
        
    return EXIT_SUCCESS;
}
