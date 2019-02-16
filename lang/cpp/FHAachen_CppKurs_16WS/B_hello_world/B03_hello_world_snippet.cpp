/*	Author: A.Voss@FH-Aachen.de 
 * 
 * 	Ein typisches Kurs-C++-Snippet.
 * 
 *  Stichworte:
 *      - #include "../tools.h", tools_log()
 */

#include <iostream> 
#include <cstdlib>
using namespace std;

// Funktionen wie tools_log() werden bekannt gemacht
#include "../tools/tools.h"

int main()
{
    // zu Beginn wird "--- '<src.file>' ..." ausgegeben

    // so kann man die Zeile im Source-Code mit der Ausgabe verbinden
    tools_log(); cout << "Hello Course !" << endl;

    // am Ende wird "--- '<src.file>' ---" ausgegeben
    return EXIT_SUCCESS;
}

