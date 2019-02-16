/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema smart Pointers, unique_ptr
 */

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
	{
		vector<C> vc;
		vc.push_back(C(1));
	}

    tools_log(); cout << "some operations (2)..." << endl;
    {

        vector< unique_ptr<C> > v;
        v.push_back( unique_ptr<C>(new C(6)) );
        tools_log(); cout << "v[0].get:" << v[0].get() << endl;
        
        unique_ptr<C> p = move(v[0]);
        tools_log(); cout << "v[0].get:" << v[0].get() << endl;
        tools_log(); cout << "p=" << (*p) << " &p:" << p.get() << endl;

        // funktioniert auch fuer arrays
        // unique_ptr<C[]> p4 ( new C[3] );
    }
    
    return EXIT_SUCCESS;
}
