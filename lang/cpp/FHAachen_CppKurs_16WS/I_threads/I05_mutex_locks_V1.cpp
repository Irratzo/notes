/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema Threads, Mutex, Locks
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

/* Thread Function, Version 1 -> ...
 * 
 * 	Diese Funktion wird von zwei Threads gleichzeitig verwendet,
 * 	d.h. gleichzeitig wird *sum erhoeht. 
 * 	Der Ausdruck x = x+d ist nicht sicher, da zwischen dem Auslesen von x
 * 	auf der rechten Seite und dem Update von x, also der Zuweisung auf
 * 	der linken Seite, ein anderer Thread x veraendern kann. Diese Aenderung
 * 	geht beim Update von x dann verloren.
 * 	Deswegen ist die Summe hier am Ende nicht wieder 0, wenn die Anzahl
 * 	Wiederholungen nur hoch genug ist (n).
 */ 
void Work1(long long inc, long long n, long long * sum) 
{
    tools_log(); cout << "thread started, start loop version 1" << endl;
    
    for (long long i=0; i<n; ++i) 
    {
        (*sum) += inc; 
        
        // s = s + inc
    }  

    tools_log(); cout << "loop and thread done" << endl;     
}

/* Thread Function, Version 2 -> safe 
 * 
 * 	Durch den Lock kann ein zwischenzeitliches Update nicht geschehen.
 * 	Dennoch ist die Loesung nicht optimal. Falls z.B. exceptions
 * 	zwischen lock und unlock auftreten, so wird die Funktion verlassen,
 * 	aber das Lock nicht aufgehoben.
 */
void Work2(long long inc, long long n, long long * sum, mutex * mutex_sum) 
{
    tools_log(); cout << "thread started, start loop version 2" << endl;

    for (long long i=0; i<n; ++i) 
    {
        // ...
        mutex_sum->lock();				/*	mutex?
 * 
 * 	Das mutex.lock verhindert, dass zwei Threads gleichzeitig diesen Codebereich
 * 	betreten. Dadurch wird das Update von *sum nicht von einem anderen Thread
 * 	unterbrochen und die Summe stimmt hinterher.
 */
        (*sum) += inc;      			/*	Warum ist die Loesung nicht gut?
 * 
 * 	Erklaerung siehe oben. Bsp. einfache Befehle wie
 * 		v.push_back(n) 
 * 	koennten exceptions werfen.
 */
        mutex_sum->unlock();
        // ...
    }  

    tools_log(); cout << "loop and thread done" << endl;     
}

/* Thread Function, Version 3 -> safe 
 * 
 * 	Bettet man das lock und unlock in ein Objekt ein, welches am Ende
 * 	seiner Lebenszeit das mutex wieder freigibt, dann wird im Falle
 * 	einer exception das Objekt aufgeraeumt und so das mutex immer 
 * 	freigegeben. Das Prinzip nennt sich RAII (Resource Acquisition Is 
 * 	Initialization) - etwas sperrig...
 * 	Und die Objekte heissen locks, genauer hier lock_guard.
 */
void Work3(long long inc, long long n, long long * sum, mutex * mutex_sum) 
{
    tools_log(); cout << "thread started, start loop version 3" << endl;

    for (long long i=0; i<n; ++i) 
    {
        lock_guard<mutex> lk(*mutex_sum);  	// exception safe (RAII)
        (*sum) += inc; 
    }  

    tools_log(); cout << "loop and thread done" << endl;     
}

// Addiere parallel n mal +1 und n mal -1 auf, so dass die Summe wieder 0 ist.
int main()
{
    const long long n = 1000000;
    long long sum;

    tools_log(); cout << "start threads t1 and t2 and sum" << endl;

    sum = 0;
    thread t1(Work1,+1,n,&sum); tools_registerthreadname(t1); 
    thread t2(Work1,-1,n,&sum); tools_registerthreadname(t2); 
    t1.join();
    t2.join();
    tools_log(); cout << "threads joined, sum=" << sum << endl << endl;

    //return 0;

    tools_log(); cout << "start threads t3 and t4 and sum" << endl;

    mutex mutex_sum;
    
    sum = 0;
    thread t3(Work2,+1,n,&sum,&mutex_sum); tools_registerthreadname(t3); 
    thread t4(Work2,-1,n,&sum,&mutex_sum); tools_registerthreadname(t4); 
    t3.join();
    t4.join();
    tools_log(); cout << "threads joined, sum=" << sum << endl << endl;

    tools_log(); cout << "start threads t5 and t6 and sum" << endl;

    sum = 0;
    thread t5(Work3,+1,n,&sum,&mutex_sum); tools_registerthreadname(t5); 
    thread t6(Work3,-1,n,&sum,&mutex_sum); tools_registerthreadname(t6); 
    t5.join();
    t6.join();

    tools_log(); cout << "threads joined, sum=" << sum << endl;
    
    return EXIT_SUCCESS;
}
