/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema Verwendung eigener Operatoren
 * 
 *  Stichworte:
 *      - operator
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

#include "../tools/tools.h"

class Bruch {
	int z,n;	// z/n
	
public:
	Bruch(int Z, int N) : z(Z), n(N) { }
	
	
	/*	Wie koennen op*= und op* definiert werden? */
	
	Bruch & operator*=(const Bruch & b) {
		z*=b.z;
		n*=b.n;
		return *this;
	}
	
	friend const Bruch operator*(Bruch lhs, const Bruch & rhs) {	
		return lhs*=rhs;
	}

	/*friend const Bruch operator*(const Bruch & lhs, const Bruch & rhs) {	
        Bruch res(lhs);
        res *= rhs;
		return res;
	}*/
	
	
    friend ostream & operator<<(ostream & os, const Bruch & b ) {
        os << "(" << b.z << "/" << b.n << ")"; return os;
    }
	
};


int main()
{
    tools_log(); cout << "play with operators ..." << endl;

	Bruch b1(2,3),b2(3,1),b3(3,2);
	
	tools_log(); cout << "b1:" << b1 << ",b2:" << b2 << ",b3:" << b3 << endl;
	
	b1 *= b2;   // b1.operator*(b2);
	b3 = b1*b2;
	tools_log(); cout << "b1:" << b1 << ",b2:" << b2 << ",b3:" << b3 << endl;
    
    return EXIT_SUCCESS;
}
