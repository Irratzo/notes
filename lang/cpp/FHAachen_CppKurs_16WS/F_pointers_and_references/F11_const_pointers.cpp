/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Verwendung von const, insbes. mit Zeigern
 * 
 *  Stichworte:
 *      - const, const_cast
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

#pragma GCC diagnostic ignored "-Wunused-but-set-variable"
#pragma GCC diagnostic ignored "-Wunused-variable"

int main()
{
    tools_log(); cout << "const und nicht-const variablen" << endl << endl;
    
	int i=1;                        // einfacher int
	int* pi = &i;                   // Zeiger auf int i
	const int ci=2;                 // const int
    const int* pci = &ci;           // Zeiger auf const int ci
//    pci =&i;
//    *pci = 12;
	// int const * pci = &ci;       // alternativ: Zeiger auf const int ci
    int* const pic = &i;            // const Zeiger auf int
	const int* const pcic = &ci;    // const Zeiger auf const int
	// pic und pcic sind Konstanten (als Zeiger) wogegen
    // pci auf einen konstanten int zeigt

    i = 3;              // OK, i nicht const
    *pi = 4;            // OK, i nicht konst
    pi = nullptr;       // OK, pi nicht const
    // ci = 5;          // NOK, ci const
    // *pci = 6;        // NOK, *pci const
    pci = nullptr;      // OK, pci nicht const
    *pic = 7;           // OK, i nicht const
    // pic = nullptr;   // NOK, pic const
    // *pcic = 8;       // NOK, *pcic const
    // pcic = nullptr;  // NOK, pcic const
    
    // const kann "entfern" werden, aber das Ergebnis ist mglw. unerwartet
    const int n = 123;

    // mit Zeigern
    int* pn = const_cast<int*>(&n);
    //int* pn = (int*)(&n);             // old-C-style
    *pn = 456;
    tools_log(); cout << "n=" << n << ", *pn=" << *pn << endl;

    // mit Referenzen
    int& rn = const_cast<int&>(n);
    rn = 789;
    tools_log(); cout << "n=" << n << ", rn=" << rn << ", *pn=" << *pn << endl;

    // warum?
    
    return EXIT_SUCCESS;
}

