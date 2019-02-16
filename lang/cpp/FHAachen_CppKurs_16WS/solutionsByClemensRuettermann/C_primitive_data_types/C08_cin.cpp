/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Dateneingabe
 * 
 *  Stichworte:
 *      - cin
 *      - stoi, stol, stod, stof
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

int main()
{
    int n;
    tools_log(); cout << "Eingabe (int) n:";
    cin >> n;
    tools_log(); cout << "n=" << n << endl;
    
    string s;
    tools_log(); cout << "Eingabe (string) s:";
    cin >> s;
    // Umwandlung in int, analog stod fuer double etc.
    n = stoi(s);
    tools_log(); cout << "s=" << s << ", als int:" << n << endl;
    

    double d,e;
    tools_log(); cout << "Eingabe (double) d,e:";
    cin >> d >> e;
    tools_log(); cout << "d=" << d << ", e=" << e << endl;
    
    return EXIT_SUCCESS;
}

