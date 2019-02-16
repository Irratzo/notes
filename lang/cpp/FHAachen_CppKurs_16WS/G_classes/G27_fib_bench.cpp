/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema Zeitmessung
 * 
 *  Stichworte:
 *      - static
 */

#include <iostream>
#include <cstdlib>
#include <thread>
#include <unordered_map>
using namespace std;

#include "../tools/tools.h"

long fib_seriell_alex(long n)
{
    return (n<2) ? n : fib_seriell_alex(n-1)+fib_seriell_alex(n-2); 
}

long fib_static_alex(long n) 
{
    static unordered_map<long,long> map;
    //cout << "call " << n << ", f " << map[n] << endl;

    if (-1==n) { map.clear(); return 0; }
    
    long fn = map[n];
    if (0!=fn) return fn;
    return (map[n]=((n<2) ? n : fib_static_alex(n-1)+fib_static_alex(n-2))); 
}

typedef long (*fib_ptr)(long);

fib_ptr table[] = {
    fib_seriell_alex,
    //fib_seriell_alex,
    fib_static_alex
};

int main()
{    
	tools_log(); cout << "#" << endl;
    
    while (true) {
        long n,fn;
        cout << endl << endl << "n: "; cin >> n;

        for (size_t i=0; i<sizeof(table)/sizeof(fib_ptr); ++i)
        {
            auto t1 = std::chrono::high_resolution_clock::now();
            long s=0;
            for (int k=0; k<100; ++k) {
                table[i](-1);
                fn=table[i](n);
                s+=fn;
            }
            auto t2 = std::chrono::high_resolution_clock::now();
            std::cout << "cand. " << i << ", fn=" << fn << ", time between: "
                  << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
                  << " ms" << endl;
        }
    }
              
    return EXIT_SUCCESS;
}

