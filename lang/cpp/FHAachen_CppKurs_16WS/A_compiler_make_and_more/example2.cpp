/*  Author: A.Voss@FH-Aachen.de
 *
 *  Ein einfaches C++-Programm.
 * 
 *  Uebersetzen im Terminal-Fenster (LXTerminal)
 *  > g++ example2.cpp -o example2.out
 *  ergibt "example2.out", ausfuehrbar mit
 *  > ./example2.out
 */

#include <iostream>
using namespace std;

int main()
{
    cout << "Hallo Kurs!" << endl;   

    int i = 2;
    
    cout << "i=" << i << " und nochmal i=" << i << "!!!" << endl;
            
    return 0;
}

