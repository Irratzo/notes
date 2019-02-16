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
    tools_log(); cout << "n=" << n << ", &n=" << &n << endl;
    
    int n = 2, k = 3;  // lokal, verdeckt globales n
    tools_log(); cout << "n=" << n << ", &n=" << &n 
                      << ", ::n=" << ::n << ", &::n=" << &::n 
                      << ", k=" << k << ", &k=" << &k << endl;
    
    if (true)
    {
        int n = 4, m = 5;   // lokal
        tools_log(); cout << "n=" << n << ", &n=" << &n 
                          << ", m=" << m << ", &m=" << &m
                          << ", ::n=" << ::n << ", &::n=" << &::n << endl;
             
        //*(&k-1)=6;  // uii?
    }   // end of scope
    // hier gibt es m nicht mehr!

    tools_log(); cout << "n=" << n << ", &n=" << &n << ", ::n=" << ::n << ", &::n=" << &::n << endl;
        
    return EXIT_SUCCESS;
}

