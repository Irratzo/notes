/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema Verwendung eigener Operatoren
 * 
 *  Stichworte:
 *      - operator
 */

#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

#include "../tools/tools.h"

// naive Implementation, spaeter folgt eine bessere.
class Point
{
    int _x1,_x2;
    
public: 
    Point(int x1, int x2) : _x1(x1), _x2(x2)
    { 
        tools_log(); cout << "ctor " << (*this) << endl;
    }
    
    Point(const Point & p) : _x1(p._x1), _x2(p._x2)
    { 
        tools_log(); cout << "ctor " << (*this) << endl;
    }
        
    int & operator[](int n)				/*	op[] ?
     * 
     * 	Dieser Operator wird aufgerufen, wenn p vom Type Point 
     * 	und nicht konstant ist, zB bei p[2]=1;
     */
    {
        tools_log(); cout << "op[" << n << "] non-const " << (*this) << endl;
        return (0==n) ? _x1 : _x2;
    }

    const int & operator[](int n) const	/*	op[] ?
     * 
     * 	Dieser Operator wird bei p[2] aufgerufen, wenn p vom Type Point 
     * 	und konstant ist.
     */
    {
        tools_log(); cout << "op[" << n << "] const " << (*this) << endl;
        return (0==n) ? _x1 : _x2;
    }

    // Warum member?
    bool operator==(const Point & p) const 
    {
        bool result = (_x1==p._x1) && (_x2==p._x2);
        tools_log(); cout << "op== " << result << endl;
        return result;
    }
    
    Point & operator++()    			/*	op++() ?
     * 
     * 	Ohne (int)-Arg. entspricht das ++p fuer p vom Typ Point.
     */
    {
        ++_x1; ++_x2;
        tools_log(); cout << "++op " << (*this) << endl;
        return *this;
    }
    
    Point operator++(int)				/*	op++(int) ?
     * 
     * 	Mit (int)-Arg. entspricht das p++ fuer p vom Typ Point.
     */
    {
        Point tmp(*this);   // old value
        ++_x1; ++_x2;
        tools_log(); cout << "op++ " << (*this) << endl;
        return tmp;
    }

    friend ostream & operator<<(ostream & os, const Point& p)
    {
        os << "(" << p._x1 << "," << p._x2 << ")";
        return os;
    }
};

int main()
{
    tools_log(); cout << "define objects" << endl;

    Point p1(1,2);
    Point p2(1,2);
    const Point p3(p1);
    bool b;
    int n;
    
    cout << endl;
    tools_log(); cout << "call op==" << endl;
    b = (p1==p2); 						/*	Wieso ist op== Member?
     * 
     * 	Aus Symmetriegruenden sollte op== kein Member sein. Gruende 
     * 	folgen. Es geht aber, d.h. hier ist es p1.operator==(p2)
     */
    
    cout << endl;
    tools_log(); cout << "call op[]" << endl;
    p1[1] = 23;
    n = p1[0];
    n = p3[0];

    cout << endl;
    tools_log(); cout << "call op++" << endl;
    ++p1;
    p1++;
    
    return EXIT_SUCCESS;
}

