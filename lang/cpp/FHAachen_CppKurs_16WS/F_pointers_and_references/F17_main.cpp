/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Ein Programm mit Parametern starten und Variablen vom Environment lesen
 * 
 *  Stichworte:
 *      - main args, getenv
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

int main(int argc, char* argv[]) 
{
    tools_log(); cout << "starte main mit " << argc << " Parametern" << endl;

    // Konvention: 0 ist command, argv[argc] ist nullptr/NULL
    for (int i=0; i<=argc; ++i)
    {
        tools_log(); cout << "  arg " << i 
                          << "='" << (argv[i]==nullptr ? "null" : argv[i])
                          << "'" << endl;
    }
    cout << endl;

    // Getopt oder Argp fuer mehr Parameter-parsing

    tools_log(); cout << "environment (Cmd: export A='text')" << endl;
    
    char *pcA = getenv("A");
    tools_log(); cout << "  A='" << (pcA==nullptr ? "null" : pcA) << "'" << endl;

    return EXIT_SUCCESS;
}

