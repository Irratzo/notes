/*
 * FH Aachen Cpp 16WS
 * Aufgabe Derufin
 * Autor: Johannes Wasmer
 * Datum: 31.01.2017
 * 
 * Aufgabe: "Berechnen Sie die ersten Fibonacci-Zahlen bis zu einem Index n, den
 * Sie von der Konsole einlesen, nicht-rekursiv in einer Schleife und geben Sie 
 * die Zahlen aus.  Formulieren Sie die Schleife als for, do-while und while-
 * Schleife. Berechnen Sie die Folge rekursiv."
 * 
 * Themen: cin, Datentypen, Schleifen, Funktionsaufrufe
 * 
 */

#if defined(_WIN32) || (defined(__APPLE__) && defined(__MACH__))
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <functional> //for Lambdas
#include <memory>
#include <type_traits>
#include <initializer_list> //for AutoDeclType
#else
#include <bits/stdc++.h>
#endif

using namespace std;

int fib_recursive_inner(int n) {
    if (n > 1) {
        return fib_recursive_inner(n - 2) + fib_recursive_inner(n - 1);
    } else if (n == 1)
        return 1;
    return 0;
}

vector<int> fibonacci_recursive(int lim) {

    vector<int> fib; //vector<int> fib(); would be a function declaration!

    int n{0};
    while (n <= lim) {
        fib.push_back(fib_recursive_inner(n));
        n++;
    }

    return fib;
}

vector<int> fibonacci_nonrecursive_for(int lim) {
    vector<int> fib;

    int a{};
    int b{1};
    int buf{};

    for (int n = 0; n <= lim; n++) {
        fib.push_back(a);
        buf = a;
        a = b;
        b += buf;
    }


    return fib;
}

vector<int> fibonacci_nonrecursive_dowhile(int lim) {
    vector<int> fib;

    int n{};
    int a{};
    int b{1};
    int buf{};

    do {
        fib.push_back(a);
        buf = a;
        a = b;
        b += buf;
        n++;

    } while (n <= lim);

    return fib;
}

vector<int> fibonacci_nonrecursive_while(int lim) {
    vector<int> fib;

    int n{};
    int a{};
    int b{1};
    int buf{};

    while (n <= lim) {
        fib.push_back(a);
        buf = a;
        a = b;
        b += buf;
        n++;
    }

    return fib;
}

int main() {

    while (true) {
        cout << "Provide upper limit, like '13789', or 'quit'." << endl;
        string input{};
        cin >> input;
        if (input == "quit") {
            break;
        }

        //init variables
        int lim = stoi(input); //5

        vector<int> fib_req = fibonacci_recursive(lim);
        vector<int> fib_nonreq_for = fibonacci_nonrecursive_for(lim);
        vector<int> fib_nonreq_dowhile = fibonacci_nonrecursive_dowhile(lim);
        vector<int> fib_nonreq_while = fibonacci_nonrecursive_while(lim);

        cout << "Fib seq recursive:                   ";
        for (auto f : fib_req) {
            cout << f << ", ";
        }
        cout << endl;

        cout << "Fib seq nonrecursive, for-loop:      ";
        for (auto f : fib_nonreq_for) {
            cout << f << ", ";
        }
        cout << endl;

        cout << "Fib seq nonrecursive, do-while-loop: ";
        for (auto f : fib_nonreq_dowhile) {
            cout << f << ", ";
        }
        cout << endl;
        
        cout << "Fib seq nonrecursive, while-loop:    ";
        for (auto f : fib_nonreq_while) {
            cout << f << ", ";
        }
        cout << endl;

        cout << endl;
    }
    return 0;
}


