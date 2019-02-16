/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Verwendung von Referenzen (&) und Zeigern/Pointern
 * 
 *  Stichworte:
 *      - call by reference, call by value
 *      - deref.op *, address-op &, ref &
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

void swap1(double d1, double d2)		
/*	swap Vers. 1
 * 
 * 	Hier werden die Argumente vom Aufrufer kopiert, d.h. d1 und d2
 * 	sind zwei Kopien. Folglich koennen diese zwar getauscht werden,
 * 	die Variablen des Aufrufers, hier in main, aendern sich dadurch
 * 	natuerlich nicht.
 */
{
    double d = d1;
    d1 = d2;
    d2 = d;
}

void swap2(double *pd1, double *pd2)	
/*	swap Vers. 2
 * 
 * 	Dies ist die klassische Swap-Variante ueber Pointer auf die 
 * 	Variablen des Aufrufers. So findet ein Tausch statt, es muss
 * 	nur, wie bei Zeigern ueblich, jeweils dereferenziert werden.
 */
{
    double d = *pd1;
    *pd1 = *pd2;
    *pd2 = d;
}

void swap3(double &d1, double &d2)		
/*	swap Vers. 3
 * 
 * 	Dies sind zwei Referenzen (&) auf die Variablen des Aufrufers.
 * 	Eine Referenz ist ein Alias fuer die Variable, die sie referenziert.
 *	Sie wird anstelle der Variablen verwendet. Das folgende swap 
 * 	tauscht demnach die Variablen aus main, wie erwartet.
 * 	Die Funktion verhaelt sich daher wie die Pointer-Variante swap2,
 * 	nur mit schoenerer Syntax und ohne zu dereferenzieren. Ebenfalls
 * 	muss beim Aufruf nichts weiter angegeben werden.
 */
{
    double d = d1;
    d1 = d2;
    d2 = d;
}

int main()
{
    double d1, d2;
    
    d1 = 1.1, d2 = 2.2;
    tools_log(); cout << "Init.wert:  d1 = " << d1 << ", d2 = " << d2 << endl << endl;
    
    d1 = 1.1, d2 = 2.2;
    swap1(d1,d2);
    tools_log(); cout << "Nach swap1: d1 = " << d1 << ", d2 = " << d2 << " -> ???" << endl;
    
    d1 = 1.1, d2 = 2.2;
    swap2(&d1,&d2);
    tools_log(); cout << "Nach swap2: d1 = " << d1 << ", d2 = " << d2 << endl;
    
    d1 = 1.1, d2 = 2.2;
    swap3(d1,d2);
    tools_log(); cout << "Nach swap3: d1 = " << d1 << ", d2 = " << d2 << endl;

    // weitere Faelle fuer die Notwendigkeit von Zeigern oder Referenzen
    // sind mehrfache Rueckgaben von Werten, z.B. 
    //      calcsumandprod(int n, int m, int* psum, int* pprod)
    //      calcsumandprod(int n, int m, int& sum, int& prod)

    return EXIT_SUCCESS;
}

