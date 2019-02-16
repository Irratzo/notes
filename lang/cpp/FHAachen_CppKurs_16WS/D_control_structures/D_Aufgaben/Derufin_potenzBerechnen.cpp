/*
 * FH Aachen Cpp 16WS
 * Aufgabe Derufin
 * Autor: Johannes Wasmer
 * Datum: 31.01.2017
 * 
 * Aufgabe: "Berechnen Sie b^n (b hoch n) für feste natürliche Zahlen b und n 
 * und geben das Ergebnis aus. Lesen Sie b und n von der Konsole ein. Schreiben 
 * Sie eine Funktion Pot, die b und n übergeben bekommt und das Ergebnis 
 * zurückgibt und ausgibt."
 * 
 * Anmerkung zur Lösung: Die Lösung nutzt uint64_t und verhindert Integer 
 * Overflow, indem die Berechnung zuvor abgebrochen wird.
 */

#if defined(_WIN32) || (defined(__APPLE__) && defined(__MACH__))
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional> //for Lambdas, Lambdas_Mine
#include <memory>
#include <type_traits>
#include <initializer_list> //for AutoDeclType, AutoDeclType_Mine
#else
#include <bits/stdc++.h>
#endif

using namespace std;

/**
 * Computes the power.
 * 
 * DEVNOTE: Another way to check for Integer Overflow is to use Clang / GCC builtin function
 * if (__builtin_umull_overflow(b,res,&intermedresult) == 0){ //no overflow} else { //Integer Overflow intermedresult }
 * Signature "umull": u: unsigned, mul: multiplication, l: long.
 * 
 * @param b base
 * @param n exponent
 * @return power or nearest computable power avoiding Integer overflow
 */
uint64_t Pot(unsigned int b, unsigned int & n) {
    uint64_t res{1};
    unsigned int m{0};
    cout << "n is " << n << endl;
    for (unsigned int i = 0; i < n; i++) {

        if (res > numeric_limits<uint64_t>::max() / b) {
            cout << "Integer overflow imminent, returning nearest computable power." << endl;
            n = m;
            return res;
        }

        res *= b;
        m++;
    }

    return res;

}

int main() {

    while (true) {
        //Berechnen Sie b^n (b hoch n) für feste natürliche Zahlen b und n und
        //geben das Ergebnis aus
        cout << "Provide input like: 10^23, or 'quit'" << endl;
        string line;
        getline(cin, line);
        if (line == "quit") {
            break;
        }
        size_t sepIndex = line.find("^");
        if (sepIndex == string::npos) {
            cout << "Error: No caret sign (Zirkumflex) provided as indicated." << endl;
            continue;
        }

        unsigned int b = stoi(line.substr(0, sepIndex));
        unsigned int n = stoi(line.substr(sepIndex + 1, string::npos));

        uint64_t pot = Pot(b, n);
        printf("C output:   Power %u^%u = %ld\n", b, n, pot); //unreliable output!
        cout << "C++ output: Power " << b << "^" << n << " = " << pot << endl; //reliable!

    }

    return 0;
}


