/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema Lambda-Expressions
 * 
 *  Stichworte:
 *      - () => { }
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;

#include "../tools/tools.h"

bool test_expression(int n)
{
    return (n % 2) == 0;
}

int main()
{
    vector<int> v = { 1,3,5,6,7,8 };

    auto result1 = find_if(v.begin(), v.end(), test_expression);


    if (result1 != v.end()) {
        cout << "Erste gerade Zahl: " << *result1 << "." << endl;
    } else {
        cout << "Keine geraden Zahlen!" << endl;
    }

    auto result2 = find_if(v.begin(), v.end(),[](int n) { return (n % 2) == 0; });

    if (result2 != v.end()) {
        cout << "Erste gerade Zahl: " << *result2 << "." << endl;
    } else {
        cout << "Keine geraden Zahlen!" << endl;
    }
    
    double x1=1.0,x2=2.0;

    auto trapezrule = [=](function<double(double)>f)->double{return 0.5*(f(x2)+f(x1))*(x2-x1);};
    auto A = trapezrule([](double x)->double{return x*x;});

    cout << "A=" << A << endl;
    
    //auto s = [](double (*f[])(double),double x) -> {return f[0](x);};
    //cout << "sin 0.5 " << sin(0.5) << "," << s({sin},0.5) << endl;
    return EXIT_SUCCESS;
}

