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

typedef double (*polynom_t)(double x);

double x3(double x) { return x*x*x; }

double eval(polynom_t p, double x)
{
	return p(x);
}

/*
double eval(function<double(double)> p, double x)
{
	return p(x);
} */

int main()
{
	// Variante 1
    tools_log(); cout << "2.0 ^ 3 = " << eval(x3,2.0) << endl;

	// Variante 2a und 2b, mit lambda-expression; merke: x->x^2
    tools_log(); cout << "2.0 ^ 3 = " << eval([](double x) -> double {return x*x*x;},2.0) << endl;
    tools_log(); cout << "2.0 ^ 3 = " << eval([](double x){return x*x*x;},2.0) << endl;

    auto lambda_x3 = [](double x){return x*x*x;};
	// Variante 3, ebenso
    tools_log(); cout << "2.0 ^ 3 = " << eval(lambda_x3,2.0) << endl;

	function<double(double)> func_x3 = [](double x){return x*x*x;};
	// Variante 4, ebenso
    //tools_log(); cout << "2.0 ^ 3 = " << eval(func_x3,2.0) << endl;

    tools_log(); cout << "end of main" << endl;
    
    return EXIT_SUCCESS;
}

