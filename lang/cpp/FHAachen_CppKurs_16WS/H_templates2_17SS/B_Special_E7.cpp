// author: a.voss@fh-aachen.de

#include <iostream>
#include <set>
#include <vector>
using namespace std;

// verschiedene Container (wie vector), abhaengig von einem Datentyp T ...

template <typename T>
class FastButComplex {
    //...
public:
    int f() { return 1; }
};

template <typename T>
class SafeButSlow {
    //...
public:
    int f() { return 2; }
};

template <typename T, template <typename> class S>
class Storage : public S<T> {
};

int main() {
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    Storage<int,FastButComplex> S1;
    Storage<int,SafeButSlow> S2;
    
	cout << "1)    S1.f() = " << S1.f() << endl;

	cout << "2)    S2.f() = " << S2.f() << endl << endl;
    
    return 0;
}

