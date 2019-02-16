/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema Threads und Mutex
 */
 
// Achtung: Beim Compilieren ist das Flag -pthread notwendig, siehe makefile.

#include <iostream>
#include <thread>
#include <condition_variable>
#include <chrono>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#include "../tools/tools.h"

void Work(mutex & signal, int & cnt) 	/*	Auf ein Signal warten
 * 
 * 	Die Idee hier ist es, auf ein Signal zu warten und in der 
 * 	Zwischenzeit solange an einer Aufgabe zu arbeiten.
 */
{
    tools_log(); cout << "thread started, wait for signal" << endl;
    
    cnt = 0;
    // Solange das mutex belegt ist, arbeite Aufgabe ab (inc cnt).
    // wenn man nur warten /und nichts tun) moechte, condition variables benutzen!
    while (!signal.try_lock())
    {
        ++cnt;
    }
    /* ===========================================
     * JW: hier ist sozusagen ne Barrier an der das Thread dauernd anrennt
     * (millionenmal pro sec) bis das Lock vom MainThread freigegeben wurde.
     */
    tools_log(); cout << "thread works" << endl;     
    // Hier ist das mutex jetzt reserviert. Es muss wieder freigegeben werden,
    // damit andere threads das Signal ebenfalls verarbeiten koennen.
    signal.unlock();

	// Arbeite an weiterer Aufgabe
    this_thread::sleep_for(chrono::seconds(2));

    tools_log(); cout << "thread done" << endl;     
}

int main()
{
    mutex signal;

    tools_log(); cout << "start threads t1 and t2 and count" << endl;

	// Reserviere das Signal, so dass die Threads auf das Signal warten 
	// koennen.
    signal.lock();

    int cnt1,cnt2;
    
    thread t1(Work,ref(signal),ref(cnt1)); tools_registerthreadname(t1); 
    thread t2(Work,ref(signal),ref(cnt2)); tools_registerthreadname(t2); 

    tools_log(); cout << "do work in main thread" << endl;
    
    // Bevor die Threads weiterlaufen, ist hier noch etwas zu tun.
    this_thread::sleep_for(chrono::seconds(1));

    tools_log(); cout << "work done, signal threads and wait" << endl;
    
    // Jetzt das Signal freigeben und die Threads laufen weiter
    signal.unlock();

    t1.join();
    t2.join();

	// cnt1 und cnt2 enthalten, wie oft die Threads in 1s in dem 
	// try_lock-loop waren.
    tools_log(); cout << "joined, cnt1=" << cnt1 << ", cnt2=" << cnt2 << endl;
    
    return EXIT_SUCCESS;
}
