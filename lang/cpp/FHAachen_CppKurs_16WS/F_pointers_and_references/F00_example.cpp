/*	Author: A.Voss@FH-Aachen.de
 * 
 *  Beispiel
 * 
 *  Stichworte:
 *      - pointer, memory
 */

#include <iostream>
#include <iomanip>
using namespace std;

#include "../tools/tools.h"

int main()
{
    int sum = 254; // 0xff;
    tools_log(); cout << "sum = " << hex << sum << ", &sum = " << &sum << dec << endl;

    short age = -2;
    tools_log(); cout << "age = " << hex << age << ", &age = " << &age << dec << endl;

    double avr = 4.45015e-308;
    tools_log(); cout << "avr = " << avr << ", &avr = " << &avr << endl;

    int* ptrsum = &sum;
    tools_log(); cout << "ptrsum = " << hex << ptrsum << ", &ptrsum = " << &ptrsum << dec << endl;

    // again and again and again
    if (true) {
        int** ptrptrsum = &ptrsum;
        tools_log(); cout << "ptrptrsum = " << hex << ptrptrsum << ", &ptrptrsum = " << &ptrptrsum << dec << endl;
        if (true) {
            tools_log(); cout << "*ptrsum = " << *ptrsum << endl;
            tools_log(); cout << "*ptrptrsum = " << *ptrptrsum << ", **ptrptrsum = " << **ptrptrsum << endl;
        }
    }
    
    return EXIT_SUCCESS;
}

