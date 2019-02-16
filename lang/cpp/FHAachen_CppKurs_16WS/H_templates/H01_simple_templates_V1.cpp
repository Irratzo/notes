/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema Templates
 */

#include <iostream>
#include <cstdlib>
#include <set>
#include <vector>
#include <limits>
#include <cmath>
using namespace std;

#include "../tools/tools.h"

int main()
{
    tools_log(); cout << "use of template classes" << endl;
    
    set<int> s = { 1,2,3 };				/*	set<int> ?
     * 	
     * 	Eine template (generic) class set, hier mit int-Elementen.
     * 	set modelliert eine (mathematische) Menge von Daten. Es gibt 
     * 	keine dopelten Elemente.
     */
    s.insert(4);
    tools_log(); cout << "size of s: " << s.size() << endl;

    vector<int> v = { 1,2,3,4 };
    v.push_back(5);
    tools_log(); cout << "size of v: " << v.size() << endl << endl;

	// Informationen zu Datentypen, hier int
    tools_log(); cout << "use of (statical) type info" << endl;
    tools_log(); cout << "  minimum value for int: " << numeric_limits<int>::min() << endl;
    tools_log(); cout << "  maximum value for int: " << numeric_limits<int>::max() << endl << endl;

    tools_log(); cout << "more (statical) type info" << endl;
    tools_log(); cout << "  is 'signed char' signed?   " << numeric_limits<signed char>::is_signed << endl;
    tools_log(); cout << "  is 'unsigned char' signed? " << numeric_limits<unsigned char>::is_signed << endl;
    tools_log(); cout << "  is 'char' signed?          " << numeric_limits<char>::is_signed << endl << endl;

    tools_log(); cout << "template functions" << endl;
    int a=5, b=6;
    
    tools_log(); cout << "  a=" << a << ", b=" << b << endl;
    swap(a,b);
    tools_log(); cout << "  a=" << a << ", b=" << b << endl;

    return EXIT_SUCCESS;
}

