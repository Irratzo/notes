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
 
    double x1=1.0,x2=2.0;
    // note: "[=]" captures all values by copy, "[&]" by reference
    auto trapezrule = [=](function<double(double)> f)
                      {return 0.5*(f(x2)+f(x1))*(x2-x1); };
    
    double A;
    auto lambda_x2 = [](double x) -> auto {return x*x;};
    A = trapezrule(lambda_x2);
    tools_log(); cout << "integral(x^2)_[a,b] = " << A << endl;
    
    A = trapezrule([](double x){return x*x*x;});
    tools_log(); cout << "integral(x^3)_[a,b] = " << A << endl;
    
    return EXIT_SUCCESS;
}

