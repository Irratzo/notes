/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema external functions
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

#include "J1_link_example_extern_V1.hpp"

int n = 23;

void write_something(const string& s)
{
    tools_log(); cout << "'" << s << "', n=" << n << endl;
}

C::C() { tools_log(); cout << "ctor" << endl; }

int C::mal2(int n) { return n+n; }

int C::m = 42;

template <typename T>
D<T>::D() { }

template class D<int>;

