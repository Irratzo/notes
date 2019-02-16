// author: a.voss@fh-aachen.de

#include <iostream>
#include <set>
#include <vector>
using namespace std;

// Eine template Klasse pair mit Datentypen T1 und T2. 
template <typename T1, typename T2>
class mypair
{
public:
    typedef T1 key_type;
    typedef T2 value_type;

    key_type key;
    value_type value;
    
    friend ostream& operator<<(ostream& os, const mypair& p) {
        os << "[" << p.key << ":" << p.value << "]";
        return os;
    }
};

// Eine Spezialisierung, d.h. fuer den Fall, dass der erste Parameter ein
// int ist, nimmt der Compiler diese Klasse
template <typename T2>
class mypair<int,T2>
{
public:
    typedef int key_type;
    typedef T2 value_type;

    key_type key;
    value_type value;
    
    friend ostream& operator<<(ostream& os, const mypair& p) {
        os << "[" << p.key << "*" << p.value << "]";
        return os;
    }
};

// Oder auch komplett spezialisiert.
template <>
class mypair<bool,bool>
{
public:
    typedef bool key_type;
    typedef bool value_type;

    int n;
    
    mypair(bool b1, bool b2) : n( ((b1)?1:0) + ((b2)?2:0) ) {}
    
    friend ostream& operator<<(ostream& os, const mypair& p) {
        bool b1 = p.n & 1;
        bool b2 = p.n>>1;
        os << "[" << b1 << "->" << b2 << "]";
        return os;
    }
};

int main() {
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    mypair<int,double> p1{2,3.1};
	cout << "1)    p1: " << p1 << endl;

    mypair<bool,bool> p2{true,false};
	cout << "2)    p2: " << p2 << endl;
     
    return 0;
}

