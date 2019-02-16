/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema Vererbung, inheritance
 * 
 *  Stichworte:
 *      - inheritance
 */

#include <iostream>
#include <cstdlib>
using namespace std;

#include "../tools/tools.h"

class A 
{
protected:
    int n;
    
public: 
    // kein std-ctor!
    A(int N) : n(N) { tools_log(); cout << "ctor A(" << n << ")" << endl; }
    ~A()            { tools_log(); cout << "dtor A(" << n << ")" << endl; }
    
    // member-Funktion in A
    int getn() const { return n; }
};

class B : public A  					/*	public A ?
 * 
 * 	B erbt alle Eigenschaften von A und diese sind public. Genauso
 * 	moeglich sind protected und private.
 */
{
protected:
    char c;
    
public: 
    B(int N) : A(N), c('A') { 			/*	A(N) ?
 * 
 * 	Es gibt keinen std-ctor in A. Das bedeutet, es muss explizit
 * 	angegeben werden, welcher ctor verwendet werden soll - hier A(N).
 * 	Man beachte auch, dass n aus A (in cout) verwendet werden kann,
 * 	da es protected ist.
 */
		tools_log(); cout << "ctor B(" << n << ")" << endl; 
	}
    ~B()                    { 
		tools_log(); cout << "dtor B(" << n << ")" << endl; 
	}
};

int main()
{
    tools_log(); cout << "define objects" << endl;

    A a(1);
    B b(2);     // b is also of type A and a little bit more (char c)
    
    tools_log(); cout << "a.n = " << a.getn() << ", b.n = " << b.getn() << endl;
        
    tools_log(); cout << "size A = " << sizeof(A) << ", size B = " << sizeof(B) << endl;
    
    return EXIT_SUCCESS;
}

