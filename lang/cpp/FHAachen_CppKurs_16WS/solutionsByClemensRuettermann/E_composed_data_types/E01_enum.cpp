/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Aufzaehlungstypen
 * 
 *  Stichworte:
 *      - enum
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

// eigene Aufzaehlungstypen, z.B.
enum GamePlayer { Unknown, Player1, Player2 };
enum Cards { Invalid=-1, Seven=7, Eight=8, Ace=11, Last };
// wofuer? welcher Datentyp intern?

int main()
{
    tools_log(); cout << "Player: Unknown=" << Unknown 
                      << ", Player1=" << Player1
                      << ", Player2=" << Player2 << endl;
    tools_log(); cout << "Cards: Seven=" << Seven
                      << ", Eight=" << Eight
                      << ", Ace=" << Ace
                      << ", Last=" << Last << endl << endl;
                      
    // Variablen dieses Typs
    GamePlayer player = Player1;
    
    tools_log(); cout << "player=" << player << endl;
    player = Player2;
    tools_log(); cout << "player=" << player << endl << endl;
    
    Cards card1,card2;
    card1 = Seven;
    card2 = Eight;
    tools_log(); cout << "card1=" << card1 << ", card2=" << card2 << endl;
    
    // Konvertierung in int kein Problem, und andersherum?
    int n = card1;
    tools_log(); cout << "n=" << n << endl;
    card1 = (Cards)8;
    card2 = static_cast<Cards>(-2); // geht das?
    tools_log(); cout << "card1=" << card1 << ", card2=" << card2 << endl;

    return EXIT_SUCCESS;
}

