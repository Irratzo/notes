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
    
    // Fuer Type deduction, Fall p3
    mypair(const T1& key, const T2& value) : key(key), value(value) {}
    
    friend ostream& operator<<(ostream& os, const mypair& p) {
        os << "[" << p.key << ":" << p.value << "]";
        return os;
    }
};

int main() {
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    mypair<int,double> p1{2,3.1};
	cout << "1)    p1: " << p1 << endl;

    mypair<string,char> p2{string("abc"),'X'};
	cout << "2)    p2: " << p2 << endl;
     
    // geht nur mit neuerem g++, z.B. 7.1 und -std=c++17
    // mypair p3{string("abc"),'X'};
	// cout << "3)    p3: " << p3 << endl;

    return 0;
}

