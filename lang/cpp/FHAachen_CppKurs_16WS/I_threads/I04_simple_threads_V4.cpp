/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema Threads
 */
 
// Achtung: Beim Compilieren ist das Flag -pthread notwendig, siehe makefile.

#include <iostream>
#include <thread>
#include <condition_variable>
#include <chrono>
#include <string>
using namespace std;

#include "../tools/tools.h"

void Work(int & secs)  					/*	Thread Funktion mit Referenz
 * 
 * 	Dies ist die Funktion, die mit einer Referenz aufgerufen wird.
 */
{
    tools_log(); cout << "thread started, sleep for " << secs << " sec" << endl;

    // sleep for some secs
    this_thread::sleep_for(chrono::seconds(secs));
    secs = -1; //JW: no difference if set to e.g. +3
   
    tools_log(); cout << "thread done" << endl;     
}

int main()
{
    tools_log(); cout << "start thread t" << endl;

    int secs = 1;
    /* ref() ?
     * 
     * 	Es ist notwendig, Referenzen via ref() zu uebergeben, damit
     * 	der ctor von thread die thread-Funktion mit einer Referenz
     * 	aufrufen kann. Es gibt auch cref fuer const refs.
     */
    thread t(Work,ref(secs));      tools_registerthreadname(t); 

    tools_log(); cout << "and wait for join" << endl;

    t.join();
    tools_log(); cout << "t joined, secs=" << secs << ", done" << endl;
         
    return EXIT_SUCCESS;
}
