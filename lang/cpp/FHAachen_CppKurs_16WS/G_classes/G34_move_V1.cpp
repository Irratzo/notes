/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema move, move assignment, r- und l-value
 * 
 *  Stichworte:
 *      - &&
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

#include "../tools/tools.h"

/*	#pragma GCC optimize
 * 
 * 	Um temp. Objekte nicht direkt vom Compiler "wegoptimieren" zu
 * 	lassen, sondern sie zu beobachten, wird ein Compiler-Flag
 * 	zur Optimierung ausgeschaltet.
 * 
 * 	Beschreibung gcc:
 * 	-fno-elide-constructors
 * 	The C++ standard allows an implementation to omit creating a 
 * 	temporary which is only used to initialize another object of 
 * 	the same type. Specifying this option disables that optimization, 
 * 	and forces G++ to call the copy constructor in all cases. 
 */
#pragma GCC optimize "-fno-elide-constructors"

class C {
public:    
    C() { 
		tools_log(); cout << "ctor C()" << endl; 
	}
    
    C(const C &) { 
        tools_log(); cout << "ctor C(&)" << endl; 
    }
    
    C & operator=(const C &) {
        tools_log(); cout << "op=(&)" << endl; return *this; 
    }
        
    /*	Worin unterscheiden sich + und *?
     * 
     * 	Op+ wird ueber zwei Referenzen aufgerufen, wogegen Op* die
     * 	Kopie fuer den Rueckgabewert direkt beim Aufruf erzeugt.
     */
     
    C & operator+=(const C &) { 
        return *this; 
    }

    friend C operator+(const C & lhs, const C & rhs) {  
        tools_log(); cout << "op+" << endl; 
        C result(lhs);
        result += rhs;
        return result; 
    }

    C & operator*=(const C &) { 
        return *this; 
    }
    
    friend C operator*(C lhs, const C & rhs) { 
        tools_log(); cout << "op*" << endl; 
        lhs*=rhs; 
        return lhs; 
    }

};

int main()
{
    tools_log(); cout << "start" << endl;

	// Wie viele Objekte werden erzeugt?
	
    C c1,c2,c3;

    cout << endl;

    tools_log(); cout << "c3=c1+c2" << endl;
    c3 = c1+c2;
    //c3.operator=(operator+(c1,c2)); // long version c3=c1+c2
    
    cout << endl;
    
    tools_log(); cout << "c3=c1*c2" << endl;
    c3 = c1*c2;

    cout << endl;

    //tools_log(); cout << "c3=c1+c2+c3" << endl;
    c3 = c1+c2+c3;

    return EXIT_SUCCESS;
}

