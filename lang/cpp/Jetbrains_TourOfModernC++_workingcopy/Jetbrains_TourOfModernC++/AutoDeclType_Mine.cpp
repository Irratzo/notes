/*
 * Self-written file for 
 * Jetbrains Tour of Modern C++
 */

/* 
 * File:   AutoDeclType_Mine.cpp
 * Author: johannesw
 *
 * Created on 3. Januar 2017, 16:14
 */
#include "Headers.h"
#include "AutoDeclType_Mine.h"

/**
 * Jetbrains Tour of Modern C++ - Example 02
 */
void autoDeclType_example() {
    auto a = 0; //inferred to be int
    auto b = 123.f; //inferred to be float
    auto c = L"hello"; //inferred to be: const wchar_t * c (IntelliJ), const const char * (Netbeans)

    /*
     * The L prefix above specifies c as const wchar_t * instead of const char *:
     */

    map<string, vector<double>> ticks;
    map<string, vector<double>>::iterator it1 = ticks.begin(); //old way
    auto it = ticks.begin(); //new way
    
}

/**
 * Jetbrains Tour of Modern C++ - Example 03
 * auto-return type example function which is included elsewhere via header: 
 * must use C++11-style (auto with trailing lambda specifying return type).
 * @return 
 */
auto meaning_of_life_C11() -> int{
    return 42;
}
