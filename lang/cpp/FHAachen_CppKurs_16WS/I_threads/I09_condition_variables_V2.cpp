/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema Threads, Mutex, Condition Variables
 */

#include <iostream>
#include <thread>
#include <condition_variable>
#include <chrono>
#include <string>
using namespace std;

#include "../tools/tools.h"

// Auf ein Signal warten
void Work(condition_variable & cv, mutex & m, bool & workdone) 
{
    tools_log(); cout << "thread started, workdone:" << workdone << endl;

    std::unique_lock<std::mutex> lk(m);
    tools_log(); cout << "got mutex, now wait for signal" << endl;


	while(!workdone)					/*	Wieso?
 * 
 * 	Entweder, workdone ist false, dann ist die Arbeit im main-Thread 
 * 	noch nicht erledigt und noch nichts signalisiert -> auf Signal warten.
 * 	Oder aber, workdone ist true und das Signal wurde schon gefeuert
 * 	-> dann braucht man nicht mehr zu warten.
 */ 
		cv.wait(lk);

	// Aequivalente Moeglichkeit vie lambda
	// cv.wait(lk,[&]{return workdone;});

    tools_log(); cout << "got signal, do work for 2 sec" << endl;
    
    // Arbeit erledigen
    this_thread::sleep_for(std::chrono::seconds(2));
    
    tools_log(); cout << "work and thread done" << endl;     
}

int main()
{
    tools_log(); cout << "start thread t" << endl;

    condition_variable cv;
    mutex m;
    bool workdone = false;

    
    thread t(Work,ref(cv),ref(m),ref(workdone));tools_registerthreadname(t);

	// Hier exisitert keine race condition!
	
    {
    std::unique_lock<std::mutex> lk(m);
    tools_log(); cout << "do main work" << endl;
    this_thread::sleep_for(std::chrono::seconds(1));
    
    tools_log(); cout << "done, signal thread" << endl;
    workdone = true;	// zuerst flag setzen
    cv.notify_one();	// dann das Signal setzen
    }

    tools_log(); cout << "and wait for join" << endl;
    t.join();

    tools_log(); cout << "joined, done" << endl;
    
    return EXIT_SUCCESS;
}
