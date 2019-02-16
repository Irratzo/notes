/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Verwendung c++ Klassen mit dynamischem Speicher
 * 
 *  Stichworte:
 *      - copy and swap idiom
 */

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "../tools/tools.h"

// a naive approach
class CStringI
{
public:
    char * p;
    
    CStringI(const char * Src) : p(new char [std::strlen(Src)+1]) {     
        std::strcpy(p,Src); 
    }
    CStringI(const CStringI & s) : p(new char [std::strlen(s.p)+1]) { // better approach?
        std::strcpy(p,s.p); 
    }
    ~CStringI() { delete [] p; }

    // s1 = s2; 
    CStringI & operator=(const CStringI & s) {
        if (this!=&s) {                         // why? &-Op=address? slows down in most cases but may be necessary
            delete [] p;                        // what if new fails? "this" is modified
            p = new char [std::strlen(s.p)+1];  // code duplication
            std::strcpy(p,s.p); 
        }
        return *this;
    }
    friend std::ostream & operator<<(std::ostream & os, CStringI const & s ) {
        os << s.p; return os;
    }

};

// a better approach with copy-and-swap idiom
class CStringII
{
public:
    char * p;
    
    CStringII(const char * Src) : p(new char [std::strlen(Src)+1]) { 
        std::strcpy(p,Src); 
    }
    CStringII(const CStringII & s) : CStringII(s.p) { } // use ctor above - c++11

    ~CStringII() { delete [] p; }

// s1 = s2
    CStringII & operator=(CStringII s) {    // note the copy!
        Swap(*this,s);                      // we have to discuss exception safety
        return *this;
    }
    friend void Swap(CStringII & s1, CStringII & s2) {
        std::swap(s1.p,s2.p);
    }
    friend std::ostream & operator<<(std::ostream & os, CStringII const & s ) {
        os << s.p; return os;
    }
};

int main()
{
    CStringI s1("hello1"), s2("course1"), s3(s2);
    
    tools_log(); cout << "1) s1=" << s1 << ", s2=" << s2 << ", s3=" << s3 << endl;
    
    s1 = s3;

    tools_log(); cout << "2) s1=" << s1 << ", s2=" << s2 << ", s3=" << s3 << endl << endl;

    CStringII t1("hello2"), t2("course2"), t3(t2);
    
    tools_log(); cout << "3) t1=" << t1 << ", t2=" << t2 << ", t3=" << t3 << endl;
    
    t1 = t3;

    tools_log(); cout << "4) t1=" << t1 << ", t2=" << t2 << ", t3=" << t3 << endl;
    
    
    return EXIT_SUCCESS;
}

