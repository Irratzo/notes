/*	Author: A.Voss@FH-Aachen.de
 */

#include <iostream>
#include <iomanip>
using namespace std;

void f(bool firstCall);

int main()
{
    cout << endl << "---" << endl << endl;

    cout << "01) vor call f(true)" << endl;
 
    f(true);
 
    cout << "02) dazwischen" << endl;
 
    f(false);
 
    cout << "03) nach call f(false)" << endl;
 
    cout << endl << "---" << endl << endl;
   
    return EXIT_SUCCESS;
}

void f(bool firstCall) {
    int n=0;
    
    cout << "    f() - Adresse von main: " << hex << (void*)(&main) << dec 
         << ", Adresse von n, aka &n: " << hex << &n << dec << endl;
    
    // suche auf dem Stack Eintrag in der "Naehe" zu &main (=main)
    for (int i = 0; i < 20; ++i) {
        int* p = &n + i;
        long diff = ((long)(*p) - (long)(&main));
        if (-500<diff && diff<500) {
            cout << "    found at p: " << hex << p << dec << ", *p: " << hex << *p << dec << ", diff: " << (long)diff << endl;
            if (firstCall) {
                // die Differenz zwischen den zwei gefunden Stellen, was passiert?
                //*p += 38;
            }
        }
    }
    
}

