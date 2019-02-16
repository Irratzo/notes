/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema Vererbung
 * 
 *  Stichworte:
 *      - pure virtual functions
 */

#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

#include "../tools/tools.h"

#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"

// assume this is a base class of all objects
class Object {
public:
     virtual string toString() { return "(obj)"; }
};

// assume this is an interface with one (pure) virtual function
class ICloneable {
public:
    virtual Object* clone() = 0;
};

// then two classes extending Object, implementing ICloneable
class A : public Object, public ICloneable
{
public:
    string toString() { return "(I am A)"; }
    Object* clone() { return new A(); }
};

class B : public Object, public ICloneable
{
public:
    string toString() { return "(I am B)"; }
    Object* clone() { return new B(); }
};

int main()
{
    tools_log(); cout << "example 1" << endl;
    A a;
    B b;
    
    // no virtual needed
    tools_log(); cout << "  a:" << a.toString() << endl;
    tools_log(); cout << "  b:" << b.toString() << endl;

    cout << endl;
    tools_log(); cout << "example 2" << endl;

    // here we define a container holding all kinds of Objects
    //
    // virtual is important because we have ptrs of type Object but
    // in fact one object of type A and one of type B (both are Object)
    // -> virtual functions are needed to call the correct toString
    
    vector<Object*> v;
    v.push_back(a.clone());
    v.push_back(b.clone());
    v.push_back(a.clone());
    v.push_back(b.clone());
    //v.push_back(&a);
    //v.push_back(&b);
    
    for (Object* o : v) {
        tools_log(); cout << "  v:" << o->toString() << endl;
    }
    
    // something wrong ...
    for (Object* o : v)
        delete o;
    v.clear();

    return EXIT_SUCCESS;
}

