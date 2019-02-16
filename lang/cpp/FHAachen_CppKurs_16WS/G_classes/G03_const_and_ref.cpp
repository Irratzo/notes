/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Verwendung von const und Referenzen
 * 
 *  Stichworte:
 *      - const, ref &
 */

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "../tools/tools.h"

class C {
    int n;
        
public:
    C(int n=0) : n(n) { }
    C(const C& c) : n(c.n) { }
    C& operator=(const C& c) {  n = c.getn(); return *this; }

    // const marks that getn does not modify object
    int getn() const { return n; }
    // setn cannot be const as it modifies object
    void setn(int n) { this->n = n; } // (*this).n = n 
    
    friend ostream& operator<<(ostream& os, const C& c) { os << c.getn(); return os; }
};

int read_n(const C & c) { return c.getn(); }     // here c is considered const!

int main()
{
    C c1(1), c2(2);         // a non-const-obj can call const-member getn
    tools_log(); cout << "c1=" << c1 << ", c2=" << c2 << ", c2.getn=" << c2.getn() << endl;

    c1.setn(3); c2.setn(4); // a non-const-obj can be used as const-parameter for read_n
    tools_log(); cout << "c1=" << c1 << ", c2=" << c2 << ", read_n(c2)=" << read_n(c2) << endl;
    
    const C c3(5);
    // c3.setn(6);          // a const-obj cannot call a non-const-member
    
    C & cr = c1;            // this is a (non-const-)reference to c1
    
    cr = c2;                // is this a new ref. to cr?

    tools_log(); cout << "c1=" << c1 << ", c2=" << c2 << endl;

    // conclusion: c1 has been modified, i.e. cr=c2 means copy c2 to cr(=c1)
    // -> a reference (cr) is initialized only once! after that it is an alias 
    //    for the object referring to (c1)
    // test: c1 will be modified
    cr.setn(7);
    tools_log(); cout << "c1=" << c1 << ", c2=" << c2 << endl;
    
    const C & ccr = c1;
    // ccr.setn(8);         // as ccr is a const-reference, it cannot call a non-const-member
    
    tools_log(); cout << "cr=" << cr << ", ccr=" << ccr << endl;
    
    const C &r1=c2, r2;    // note: only r1 is a reference, r2 is of type C; see also ptr decl.
    tools_log(); cout << "r1=" << r1 << ", r2=" << r2 << endl;

    return EXIT_SUCCESS;
}

