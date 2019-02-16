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
using namespace std;

#include "../tools/tools.h"

void f()
{
    // std::this_thread::sleep_for(std::chrono::seconds(2));
    std::this_thread::sleep_for(std::chrono::milliseconds(2134));
}

int main()
{    
	tools_log(); cout << "#" << endl;

    auto t1 = std::chrono::high_resolution_clock::now();
    f();
    auto t2 = std::chrono::high_resolution_clock::now();
    tools_log(); std::cout << "time between: "
              << std::chrono::duration_cast<std::chrono::milliseconds>(t2-t1).count()
              << " ms" << endl;
              
    return EXIT_SUCCESS;
}

