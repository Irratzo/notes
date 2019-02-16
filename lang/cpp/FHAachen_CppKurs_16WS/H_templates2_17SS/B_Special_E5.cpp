// author: a.voss@fh-aachen.de

#include <iostream>
#include <set>
#include <vector>
using namespace std;

// Spezialisierung funktioniert auch bei Funktionen
template <typename T>
T Inverse(const T & t) { return (T)1/t; }

// Berechne "Inverse" fuer chars wie folgt: A -> Z, B -> Y und vice versa
template <>
char Inverse(const char & t) { return (char)(90-(int)t+65); }


int main() {
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

	cout << "1)    0.1 ^-1  = " << Inverse(0.1) << endl;

	cout << "1)    10  ^-1  = " << Inverse(10.0) << endl;

	cout << "1)    'B' ^-1  = " << Inverse('B') << endl << endl;
     
    return 0;
}

