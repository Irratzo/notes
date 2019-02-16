/*
 * Starten Sie Threads, von denen der erste 1 Sek., der zweite 2 Sek. und
 * der dritte 3 Sek. schlafen. Der Hauptthread wartet auf alle drei.
 */

/* 
 * File:   main.cpp
 * Author: johannesw
 *
 * Created on 13. Juli 2017, 09:10
 */

#include <cstdlib>
#include <iostream>
#include <thread>
#include <condition_variable>
#include <chrono>
#include <vector>
#include "../../../tools/tools.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    vector<thread> vec;

    for (int i = 1; i < 4; i++) {
        tools_log(); cout << "start thread " << i << " sleeping for " << i << " sec";
        vec.push_back(thread([ = ](){this_thread::sleep_for(chrono::seconds(i));})); cout << endl; tools_registerthreadname(vec[i]);
    }
    
    tools_log(); cout << "wait for join" << endl;
    int i = 1;
    for (auto &t : vec){
        t.join();
        tools_log(); cout << "thread " << i << " joined" << endl;
        i++;
    }
    tools_log(); cout << "done" << endl;



    return 0;
}

