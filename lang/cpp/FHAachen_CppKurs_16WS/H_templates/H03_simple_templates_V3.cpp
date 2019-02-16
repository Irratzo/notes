/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema Templates
 */

#include <iostream>
#include <cstdlib>
using namespace std;

#include "../tools/tools.h"

// Es sind auch int-Template-Parameter zugelassen, hier ein
// Vektor fixer Laenge.
template <typename T, int N>
class MyVector 
{
public:
    enum { dim = N };
    T data[dim];
    
    T operator[](int i) const { return data[i]; }
    T& operator[](int i) { return data[i]; }
    
    template <typename S>				/*	Wozu ?
     * 
     * 	Die Zuweisung von Vektoren anderen Typs, allerdings mit gleicher
     * 	Laenge, ist hiermit moeglich.
     */
    MyVector & operator=(const MyVector<S,N> & v)
    {
        for (int i=0; i<N; ++i)
            data[i] = (T)(v.data[i]);
        return *this;
    }
};

// template partial specialization
// fuer den Fall dim=0
template <typename T>
class MyVector<T,0>
{
public:
    enum { dim = 0 };
    T data;
    
    T operator[](int) const { return data; }
    T& operator[](int) { return data; }
};

// ein typedef template
template<class T> 
using MyVector3d = MyVector<T,3>;

// Spezialisierung funktioniert auch bei Funktionen
template <typename T>
T Inverse(const T & t) { return (T)1/t; }

double Inverse(const double & t) { return 23; }

// Berechne "Inverse" fuer chars wie folgt: A -> Z, B -> Y und vice versa
template <>
char Inverse(const char & t) { return (char)(90-(int)t+65); }

int main()
{
    tools_log(); cout << "use of template classes" << endl;
    
    MyVector<int,3> v3;
    MyVector<int,0> v0;
    tools_log(); cout << "  size of v3: " << sizeof(v3) << endl;
    tools_log(); cout << "  size of v0: " << sizeof(v0) << endl << endl;

    MyVector<double,3> d3;
    tools_log(); cout << "  size of d3: " << sizeof(d3) << endl << endl;
    
    d3 = v3;
    v3 = v3;
    v3 = d3;
    // v3 = v0;
    
    MyVector3d<char> c3;
    tools_log(); cout << "  size of c3: " << sizeof(c3) << endl << endl;

    tools_log(); cout << "use of specialized template functions" << endl;
    tools_log(); cout << "  0.1 ^-1  = " << Inverse(0.1) << endl;
    tools_log(); cout << "  10  ^-1  = " << Inverse(10.0) << endl;
    tools_log(); cout << "  'B' ^-1  = " << Inverse('B') << endl;

    tools_log(); cout << "  10 ^-1  = " << Inverse(10) << endl;

    return EXIT_SUCCESS;
}

