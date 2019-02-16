/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema Template programming
 */

#include <iostream>
#include <cstdlib>
using namespace std;

#include "../tools/tools.h"

// Fibonacci Folge zur compile-Zeit berechnen
template <int n>
class Fib {
public:
    enum { v = Fib<n-1>::v+Fib<n-2>::v };
};

template <>
class Fib<1> {
public:
    enum { v = 1 };
};

template <>
class Fib<0> {
public:
    enum { v = 0 };
};

int main()
{
    tools_log(); cout << "use of recursive templates" << endl;
    tools_log(); cout << "  fib(2) = " << Fib<2>::v << endl;
    tools_log(); cout << "  fib(7) = " << Fib<7>::v << endl << endl;

    return EXIT_SUCCESS;
}

