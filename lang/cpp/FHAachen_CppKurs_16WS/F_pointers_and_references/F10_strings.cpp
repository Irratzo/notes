/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	C++-string Funktionen
 * 
 *  Stichworte:
 *      - C++-string, size, find, op+, c_str
 */

#include <iostream>
#include <string>
using namespace std;

#include "../tools/tools.h"

int main()
{
    string msg1 = "Dies ist ein Satz.";	// 18 chars, ohne \0

    tools_log(); cout << "msg1=\"" << msg1 << "\"" << endl;
    tools_log(); cout << "len=" << msg1.size() << endl;

    // kopiere
    string msg2(msg1); // msg2 = msg1;
    tools_log(); cout << "msg2=\"" << msg2 << "\"" << endl;
    
	// jetzt mit C++-string Funktionen
    
    string p = msg1+msg2;
    tools_log(); cout << "p=\"" << p << "\"" << endl;
	
    size_t pos = msg1.find('S');
    tools_log(); cout << "pos. of 'S'=" << pos << endl << endl;	
    
    // ein string kann fuer C-string Funktionen (read-only) verwendet werden
    tools_log(); cout << "msg1-C-string=\"" << msg1.c_str() << "\"" << endl;
    
    return EXIT_SUCCESS;
}

