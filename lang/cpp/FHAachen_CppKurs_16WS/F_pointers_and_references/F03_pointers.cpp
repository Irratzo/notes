/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Zeiger/Pointer
 * 
 *  Stichworte:
 *      - op *, op &, void*
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

// hier wird eine Referenz uebergeben, d.h. die Variable im Aufruf
// wird veraendert (vgl. swap in anderem Snippet)
void init(int* p)
{
    *p = 0;
}

int main()
{
    
    // Pointer sind Adressen von anderen Variablen, sie koennen nur
    // die Adresse (&) einer Var. enthalten; sie haben auch einen Typ (hier int)
    int n = 1, m = 2;
    int* pn = &n;
    
    // um auf die Inhalte der Variablen zuzugreifen, auf die sie zeigen
    // muss dereferenziert werden (*)
    *pn = 3;
    tools_log(); cout << "n=" << n << ", *pn=" << *pn << ", m=" << m << endl;
    n = 4;
    tools_log(); cout << "n=" << n << ", *pn=" << *pn << ", m=" << m << endl;
   
    // sie koennen neu gesetzt werden! was passiert?
    pn = &m;
    m = 5;
    tools_log(); cout << "n=" << n << ", *pn=" << *pn << ", m=" << m << endl;

    // sie werden bei der Parameteruebergabe benutzt, um 
    // (teuere) Kopien zu vermeiden
    init(&n);
    init(&m);
    tools_log(); cout << "n=" << n << ", *pn=" << *pn << ", m=" << m << endl;

    // das geht prinzipiell, warum und was passiert?
    // init((int*)3);
    
    // Pointer koennen auf 0 (null) gesetzt werden, dann ist dereferenzieren
    // aber nicht mehr moeglich
    pn = nullptr;   // frueher =0 oder =NULL
    tools_log(); cout << "n=" << n << ",  pn=" << pn << ", m=" << m << endl << endl;
    
    // mit Zeigern kann man rechnen und Unfug veranstalten ...
    int a=10, b=11, c=12;
    tools_log(); cout << "a=" << a << ", b=" << b << ", c=" << c << endl;
    
    // was passiert hier?
    pn = &b+1;
    *pn = 13;
    tools_log(); cout << "a=" << a << ", b=" << b << ", c=" << c << endl;
    
    // Erklaerungshilfe
    tools_log(); cout << "&a=" << &a << ", &b=" << &b << ", &c=" << &c << endl;
    tools_log(); cout << "&b+1=" << (&b+1) << endl << endl;
    
    // Zeigerarithmetik (p+1) ist vollkommen legal, siehe Beispiel arrays,
    // nur das Manipulieren "fremden" Speichers fuehr zu unbestimmtem Verhalten
    
    // Pointer auf ein double, vollkommen analog
    double d = 3.1415926;
    double* pd = &d;
    
    tools_log(); cout << "d=" << d << ", *pd=" << *pd << endl;
    
    // es gibt auch Pointer ohne Typ, folglich ist dereferenzieren (*) nicht moeglich
    void* vp = pd;
    tools_log(); cout << "vp=" << vp << ", pd=" << pd << endl;
    
    return EXIT_SUCCESS;
}

