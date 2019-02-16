/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema external functions
 */

#include <iostream>
#include <cstdlib>
using namespace std;

#include "../tools/tools.h"

#include "J1_link_example_extern_V1.hpp"

int main()
{
    do_something();
    write_something("hello");
    
    C c;
    
    tools_log(); cout << "2*12=" << c.mal2(12) << ", C::m=" 
                      << C::m << endl;

    D<int> d;
    
    return EXIT_SUCCESS;
}

