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

// thread-function
void Work(int n) 
{
    tools_log(); cout << "thread no " << n << " started, sleep for " << n/2.0 << " sec" << endl;

    // sleep for n/2 sec
    this_thread::sleep_for(chrono::milliseconds(n*500));
   
    tools_log(); cout << "thread done" << endl;     
}

int main()
{
    const int numthreads = 5;

    tools_log(); cout << "start " << numthreads << " threads " << endl;

    thread threads[numthreads];    		/*	Thread Objekte anlegen
     * 
     * 	Hier ist noch nichts gestartet!
     */
        
    for (int i=0; i<numthreads; ++i)	/*	Threads starten
 * 
 * 	Hier werden die Objekte erneut zugewiesen, und diesmal auch gestartet.
 */ 
        threads[i] = thread(Work,i);
       
    tools_log(); cout << "and wait for join" << endl;

    for (auto & t : threads)			/*	join fuer alle
 * 
 * 	Auf alle warten.
 */
        t.join();
    
    tools_log(); cout << "joined, done" << endl;
    
    return EXIT_SUCCESS;
}
