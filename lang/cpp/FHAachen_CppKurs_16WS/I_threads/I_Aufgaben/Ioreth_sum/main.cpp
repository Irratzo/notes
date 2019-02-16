/*
 * Summieren Sie die Zahlen 1..N parallel und thread-safe in einer globalen
 * Summenvariablen auf.
 * --------------------------------------------------------
 * Notes on Written Code:
 * 
 * - Reused code from Isildur (threads in vector, use lambda for thread Ctor)
 * - The inside of the lambda is reused from I05_mutex_locks_V1.cpp,
 *   function Work3.
 * 
 * 
 * --------------------------------------------------------
 * Notes on Results of Runs:
 * 
 * The lock_guard really does work!
 * Results for num_threads=5, N=654321:
 * without lock_guard: 631987
 * with    lock_guard: 654321 or 654322
 */

/* 
 * File:   main.cpp
 * Author: johannesw
 *
 * Created on 13. Juli 2017, 09:31
 */

#include <cstdlib>
#include <iostream>
#include <thread>
#include <condition_variable>
#include <chrono>
#include <vector>
#include <cassert>
#include "../../../tools/tools.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    vector<thread> vec;
    const int num_threads{5};

    const long long N{654321};
    long long sum{0};
    mutex mutex_sum;

    /*
     * need to distribute task among num_threads.
     * Problem: N / num_threads will have a rest.
     * Solution:
     * - sum (N/num_threads) for first N-1 threads.
     * - sum (N/num_threads)+(N % num_threads) for last thread
     */
    const long long N_firstThreads = N / num_threads;
    const long long N_lastThread = N_firstThreads + (N % num_threads);
    const long long N_check = ((num_threads - 1) * N_firstThreads + N_lastThread);
    //    assert(N == N_check); //Runtime check
    /*C++11: static_assert: Compiletime check */
    string assert_msg_fail = "N distributed = " + to_string(N_check) + " does not equal N = " + to_string(N);
    static_assert(N == N_check, "N distributed does not add up to N");

    for (int i = 1; i <= num_threads; i++) {
        cout << endl;
        tools_log();
        cout << ". start thread " << i << " summing, SUM = " << sum << "." << endl;
        vec.push_back(
                thread(
                [&]() {
                    tools_log(); cout << ". thread " << i << " started, SUM = " << sum << "." << endl;
                    const long long M = (i != num_threads) ? N_firstThreads : N_lastThread;
                    for (long long j = 0; j < M; ++j) {
                        lock_guard<mutex> lk(mutex_sum); //comment this out to enable data race
                                ++sum;
                    }
                    tools_log(); cout << ". thread " << i << " done summing, SUM = " << sum << "." << endl;
                }
        )
        );
        cout << endl;
        tools_registerthreadname(vec[i]);
    }

    tools_log();
    cout << ". wait for join." << endl;
    int i = 1;
    for (auto &t : vec) {
        t.join();
        tools_log();
        cout << ". thread " << i << " joined, SUM = " << sum << "." << endl;
        i++;
    }
    tools_log();
    cout << ". done, result: sum is now: " << sum << endl;






    return 0;
}

