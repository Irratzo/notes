/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Werfen und Fangen einfacher Ausnahmen
 * 
 *  Stichworte:
 *      - throw, try, catch
 */

#pragma GCC diagnostic ignored "-Wconversion-null"

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

#include "../tools/tools.h"

void f()
{
    try
    {
        throw 1;
    } 
    catch (...)
    {
        tools_log(); cout << "catch block in f" << endl;
        throw;
    }
}

int main()
{
    // do some work, throw something in case of error
    tools_log(); cout << "throw 12.34" << endl;    
    try
    {
        throw 12.34;
        tools_log(); cout << "after throw" << endl;
    } 
    catch (...)
    {
        tools_log(); cout << "catch block" << endl;
    }

    // catch different types
    tools_log(); cout << "throw int" << endl;
    try
    {
        throw 23;
    } 
    catch (double d)
    {
        tools_log(); cout << "catch block double, d=" << d << endl;
    }
    catch (int n)
    {
        tools_log(); cout << "catch block int, n=" << n << endl;
    }
    catch (...)
    {
        tools_log(); cout << "catch block rest" << endl;
    }

    // catch, rethrow, catch
    tools_log(); cout << "rethrow" << endl;
    try
    {
        f();
    } 
    catch (int n)
    {
        tools_log(); cout << "catch block int, n=" << n << endl;
    }
    catch (...)
    {
        tools_log(); cout << "catch block rest" << endl;
    }
    
    return EXIT_SUCCESS;
}

