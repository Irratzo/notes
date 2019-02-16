/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema Vererbung, inheritance
 * 
 *  Stichworte:
 *      - inheritance, virtual functions
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
using namespace std;

#include "../tools/tools.h"

#pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"

class Object
{
public:
int n;
    virtual string toString() const { return "Object::toString"; }
};

class C : public Object
{
public:
    string toString() const { return "C::toString"; }
};

void Out(const Object& o) { 
    tools_log(); cout << o.toString() << endl; 
}

int main()
{
    C c;
    
    tools_log(); cout << "size C " << sizeof(C) << endl;
//    cout << "adr " << (void*)(&c) << endl;
//    cout << "adr " << (void*)(&(c.n)) << endl;

    
    // was geht schief bzw. was ist beabsichtigt?
    tools_log(); cout << c.toString() << endl;
    Out(c);
    
    //Object& ro = c;
    //tools_log(); cout << ro.toString() << endl;

    return EXIT_SUCCESS;
}

