/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema Verwendung eigener Operatoren
 *  http://stackoverflow.com/questions/4421706/operator-overloading
 *  http://en.wikipedia.org/wiki/Operators_in_C_and_C%2B%2B
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

#pragma GCC diagnostic ignored "-Wunused-parameter"

class X {
    int n;
	
public:
	X(int n) : n(n) { }

    // (1)
    X& operator=(const X& rhs)
    {
      // copy from rhs, or use swap idiom with X& X::operator=(X rhs)
      return *this;
    }

	// (2)
    friend ostream & operator<<(ostream & os, const X & x ) {
        os << "x.n=" << x.n; return os;
    }

    friend istream& operator>>(istream& is, X& obj)
    {
        is >> obj.n;
        // read obj from stream, use is.setstate(std::ios::failbit) in case of error
        return is;
    }
    
    // (3)
    int operator()(int y)
    {
        return n*y;
    }
	
    // (4) note: only two contain functionality
    friend bool operator==(const X& lhs, const X& rhs)
    { 
        return lhs.n == rhs.n;
    }
    friend bool operator!=(const X& lhs, const X& rhs)
    {
        return !operator==(lhs,rhs);
    }

    friend bool operator<(const X& lhs, const X& rhs)
    {  
        return lhs.n < rhs.n;
    }
    friend bool operator>(const X& lhs, const X& rhs)
    {
        return  operator< (rhs,lhs);    // note: args switch role
    }
    friend bool operator<=(const X& lhs, const X& rhs)
    {
        return !operator> (lhs,rhs);
    }
    friend bool operator>=(const X& lhs, const X& rhs)
    {
        return !operator< (lhs,rhs);
    }
    
    // in principle: || and && are defined the same way but the built-in
    // versions use shortcut semantics, the user defined ones do not
    // => "it is highly advised NEVER to define them"

    // (5) note: again, postfix uses prefix
    X& operator++()     // prefix ++x
    {
        ++n;
        return *this;
    }
    
    X operator++(int)   // postfix x++ (dummy argument)
    {
        X tmp(*this);
        operator++();
        return tmp;
    }
    
    // (6) note: again, op= uses op+=
    X& operator+=(const X& rhs)
    {
        n += rhs.n;
        return *this;
    }

    friend X operator+(X lhs, const X& rhs)
    {
        lhs += rhs;
        return lhs;
    }
    
    // (7) value_type& in case of non-built-in types, otherwise without &
    //  non-const objects
    //      value_type& operator[](index_type idx);
    //  const objects
    //      const value_type& operator[](index_type idx) const;

    /*
     *  possible:
     *  arithmetic operators: + - * / % and += -= *= /= %= (all binary infix); 
     *      + - (unary prefix); ++ -- (unary prefix and postfix)
     *  bit manipulation: & | ^ << >> and &= |= ^= <<= >>= (all binary infix); 
     *      ~ (unary prefix)
     *  boolean algebra: == != < > <= >= || && (all binary infix); 
     *      ! (unary prefix)
     *  memory management: new new[] delete delete[]
     *  implicit conversion operators
     *  miscellany: = [] -> , (all binary infix); * & (all unary prefix) () (function call, n-ary infix)
     * 
     *  not possible:
     *  .  ::  sizeof ?:
     * 
     *  not considered:
     *        value_type& operator*();
     *  const value_type& operator*() const;
     *        value_type* operator->();
     *  const value_type* operator->() const;
     * 
     *  there are more ...
     */


};


int main()
{
    tools_log(); cout << "self defined operators ..." << endl;

    X x(0),x1(1),x2(2);
    
    // (1) assign
    x1 = x2;
    
    // (2) left- and right-shift
    tools_log(); cout << "Input x.n="; cin >> x;
    tools_log(); cout << "->" << x << endl;
    
    // (3) function call op.
    tools_log(); cout << "call x(10)=" << x(10) << endl;
    
    // (4) comparison
    tools_log(); cout << "x1<x2? " << (x1==x2) << endl;
    
    // arithmetic operators
    
    // (5) pre- and postfix
    ++x1; x2++;

    // (6) arithm. operations
    x += x1;
    x = x1+x2;
    
    // (7)
    // x[] 

    return EXIT_SUCCESS;
}
