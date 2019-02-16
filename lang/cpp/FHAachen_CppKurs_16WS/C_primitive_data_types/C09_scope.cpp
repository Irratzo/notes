/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Gueltigkeitsbereiche, scope
 * 
 *  Stichworte:
 *      - scope
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

int n = 1;  // globales n


int main()
{
    tools_log(); cout << "Ebene: main(), bisher nur global n=1 gesetzt:" << endl;
    tools_log(); cout << "n=" << n << ", &n=" << &n << endl << endl;

    tools_log(); cout << "nun in main n=2, k=3 gesetzt." << endl;
    int n = 2, k = 3;  // lokal, verdeckt globales n
    tools_log(); cout << "n=" << n << ", &n=" << &n 
                      << ", ::n=" << ::n << ", &::n=" << &::n 
                      << ", k=" << k << ", &k=" << &k << endl;
    tools_log(); cout << "*(&k-1)=" << *(&k-1) << ", &k-1=" << &k-1 << endl << endl;
    
    if (true)
    {
        cout << endl; tools_log(); cout << "\tEbene: main() > if(true)-Block" << endl;
        int n = 4, m = 5;   // lokal
        tools_log(); cout << "\tnun im block n=4, m=5 gesetzt." << endl;
        tools_log(); cout << "\tn=" << n << ", &n=" << &n 
                          << ", m=" << m << ", &m=" << &m
                          << ", ::n=" << ::n << ", &::n=" << &::n << endl;
        
        tools_log(); cout << "\t*(&k-1)=" << *(&k-1) << ", &k-1=" << &k-1 << endl << endl;
        *(&k-1)=6;  // uii?
        tools_log(); cout << "\tnun *(&k-1)=6 gesetzt (myExperiment)" << endl;
        tools_log(); cout << "\tn=" << n << ", &n=" << &n << endl;
        tools_log(); cout << "\t*(&k-2)=" << *(&k-2) << ", &k-2=" << &k-2 << endl;
    }   // end of scope
    
    cout << endl; tools_log(); cout << "Ebene: main()" << endl;
    // hier gibt es m nicht mehr!
    
    tools_log(); cout << "*(&k-1)=" << *(&k-1) << ", &k-1=" << &k-1 << endl;

    tools_log(); cout << "n=" << n << ", &n=" << &n 
                      << ", ::n=" << ::n << ", &::n=" << &::n 
                      << ", k=" << k << ", &k=" << &k << endl;
        
    return EXIT_SUCCESS;
}

