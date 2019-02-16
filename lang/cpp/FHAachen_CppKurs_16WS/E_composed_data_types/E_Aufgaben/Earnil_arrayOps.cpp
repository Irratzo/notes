/*
 * FH Aachen Cpp 16WS
 * Aufgabe Duilin
 * Autor: Johannes Wasmer
 * Datum: 06.07.2017
 * 
 * Aufgabe: 
 * • Legen Sie ein (globales) Array der Länge 3 von doubles an.
 * • Lesen Sie das erste und zweite Element von der Konsole ein und spei-
 * chern Sie die Summe in dem dritten Element.
 * • Geben Sie alle Elemente in einer Funktion aus.
 * • Legen Sie ein weiteres Array der gleichen Größe an und kopieren Sie
 * das erste in das zweite Array in einer Funktion.
 * 
 * 
 * Themen: arrays
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

int main(int argc, char* argv[]) {
    
//    double *arr = new double[3]; C++-style array
    double arr[argc]; //C-style array
    
    int len = argc;
    //but normally, would calc length by:
    len = sizeof(arr) / sizeof(*arr); //for C-style array
    
    for (int i=0; i < argc; i++){
        arr[i] = stod(argv[i]); //std::stod C++11
        //source: https://stackoverflow.com/a/29328588/8116031
    }
    
    cout<< "last entry is sum of preceding entries. Calculate...";
    double sum = .0;
    for (int i=0; i< len-1; i++){
        sum += arr[i];
    }
    arr[len-1] = sum;
    
    cout << "Output array:";
    for (int i=0; i<len; i++){
        cout << arr[i] << " " << endl;
    }
    
    
    return 0;
}