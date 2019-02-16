/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema Templates
 */

#include <iostream>
#include <cstdlib>
#include <set>
#include <vector>
#include <limits>
#include <cmath>
using namespace std;

#include "../tools/tools.h"

template <typename T>
class Wert {
public:
    T x;
    Wert(T x) : x(x) { }
        
    friend ostream& operator<<(ostream& os, const Wert& W) {
        os << "(" << W.x << ")";
        return os;
    }
    
    template <typename S>
    Wert& operator=(const Wert<S>& W) {
        x = (T)W.x;
        return *this;
    }

};

template <typename T1, typename T2>
struct ReturnType;

template <>
struct ReturnType<int,double> {
    typedef double value_type;
};
template <>
struct ReturnType<double,int> {
    typedef double value_type;
};
template <typename T>
struct ReturnType<T,T> {
    typedef T value_type;
};

template <typename T1, typename T2>
Wert<typename ReturnType<T1,T2>::value_type> operator+(const Wert<T1>& lhs, const Wert<T2>& rhs) {
    typedef typename ReturnType<T1,T2>::value_type value_type;
    Wert<value_type> rc((value_type)lhs.x);
    rc.x += (value_type)(rhs.x);
    return rc;
}

int main()
{
    tools_log(); cout << "use of template classes" << endl;
    
    Wert<int> w1(1),w2(2),w3(0);
    
    tools_log(); cout << "w1:" << w1 << endl;
    w3 = w1+w2;
    tools_log(); cout << "w3:" << w3 << endl;

    Wert<double> d1(1.5),d2(2.5),d3(0);
    tools_log(); cout << "d1:" << d1 << endl;
    d3 = d1+d2;
    tools_log(); cout << "d3:" << d3 << endl;

    d3 = w1+d2;
    tools_log(); cout << "d3:" << d3 << endl;

    d3 = d2+w1;
    tools_log(); cout << "d3:" << d3 << endl;

    return EXIT_SUCCESS;
}

