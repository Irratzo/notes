// author: a.voss@fh-aachen.de

#include <iostream>
#include <set>
#include <vector>
using namespace std;

// Fibonacci Folge zur compile-Zeit berechnen
template <int n>
class Fib {
public:
    enum { v = Fib<n-1>::v + Fib<n-2>::v };
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

int main() {
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

	cout << "1)    fib(2) = " << Fib<2>::v << endl;

	cout << "2)    fib(7) = " << Fib<7>::v << endl << endl;
    
    return 0;
}

