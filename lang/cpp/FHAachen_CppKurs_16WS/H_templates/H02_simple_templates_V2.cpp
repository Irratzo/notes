/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema Templates
 */

#include <iostream>
#include <cstdlib>
using namespace std;

#include "../tools/tools.h"

template <typename T>       			/*	template, typename ?
 * 
 * 	Eine template Klasse mit Typ T. In aelterem Code auch oft als
 * 	template <class T> 
 */
class Point
{
public:
    typedef T value_type;

    T x,y;
};

template <typename T>
class TypeInfo
{
public:
	// analog numeric_limits<...>::min()
    static size_t CalcSize() { return sizeof(T); }
};

template <>								/*	template <> ?
 * 
 * 	Dies ist eine Spezialisierung. Das bedeutet, manche Template-Parameter
 * 	sind explizit angegeben. Die verbleibenden sind weiterhin Parameter, 
 * 	hier bleiben allerdings keine uebrig, daher ist die Menge der
 * 	Template-Parameter leer: <>
 */
class TypeInfo<bool>
{
public:
    // auch der return-Typ kann anders sein
    static double CalcSize() { return 1.0/8.0; }
};

// rotiere die Argumente t1 <- t2, t2 <- t3, t3 <- t1
template <typename T1, typename T2, typename T3>
void RotateLeft(T1 & t1, T2 & t2, T3 & t3)
{
    T1 tmp = t1;
    t1 = t2;
    t2 = t3;
    t3 = tmp;
}

int main()
{
    tools_log(); cout << "use of template classes" << endl;
	
    Point<int> P = {1,2};
    //Point<int>::value_type X = P.x;
    tools_log(); cout << "  coordinates P: (" << P.x << "," << P.y << ")" << endl;
    tools_log(); cout << "  size of P: " << sizeof(P) << endl;

    Point<long long> Q = {1LL,2LL};
    tools_log(); cout << "  coordinates Q: (" << Q.x << "," << Q.y << ")" << endl;
    tools_log(); cout << "  size of Q: " << sizeof(Q) << endl << endl;

    tools_log(); cout << "use of type info" << endl;
    tools_log(); cout << "  size of int: " << TypeInfo<int>::CalcSize() << endl;
    tools_log(); cout << "  size of double: " << TypeInfo<double>::CalcSize() << endl;
    tools_log(); cout << "  size of Point<int>: " << TypeInfo<Point<long long>>::CalcSize() << endl;
    // note: specialized template
    tools_log(); cout << "  size of bool: " << TypeInfo<bool>::CalcSize() << endl << endl;

    tools_log(); cout << "template functions" << endl;

    int n1=1;
    unsigned int n2=2;
    signed long n3=3;
    RotateLeft(n1,n2,n3);
    tools_log(); cout << "  n1=" << n1 << ", n2=" << n2 << ", n3=" << n3 << endl;
    
    return EXIT_SUCCESS;
}

