/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema move, move assignment, r- und l-value
 * 
 *  Stichworte:
 *      - &&
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

#include "../tools/tools.h"

/*	rvalues, lvalues
 * 	Es gibt lvalues und rvalues (locator value).
 * 	Ein lvalue ist etwas, was eine Adresse hat, dem man etwas
 * 	zuweisen kann.
 * 	Ein rvalue ist etwas, was kein lvalue ist. Z.B. ein temp. Objekt.
 * 
 * 	Es gibt noch mehr, etwa xvalues, siehe
 *	http://en.cppreference.com/w/cpp/language/value_category
 */

int m = 42;								/* glob. variable
 * 
 * besitzt eine Adresse.
 */

int & set_m() { return m; }				/* ref. auf m
 * 
 * 	ist ein Alias fuer m, besitzt eine Adresse.
 */

string get_name() { return "Smith"; }	/* temp. Objekt
 * 
 * 	wird zurueckgegeben, also kein lvalue.
 */

/*	Zwei Varianten einer Funktion
 * 
 * 	Eine fuer lvalues (&), eine fuer rvalues (&&).
 * 	Gibt es die rvalue-Variante nicht, wird immer die lvalue-Variante
 * 	verwendet.
 */
void f(const string& s)  { 
    tools_log(); cout << "ref  f&  s: " << s << endl; 
}

void f(const string&& s) { 
    tools_log(); cout << "move f&& s: " << s << endl; 
}

int main()
{
    int n{};

    tools_log(); cout << "start    n=" << n << ", m=" << m << endl;

    n = 1;          // n (lvalue)
    set_m() = 23;   // lvalue, der nicht direkt eine Variable ist
    tools_log(); cout << "assigned n=" << n << ", m=" << m << endl;
    
    string s;
    s = get_name(); // get_name liefert einen rvalue
    
    f(s);			// lvalue-Variante
    f(get_name());	// rvalue-Variante
    
    // Zum Test die rvalue-Variante auskommentieren.

    return EXIT_SUCCESS;
}

