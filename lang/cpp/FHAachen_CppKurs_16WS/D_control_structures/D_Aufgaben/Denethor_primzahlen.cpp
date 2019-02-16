/*
 * FH Aachen Cpp 16WS
 * Aufgabe Derufin
 * Autor: Johannes Wasmer
 * Datum: 31.01.2017
 * 
 * Aufgabe: "Berechnen Sie b^n (b hoch n) für feste natürliche Zahlen b und n 
 * und geben das Ergebnis aus."
 * Tipp: modulo %.
 * 
 * Themen: Datentypen, Schleifen, cin, cout 
 * 
 * Anmerkung zur Lösung: Eigenimplementation des Sieb von Erastothenes. Modulo 
 * nicht verwendet. Eliminiert Nichtprimzahlen durch iterative Elimination von
 * Vielfachen von a, beginnend ab a^2.
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
        cout << "Provide upper limit, like '13789', or 'quit'." << endl;
        string input{};
        cin >> input;
        if (input == "quit") {
            break;
        }

        //init variables
        unsigned int lim = stoi(input); //5
        //static memory allocation, forbidden with arrays: int nums [lim] = {}; //[0,0,0,0,0]
        int* nums = new int[lim]; //dynamic memory allocation because of runtime-determined lim 
        //even better would be to use STL:         vector<int> nums(lim);

        //comments: example input "8"
        //(,,: outer loop; ,: inner loops)
        for (unsigned int i = 0; i < lim; i++) {
            nums[i] = i + 1; //[1,2,3,4,5,6,7,8]
        }
        unsigned int current = 2;

        while (current < lim) { //2<=8, 3<=8

            unsigned int quad = current * current; //4,, 9
            if (quad > lim) {// 4<8, 9>8
                break;
            }

            unsigned int vf = quad; //4,,
            while (vf <= lim) { // 4<=8, 6<=8, 8<=8, 10>8 
                nums[vf - 1] = 0; //[1,2,3,0,5,6,7,8], [1,2,3,0,5,0,7,8], [1,2,3,0,5,0,7,0]
                vf += current; //6, 8, 10
            }

            //find next unmarked
            for (unsigned int i = current + 1; i < lim; i++) { //i=3,,
                if (nums[i - 1] != 0) { //nums[2]=3,,
                    current = nums[i - 1]; //current = 3,,
                    break;
                }
            }
        }

        cout << "Primes: ";
        for (unsigned int i = 0; i < lim; i++) {
            if (nums[i] != 0) {
                cout << nums[i];
                if (i < lim - 1) {
                    cout << ", ";
                }
            }
        }
        cout << endl << endl;
    }
    return 0;
}


