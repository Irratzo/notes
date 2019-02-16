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

int main()
{
    tools_log(); cout << "start threads t1 and t2" << endl;

    /*	Thread starten
     * 
     * 	Hier wird der Thread gestartet, d.h. hier die Lambda-Funktion
     * 	ausgefuehrt.
     */
    thread t1([](){this_thread::sleep_for(chrono::seconds(2));});      
    thread t2([](){this_thread::sleep_for(chrono::seconds(5));});      

    tools_log(); cout << "and wait for join" << endl;

    t1.join();
    tools_log(); cout << "t1 joined, done" << endl;
    
    t2.join();
    tools_log(); cout << "t2 joined, done" << endl;
         
    return EXIT_SUCCESS;
}
