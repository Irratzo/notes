// author: a.voss@fh-aachen.de

#include <iostream>
#include <set>
#include <vector>
using namespace std;

// Templates kommen auch als Funktionen vor
template <typename T>
void myswap(T& t1, T& t2) {
    T t = t1;
    t1 = t2;
    t2 = t;
}

int main() {
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    // Die Typbestimmung erfolgt entweder implizit anhand der Argumente ...
    double a=2.0, b=3.0;
    myswap(a,b);
    cout << "1)    a: " << a << ", b: " << b << endl;

    int i=2, j=3;
    myswap(i,j);
    cout << "2)    i: " << i << ", j: " << j << endl;

    // ... oder auch explizit.
    string s="2", t="3";
    myswap<string>(s,t);
    cout << "3)    s: " << s << ", t: " << t << endl;

    // Das geht nicht, da Typen unterschiedlich sind und das Template
    // nur einen Typen erwartet.
    // myswap(a,i);

    return 0;
}

