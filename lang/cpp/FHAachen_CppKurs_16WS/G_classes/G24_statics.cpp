/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema statische Member
 * 
 *  Stichworte:
 *      - static
 */

#include <iostream>
#include <cstdlib>
using namespace std;

#include "../tools/tools.h"

class C {
    int n = 23;
    static int cnt; 	//  = 0; direkte Initialisierung nicht erlaubt

public:
    C()  { ++cnt; }		// cnt enthaelt die aktuelle Anzahl von C-Objekten
    ~C() { --cnt; }
        
    void set_n(int N);	// hier nur Deklarationen; Definitionen ausserhalb
    int get_n() const;
    
    static int get_cnt() { return cnt; }
};

// Definitionen folgen, jeweils mit vollem Namen ("C::")

int C::cnt = 0;

void C::set_n(int N) { 
	n=N; 
}

int C::get_n() const { 
    return n; 
}

/*	statische Elemente
 * 	
 * 	koennen entweder ueber den Klassennamen angesprochen werden, also
 * 	z.B. C::get_cnt()
 * 	oder auch ueber ein Objekt, 
 * 	z.B. c1.get_cnt()
 * 	obwohl sie ein Objekt nicht benoetigen.
 */

// f() { static ...}

int main()
{    
	tools_log(); cout << "#C-Obj: " << C::get_cnt() << endl;

    C c1,c2; 
    c2.set_n(42); 
    tools_log(); cout << "c1.n=" << c1.get_n() << ", c2.n=" << c2.get_n() 
                      << ", #C-Obj: " << C::get_cnt() << endl;
    
    if (true) {
        C c3;
        tools_log(); cout << "#C-Obj: " << C::get_cnt() << endl;
    }
    
    tools_log(); cout << "#C-Obj: " << C::get_cnt() << endl;
    
//    f();
//    f();
//    f();
    
    return EXIT_SUCCESS;
}

