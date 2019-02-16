/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema Vererbung, abstrakte Klassen und Interfaces in C++
 * 
 *  Stichworte:
 *      - interface, abstract classes
 */

#include <iostream>
#include <cstdlib>
using namespace std;

#include "../tools/tools.h"

// there is no special "interface", interface behaviour is provided
// by so-called abstract classes being classes with pure virtual functions
// only
// (as C++ has multiple-inheritance, there is no need to have interfaces)

// this is an abstract class with one pure virtual function
class IReport 
{
    virtual void CreateReport() = 0;    // "=0" means pure virtual
};

// inheriting from an abstract class; it is not necessary to implement
// all pure virtual functions but if we don't we would have another 
// abstract class
class Customer : public IReport
{
public:
    void CreateReport() { tools_log(); cout << "report created." << endl; }     // implementation
};

int main()
{
    // an abstract class cannot be instantiated
    //IReport r;
    Customer c;
    c.CreateReport();

    return EXIT_SUCCESS;
}

