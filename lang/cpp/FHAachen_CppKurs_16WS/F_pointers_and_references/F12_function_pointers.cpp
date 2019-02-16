/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Funktionszeiger
 * 
 *  Stichworte:
 *      - function pointer
 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#include "../tools/tools.h"

// das ist der Typ eines Funktionszeigers
typedef double (*func_t)(double);

// eine Beispielfunktion mit obiger Signatur
double negsin(double d) { return -sin(d); }

int main()
{
    double d = 3.14;
    func_t f = sin;   // das ist ein Funktionszeiger init. mit 'sin'
    
    tools_log(); cout << "sin(" << d << ")=" << sin(d) << endl;
    tools_log(); cout << "  f(" << d << ")=" << f(d) << endl;
    // strenggenommen ist f ja ein Zeiger, daher ist folgendes mgl.
    tools_log(); cout << "  f(" << d << ")=" << (*f)(d) << endl;
    
//    f = negsin;

    // so sieht die Definition aus, wenn kein typedef verwendet wird
    double (*g)(double) = sin;    
    tools_log(); cout << "  g(" << d << ")=" << g(d) << endl;

    // analog gibt es auch Funktionsreferenzen (nicht so bekannt)
    double (&h)(double) = sin;    
    tools_log(); cout << "  h(" << d << ")=" << h(d) << endl << endl;

    // was ist das?
    func_t fa[] = { sin, negsin, cos };
    // double (*fa[])(double) = { sin, negsin, cos };
    
    for (double x=0.0; x<M_PI+0.5; x+=0.5)  // M_PI in cmath
    {
        tools_log(); 
        for (unsigned int i=0; i<sizeof(fa)/sizeof(func_t); ++i)
        {
            // etwas formatierung (iomanip, folgt noch)
            cout << setprecision(2);
            cout << "fa[" << i << "](" << setw(3) << x 
                 << ")=" << setw(6) << fa[i](x) << " ";
        }
        cout << endl;
    }

    return EXIT_SUCCESS;
}

