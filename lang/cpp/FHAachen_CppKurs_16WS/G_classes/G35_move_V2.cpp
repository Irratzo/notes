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
        //return lhs*=rhs;   
    }

	/* move ctor und move-assignment-op
	 * 
     *  Motivation:
	 * 	Diese Funktionen werden nur im Falle von tmp. Obj (rvalues) aufgerufen.
	 */
	 
	// move ctor
    C(const C &&) { 
        tools_log(); cout << "ctor C(&&)" << endl; 
    }

    // move-assignment-operator
    C & operator=(const C &&) {
        tools_log(); cout << "op=(&&)" << endl; 
        return *this; 
    }

};

int main()
{
    tools_log(); cout << "start" << endl;

    C c1,c2,c3;

    cout << endl;

    tools_log(); cout << "c3=c1+c2" << endl;
    c3 = c1+c2;

    cout << endl;
    
    tools_log(); cout << "c3=c1*c2" << endl;
    c3 = c1*c2;

    cout << endl;

//    tools_log(); cout << "c3=c1+c2+c3" << endl;
    c3 = c1+c2+c3;

    return EXIT_SUCCESS;
}

