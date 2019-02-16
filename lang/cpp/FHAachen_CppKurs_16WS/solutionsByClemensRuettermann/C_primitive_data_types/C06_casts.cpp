/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Typumwandlungen 
 * 
 *  Stichworte:
 *      - cast, static_cast, cmath, round, lround
 */

#include <iostream>
#include <cmath>
using namespace std;

#include "../tools/tools.h"

int main()
{
    char c = 'A';
    int n = 66;
    unsigned int u = 97;
    
    tools_log(); cout << "c=" << c << ", n=" << n << endl;
    
    // Umwandlungen hier ohne weitere Massnahmen moeglich
    c = 67;
    n = 'D';
    tools_log(); cout << "c=" << c << ", n=" << n << endl;
    
    //#pragma GCC diagnostic ignored "-Wconversion"
    c = u;  // erzeugt Warnung
    n = u;  // dies nicht
    tools_log(); cout << "c=" << c << ", n=" << n << endl;
    
    // folgende aequivalente Moeglichkeiten zum expliziten cast ohne Warnung
    c = (char)u;
    c = char(u);
    c = static_cast<char>(u);
    
    cout << endl;
    
    double d = 3.1415;
    float f = 2.71f;
    
    tools_log(); cout << "f=" << f << ", d=" << d << endl;
    
    //#pragma GCC diagnostic ignored "-Wfloat-conversion"
    f = d;  // Warnung
    f = (float)d;
    f = float(d);
    f = static_cast<float>(d);

    cout << endl;
    
    d = 1.9999;
    n = d;
    tools_log(); cout << "n=" << n << endl;
    
    // korrekter Weg seit C++11
    n = (int)lround(d);
    tools_log(); cout << "n=" << n << endl;
    
    return EXIT_SUCCESS;
}

