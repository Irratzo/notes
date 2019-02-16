/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Felder/Arrays
 * 
 *  Stichworte:
 *      - op[], Zeigerarithmetik
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

int sum(int zeile[], size_t dimx);

int main()
{
    int a[5] = { 2,3,5,7,11 };

    // Ausgabe aller Elemente
    tools_log(); cout << "a={ ";
    for (auto n : a)
        cout << n << " ";
    cout << "}" << endl;
    
    // Vorsicht!
    // int* pa, pb;
    int *pa, *pb;
    
    // was wird ausgegeben?
    pa = a+1;
    pb = pa+2;
    tools_log(); cout << "*pa=" << *pa << ", *pb=" << *pb << endl;
    
    // initialisierung geht auch so:
    int z[] = { -1, -2, -3 };
    const size_t len_z = sizeof(z)/sizeof(int);
    tools_log(); cout << "len_z=" << len_z << ", sizeof z=" << sizeof(z) << endl << endl;

    // mehrdimensionale Felder
    const size_t dimx=2, dimy=3;
    int f[dimy][dimx] = { {1,2}, {3,4}, {5,6} };
    
    // zeilenweise ausgeben
    for (size_t y=0; y<dimy; ++y)
    {
        tools_log(); cout << "f[" << y << "] = [ ";
        for (size_t x=0; x<dimx; ++x)
            cout << f[y][x] << " ";
        cout << "]" << endl;
    }
    
    // wie liegen diese im Speicher? starte beim ersten
    int* pf = &f[0][0];
    tools_log(); cout << "flat f=[ ";
    for (size_t i=0; i<dimy*dimx; ++i)
        cout << *(pf+i) << " ";
    cout << "]" << endl;
    
    // arrays als Parameter sind moeglich, bei mehrdim.
    // muessen alle Dimensionen ausser der letzten angegeben werden
    int s = sum(f[1],dimx);
    tools_log(); cout << "sum f[1]=" << s << endl;
    
    // was tun, wenn Laenge zur Compilezeit unbekannt?
    
    return EXIT_SUCCESS;
}

int sum(int zeile[], size_t dimx)
//int sum(int* zeile, size_t dimx)      // aequivalent
{
    int s=0;
    for (size_t x=0; x<dimx; ++x)
        s+=zeile[x];
    return s;
}
