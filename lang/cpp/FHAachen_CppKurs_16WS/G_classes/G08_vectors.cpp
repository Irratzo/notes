/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Verwendung von Templates und Klassen
 *  Ueberblick: http://www.cplusplus.com/reference/stl/
 * 
 *  Stichworte:
 *      - template, vector, stl
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>       // containers are part of the so-called 
using namespace std;

#include "../tools/tools.h"

int main()
{
    // a vector of ints -> type parameter <int>
    // initialization = { values ... } is a C++11-feature
    vector<int> v = { 4,5,6 };     
    
    // add some value at the end
    for (int i=0; i<3; ++i)
        v.push_back(i);
    tools_log(); cout << "v.size = " << v.size() << endl << endl;
    
    // replace a value
    v[1] = 23;
    
    // loops:
    tools_log(); cout << "loop with for:" << endl;
    for (unsigned int i=0; i<v.size(); ++i) 
    {
        tools_log(); cout << "   v[" << i << "] = " << v[i] << endl;
    }
    tools_log(); cout << "done" << endl << endl;

    tools_log(); cout << "loop with iterators:" << endl;
    for (vector<int>::iterator it = v.begin(); it!=v.end(); ++it) // const_iterator
    {
        tools_log(); cout << "   *it = " << *it << endl;
    }
    tools_log(); cout << "done" << endl << endl;
        
    tools_log(); cout << "loop with 'foreach':" << endl;
    for (auto n : v)    // C++11-feature
    {
        tools_log(); cout << "   n = " << n << endl;
    }
    tools_log(); cout << "done" << endl << endl;

    return EXIT_SUCCESS;
}

