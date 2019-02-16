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

using namespace std;

void Work (int sec)
{
    tools_log();cout<< "working for "<<sec<<" sec(s)"<<endl;
    this_thread::sleep_for(chrono::seconds(sec));
    tools_log();cout<< "work done"<<endl;
}

int main()
{
    tools_log(); cout << "start threads t1 and t2" << endl;
    
    thread  t1(Work,1); tools_registerthreadname(t1);
    thread  t2(Work,2); tools_registerthreadname(t2);

    t2.join();
    tools_log(); cout <<"first join"<<endl;
    t1.join();
    tools_log(); cout <<"second join"<<endl;

    tools_log(); cout <<"all done"<<endl;
}

