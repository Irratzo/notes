/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema range based for, C++11 !
 * 
 *  Stichworte:
 *      - for (auto x : v)
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <initializer_list>
using namespace std;

#include "../tools/tools.h"

// how to provide an iterator (here read-only only)
class D {
    
    // nested class definition inside
    class myiterator
    {
    private:
        const D & d;    // we need to know which iterator we traverse
        size_t index;      // and the position

    public:
        myiterator(const D & _d, size_t _index) : d(_d), index(_index) { }
        
        // for simplicity, compare identity and indices only
        bool operator!=(const myiterator& rhs) const
        {
            return (&d==&rhs.d) && (index!=rhs.index);
        }

        double operator*() const { return d.v[index]; }
     
        const myiterator& operator++()
        {
            ++index;
            return *this;   // standard return value
        }
    };

private:    
    vector<double> v;

public:
    // use initializer_list from vector
    D(const initializer_list<double>& l) : v(l) { }
    
    myiterator begin () const { return myiterator(*this, 0); }
    myiterator end () const   { return myiterator(*this, v.size()); }
};


int main()
{
    tools_log(); cout << "define objects" << endl;

    vector<int> v = { 1,2,3 };
    
    tools_log(); cout << "variant I:   v = [ ";
    for (vector<int>::iterator it = v.begin(); it!=v.end(); ++it)
        cout << *it << " ";
    cout << "]" << endl;

    // note: auto
    tools_log(); cout << "variant II:  v = [ ";
    for (auto it = v.begin(); it!=v.end(); ++it)
        cout << *it << " ";
    cout << "]" << endl;

    // read-only variant
    tools_log(); cout << "variant III: v = [ ";
    for (auto x : v)
        cout << x << " ";
    cout << "]" << endl;

    // write variant with ref &
    bool first = true;
    tools_log(); cout << "variant IV:  v = [ ";
    for (auto & x : v) {
        if (first) { x = 0; first = false; }
        cout << x << " ";
    }
    cout << "]" << endl << endl;

    // remember: auto can be used in cases where the compiler is able to derive the type
    auto n = 12;    // int
    auto f = 2.3f;  // float etc.
    tools_log(); cout << "n=" << n << ", f=" << f << endl << endl;

    D d = { 5.5,6.6,7.7 };
    
    // use D::myiterator
    tools_log(); cout << "variant I:   d = [ ";
    for (auto it = d.begin(); it!=d.end(); ++it)
        cout << *it << " ";
    cout << "]" << endl;

    tools_log(); cout << "variant II:  d = [ ";
    for (auto x : d)
        cout << x << " ";
    cout << "]" << endl;

    return EXIT_SUCCESS;
}

