/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Die C-Methode, um eine variable Menge von Argumenten zu uebergeben.
 * 
 *  Stichworte:
 *      - varg, va_list, va_arg
 */

#include <iostream>
#include <cstdarg>
using namespace std;

#include "../tools/tools.h"

void sum_args(int n1, ...);
void show_alphabet(int count, ...);

int main()
{
    sum_args(1,'A'); // 2,4,8,0);
    //show_alphabet(3, 'A',65, 'B',66, 'C',67);

    return EXIT_SUCCESS;
}

// ein Argument muss vor den '...' immer angegeben werden und die Art und Weise
// festzustellen, wieviele Argumente/Parameter folgen, ist frei und muss
// selber festgelegt werden. 
// Hier bei 'sum_args' durch eine 0 am Ende und bei 'show_alphabet' 
// durch die Angabe der folgenden Paerchen zu Beginn

// alles aufsummieren, bis eine 0 als Par. folgt
void sum_args(int n1, ...)
{
    va_list l;
    va_start(l,n1);         // init list

    int n=n1,sum=0;
    while(n>0)
    {
        tools_log(); cout << "Param=" << n << endl;
        sum += n;
        n=va_arg(l,int);    // take next par
    }
    tools_log(); cout << "Summe=" << sum << endl << endl;
}

// zu Beginn die Anzahl von Paerchen angeben
void show_alphabet(int count, ...)
{
    va_list l;
    va_start(l,count);
    
    for (int i=0; i<count; ++i)
    {
        char c = (char)va_arg(l,int);  // char is stored as int!
        int  n = va_arg(l,int);
        tools_log(); cout << "Param=(" << c << "," << n << ")" << endl;
    }
}

