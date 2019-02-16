/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Referenzen
 * 
 *  Stichworte:
 *      - ref &
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

// hier wird eine Referenz uebergeben, d.h. die Variable im Aufruf
// wird veraendert (vgl. swap in anderem Snippet)
void init(int& k)
{
    k = 0;
}

int main()
{
    // Referenzen sind Aliase fuer andere Variablen
    int n = 1, m = 2;
    int& rn = n;
    
    rn = 3;
    tools_log(); cout << "n=" << n << ", rn=" << rn << ", m=" << m << endl;
    n = 4;
    tools_log(); cout << "n=" << n << ", rn=" << rn << ", m=" << m << endl;
   
    // sie koennen nicht neu gesetzt werden! was passiert?
    rn = m;
    m = 5;
    tools_log(); cout << "n=" << n << ", rn=" << rn << ", m=" << m << endl;

    // haeufig werden sie bei der Parameteruebergabe benoetigt, um 
    // (teuere) Kopien zu vermeiden
    init(n);
    init(m);
    tools_log(); cout << "n=" << n << ", rn=" << rn << ", m=" << m << endl;

    // das geht nicht, warum?
    // init(3);
    
    // Referenzen koennen nicht auf 0 (null) gesetzt werden
    
    return EXIT_SUCCESS;
}

