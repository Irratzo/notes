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

// Thread Function
void Work(long long offset, long long n, vector<long long> * v, mutex * mutex_v) 
{
    tools_log(); cout << "thread started" << endl;

    for (long long i=0+offset; i<n; i+=2) 
    {
        // version standard lock, exception safe (RAII)
        lock_guard<mutex> lk(*mutex_v);			
				v->push_back(i);
        
        // more general lock, e.g. does not lock in ctor but unlocks in dtor
        //   unique_lock<mutex> lk(*mutex_v, defer_lock);
        //   // do something different
        //   lk.lock();
        //   v->push_back(i);

        // or recursice lock
        //   lock_guard<recursive_mutex> lk(*mutex_v);
           // call function with more locks on mutex_v
    }  

    tools_log(); cout << "loop and thread done" << endl;     
}

// Fuelle vector und zaehle gerade und ungerade Zahlen.
int main()
{
    const long long n = 1000000;

    mutex mutex_v;
    vector<long long> v;

    tools_log(); cout << "start threads t1 and t2 and sum" << endl;

    thread t1(Work,0,n,&v,&mutex_v); tools_registerthreadname(t1); 
    thread t2(Work,1,n,&v,&mutex_v); tools_registerthreadname(t2); 
    t1.join();
    t2.join();

    // Zaehle via lambda expression
    /* JW: count_if, var k: this is general count_if syntax:
     * count_if(v.begin(), v.end(), [](int i){return i%3 == 0;});
     * means: count elements divisible by 3;
     * This is like Java's Lambda's (t -> {doStuffWith t;}).
     * In Java, count_if would be a Predicate<U> (type U in, boolean out).
     */
    long long cnt1 = count_if (v.begin(), v.end(), [](long long k){ return (0==k%2);});
    long long cnt2 = count_if (v.begin(), v.end(), [](long long k){ return (1==k%2);});

    tools_log(); cout << "threads joined, even:" << cnt1 << " odd:" << cnt2 << endl;
    
    return EXIT_SUCCESS;
}
