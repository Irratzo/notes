/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Mathematikfunktionen
 *  Achtung: man braucht im makefile die math-lib: Linkoption '-lm'
 * 
 *  Stichworte:
 *      - sin,cos,tan,sinh,asin,log,log10,exp,fabs,floor,ceil
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#include "../tools/tools.h"

int main()
{
    tools_log(); cout << "ein paar Mathematikfunktionen" << endl << endl;
    
    double d = 0.567;

    // examples - see (c)math.h for more
    
    cout << setprecision(3);
    tools_log(); cout << "    sin(" << d << ")=" << setw(6) << sin(d) << endl;
    tools_log(); cout << "   asin(" << d << ")=" << setw(6) << asin(d) << endl;
    tools_log(); cout << "   sinh(" << d << ")=" << setw(6) << sinh(d) << endl;

    tools_log(); cout << "   fabs(" << d << ")=" << setw(6) << fabs(d) << endl;
    tools_log(); cout << "   ceil(" << d << ")=" << setw(6) << ceil(d) << endl;
    tools_log(); cout << "  floor(" << d << ")=" << setw(6) << floor(d) << endl;

    tools_log(); cout << "    exp(" << d << ")=" << setw(6) << exp(d) << endl;
    tools_log(); cout << "    log(" << d << ")=" << setw(6) << log(d) << endl;
    tools_log(); cout << "  log10(" << d << ")=" << setw(6) << log10(d) << endl;

    return EXIT_SUCCESS;
}

