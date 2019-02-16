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
void Work(condition_variable & cv, mutex & m) 
{
    tools_log(); cout << "thread started" << endl;

    std::unique_lock<std::mutex> lk(m);
    tools_log(); cout << "got mutex, now wait for signal" << endl;

	cv.wait(lk);						/* Was ist mit dem Mutex?
 * 
 * 	Das Mutex muss hier natuerlich freigegeben werden, damit an
 * 	anderer Stelle auch die condition variable signalisiert werden kann.
 * 	wait gibt es intern frei.
 *  ===================================================
 *  JW: das ist dieslbe Barrier wie beim I07 try_lock-loop,
 *  bloss dass dort 'wartearbeit' getan wurde, hier wa. nicht/weniger.
 */
 
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
    
    thread t(Work,ref(cv),ref(m));tools_registerthreadname(t);

/*	Race condition?
 * 	
 * 	Die folgende Zeile auskommentieren und das Programm haengt.
 */
//    this_thread::sleep_for(std::chrono::milliseconds(10));
//    JW: das stimmte: commented out: stuck, commented in: ran,
//    but then commented out again: runs still now. ??
        
    {
    std::unique_lock<std::mutex> lk(m);
    tools_log(); cout << "do main work" << endl;
    this_thread::sleep_for(std::chrono::seconds(1));

    tools_log(); cout << "done, signal thread" << endl;
    cv.notify_one();
    }

    tools_log(); cout << "and wait for join" << endl;
    t.join();

    tools_log(); cout << "joined, done" << endl;
    
    return EXIT_SUCCESS;
}
