/*
 * FH Aachen Cpp 16WS
 * Aufgabe Duilin
 * Autor: Johannes Wasmer
 * Datum: 07.02.2017
 * 
 * Aufgabe: "Lesen Sie Text von der Konsole ein und versuchen Sie diesen in int,
 * float und double Zahlen umzuwandeln. Benutzen Sie dazu die Funk-
 * tionen stoi, stof und stod. Konvertieren Sie das Ergebnis zurück in
 * einen String mittels to_string. Was passiert bei fehlerhaften Eingaben?"
 * 
 * Themen: cin, Strings, Konvertierung
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

int main() {

    while (true) {
        cout << "Provide (preferably) a number, or 'quit'." << endl;
        string input{};
        cin >> input;
        if (input == "quit") {
            break;
        }

        //try conversions
        int ini = stoi(input);
        cout << "str    -> int" << endl;
        float fof = stof(input);
        cout << "str    -> float" << endl;
        double dod = stod(input);
        cout << "str    -> double" << endl;
        
        string isi = to_string(ini);
        cout << "int    -> str" << endl;
        string fsf = to_string(fof);
        cout << "float  -> str" << endl;
        string dsd = to_string(dod);
        cout << "double -> str" << endl;
        
        cout << "Results stoX():      " << ini << ", " << fof << ", " << dod << endl;
        cout << "Results to_string(): " << isi << ", " << fsf << ", " << dsd << endl;

    }

    return 0;
}

