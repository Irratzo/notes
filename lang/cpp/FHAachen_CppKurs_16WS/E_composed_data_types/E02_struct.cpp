/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	In Strukturen zusammengefasste Datentypen, Referenz vs. Kopie
 * 
 *  Stichworte:
 *      - struct
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

// zwei Nummern
struct TelNr {
    int PreSel;
    int Number;
};

int main()
{
    // zwei Vars vom Typ TelNr
    TelNr t1, t2;
    
    // Initialisierung
    t1.PreSel = 0241;
    t1.Number  = 110;    
    t2.PreSel = 0202;
    t2.Number  = 112;
    
    // stimmen die Werte?
    tools_log(); cout << "t1=" << t1.PreSel << "/" << t1.Number << endl;
    tools_log(); cout << "t2=" << t2.PreSel << "/" << t2.Number << endl;

    // direkte Initialisierung (beides mgl)
    TelNr t3 { 2405, 1234 };
    TelNr t4 = { 201,  5678 };
    tools_log(); cout << "t3=" << t3.PreSel << "/" << t3.Number << endl;
    tools_log(); cout << "t4=" << t4.PreSel << "/" << t4.Number << endl << endl;

    // Definition im Code
    struct TelEintrag {
        string Name;
        TelNr Nr;
    };
    
    // etwas kompliziertere Initialisierung
    TelEintrag e { "Mueller", { 241,98765 } };
    tools_log(); cout << "Eintrag e: Name=" << e.Name 
                      << ", No=" << e.Nr.PreSel << "/" << e.Nr.Number << endl << endl;

    // f ist vom Typ TelEintrag und wird mit e initialisiert
    auto f = e;
    // jetzt wird e veraendert, welche Werte besitzt nun f?
    e.Name = "-"; e.Nr = { 0,0 };

    tools_log(); cout << "Eintrag e: Name=" << e.Name 
                      << ", No=" << e.Nr.PreSel << "/" << e.Nr.Number << endl;
    tools_log(); cout << "Eintrag f: Name=" << f.Name 
                      << ", No=" << f.Nr.PreSel << "/" << f.Nr.Number << endl;
    
    return EXIT_SUCCESS;
}

