/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema Lambda-Expressions
 * 
 *  Stichworte:
 *      - () => { }
 */

#include <iostream>
#include <cstdlib>
using namespace std;

#include "../tools/tools.h"

int main()
{
    // a simple lambda function
    auto add4 = [](int n) { return n+4; };
    tools_log(); cout << "add4(8)=" << add4(8) << endl << endl; 
    
    int n = 5;
    // a lambda expression with a reference par. and no return type
    auto inc = [](int & n) {  ++n; };
    inc(n);
    tools_log(); cout << "n=" << n << endl << endl; 

    // a lambda expression, where m is unknown ... copy m
    int m = 12;
    auto addtom = [=](int n) { return m+n; };
    tools_log(); cout << "m=" << m << ", addtom(3)=" << addtom(3) << endl << endl; 

    m = 13;
    tools_log(); cout << "m=" << m << ", addtom(3)=" << addtom(3) << endl << endl; 
    
    // a lambda expression, where m is set ... ref of m
    auto setm = [&](int n) { m=n; };        // or [&m]
    tools_log(); cout << "m=" << m << endl; 
    setm(5);
    tools_log(); cout << "m=" << m << endl << endl; 

    // another syntax with return type explicitely given
    auto pi = []() -> double { return 3.1415926; };
    tools_log(); cout << "pi=" << pi() << endl << endl; 
    
    return EXIT_SUCCESS;
}

