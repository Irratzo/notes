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

// In diesem Beispiel koennen units auch verschieden sein.
// Eine einfache Menge-mit-Einheiten-Klasse.
class Unit {
    double amount;
    string unit;
    
public:
    Unit(double a, const string & u) : amount(a), unit(u)
    { 
        tools_log(); cout << "ctor " << (*this) << endl;
    }
    
    Unit(const Unit & u) : amount(u.amount), unit(u.unit)
    { 
        tools_log(); cout << "ctor " << (*this) << endl;
    }

    Unit & operator=(const Unit & u)
    { 
        unit=u.unit; amount=u.amount; 
        tools_log(); cout << "op=  " << (*this) << endl;
        return *this;
    }
    
    // Ein Weg, als Member (erste Version)
    Unit operator+(const Unit & u_rhs) 
    {
        Unit result(*this);
        result.amount += u_rhs.amount;
        tools_log(); cout << "op+  " << result << endl;
        return result;
    }; 

    // Oder als friend-Funktione (ebenfalls erste Version)
    friend Unit operator-(const Unit & u_lhs, const Unit & u_rhs) 
    {
        Unit result(u_lhs);
        result.amount -= u_rhs.amount;
        tools_log(); cout << "op-  " << result << endl;
        return result;
    }; 
    
    friend ostream & operator<<(ostream & os, const Unit & u)
    {
        os << "(" << u.amount << " " << u.unit << ")";
        return os;
    }
        
};

int main()
{
    tools_log(); cout << "define objects" << endl;

    Unit weight1(1,"kg");
    Unit weight2(2,"kg");
    Unit weight3(weight2);
    
    cout << endl;
    tools_log(); cout << "call op=" << endl;
    weight3 = weight1;

    cout << endl;
    tools_log(); cout << "call op+" << endl;
    weight3 = weight1+weight2;      // weight1.op+(weight2)
//              weight1 + 12.0        // weight1.op+(12.0);
//              12.0 + weight1        // 12.op+(weight1)

    cout << endl;
    tools_log(); cout << "call op-" << endl;
    weight3 = weight1-weight2;      // op-(weight1,weight2)
//        weight1 - 12.0              // op-(weight,12)
//        12.0 - weight               // op-(12,weight)
    
    return EXIT_SUCCESS;
}

