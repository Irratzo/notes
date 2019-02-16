/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Weitere primitive Datentypen und ihre jeweilige Groesse.
 * 
 *  Stichworte:
 *      - printf, Formatstring fuer Fliesskommazahlen
 *      - Datentypen, float, double, long double 
 */

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#include "../tools/tools.h"

int main()
{   
    // Fliesskommazahlen
    
    float f = 1.23f;
    double d = 2.34;
    long double ld = 3.45;
    
    tools_log(); printf("f =%f, sizeof(float)=%zu\n",f,sizeof(float));
    tools_log(); printf("d =%f, sizeof(double)=%zu\n",d,sizeof(double));
    tools_log(); printf("ld=%Lf, sizeof(long double)=%zu\n",ld,sizeof(long double));

    return EXIT_SUCCESS;
}

