/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema Verwendung eigener Operatoren
 * 
 *  Stichworte:
 *      - operator
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
using namespace std;

#include "../tools/tools.h"

// noch eine String-Klasse ...
class CStringIII
{
public:
    char * p;
    
    CStringIII(const char * Src) : p(new char [strlen(Src)+1]) { strcpy(p,Src); }

    CStringIII(const string & s) : CStringIII(s.c_str()) { }	/* : CStringIII(...) ?
     * 
     * 	eigenen ctor zu verwenden reduziert Code-Duplikate und ist ein 
     * 	C++11 Feature.
     */

    CStringIII(const CStringIII & s) : CStringIII(s.p) { }		/* : CStringIII(...) */

    ~CStringIII() { delete [] p; }

    CStringIII & operator=(CStringIII s) {  // note the copy!
        swap(p,s.p);                     
        return *this;
    }
    
    CStringIII & operator+=(const CStringIII & rhs) {
		char * q = new char [strlen(p)+strlen(rhs.p)+1];
		strcat(strcpy(q,p),rhs.p);
		swap(p,q);
		delete [] q;
		return *this;
	}
	
	// selbe Idee wie bei op=
	friend const CStringIII operator+(CStringIII lhs, const CStringIII & rhs) {	
		return lhs+=rhs;
	}
    
    friend ostream & operator<<(ostream & os, const CStringIII & s ) {
        os << s.p; return os;
    }
};


int main()
{
    tools_log(); cout << "play with operators ..." << endl;

	string two="two";
	CStringIII s1("one"),s2(two),s3(s1);
	
	s3 += s1;
	tools_log(); cout << "op+= " << s3 << endl;

	s3 += s1 += s2;
	tools_log(); cout << "op+= " << s3 << endl;
	
	s3 = s1+s2;
	tools_log(); cout << "op+  " << s3 << endl;

	s3 = s1+s2+s3;
	tools_log(); cout << "op+  " << s3 << endl;
    
    return EXIT_SUCCESS;
}
