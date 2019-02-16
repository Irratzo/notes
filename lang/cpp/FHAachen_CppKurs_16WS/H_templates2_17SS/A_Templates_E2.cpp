// author: a.voss@fh-aachen.de

#include <iostream>
#include <set>
#include <vector>
using namespace std;

// Eine template Klasse point mit Datentyp T. In aelterem Code auch oft als
// template <class T> 
template <typename T>
class point
{
public:
    typedef T value_type;

    T x,y;
    
    friend ostream& operator<<(ostream& os, const point& p) {
        os << "(" << p.x << "," << p.y << ")";
        return os;
    }
};

int main() {
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    point<int> pi{2,3};
	cout << "1)    pi: " << pi << endl;

    point<long> pl{12,13};
	cout << "2)    pl: " << pl << endl;
    
    point<char> pc{'a','b'};
	cout << "3)    pc: " << pc << endl;

    // Wozu typedef?
    // Manchmal ist es sinnvoll, sich den Datentyp zu "merken", mit dem
    // das Template definiert wurde (es gibt mehrere Moeglichkeiten).
    // Vgl. auch z.B. vector, set etc.
    typedef point<unsigned int> Point;
    Point::value_type a=5, b=6;
    Point pu{a,b};
	cout << "4)    pu: " << pu << endl << endl;
    
    // Verschiedene Klassen!
    // pi = pl;
    
    return 0;
}

