// author: a.voss@fh-aachen.de

#include <iostream>
#include <set>
#include <vector>
using namespace std;

// Klasse haelt einfach einen Wert und kann kompatible zugewisen werden
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

// Type (traits) ermittelt den genaueren Typ

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

// Operator+ rechnet und konvertiert in den genaueren Typ
// (typename in typedef wird bei Typdefinitionen verwendet)
// Beispiel fuer die Verwendung von Traits

template <typename T1, typename T2>
Wert<typename ReturnType<T1,T2>::value_type> operator+(const Wert<T1>& lhs, const Wert<T2>& rhs) {
    typedef typename ReturnType<T1,T2>::value_type value_type;
    Wert<value_type> rc((value_type)lhs.x);
    rc.x += (value_type)(rhs.x);
    return rc;
}

int main() {
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    
    Wert<int> w1(1),w2(2),w3(0);

	cout << "1)    w1:" << w1 << endl;
    w3 = w1+w2;
	cout << "2)    w3:" << w3 << endl;
    
    Wert<double> d1(1.5),d2(2.5),d3(0);

	cout << "3)    d1:" << d1 << endl;
    d3 = d1+d2;
	cout << "4)    d3:" << d3 << endl;

    d3 = w1+d2;
	cout << "5)    d3:" << d3 << endl;

    d3 = d2+w1;
	cout << "6)    d3:" << d3 << endl << endl;
    
    return 0;
}

