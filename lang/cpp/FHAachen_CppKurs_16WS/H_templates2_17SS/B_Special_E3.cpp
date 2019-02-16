// author: a.voss@fh-aachen.de

#include <iostream>
#include <set>
#include <vector>
using namespace std;

template <typename T>
class TypeInfo
{
public:
	// analog numeric_limits<...>::min()
    static size_t CalcSize() { return sizeof(T); }
};

// Dies ist eine Spezialisierung. Das bedeutet, manche Template-Parameter
// sind explizit angegeben. Die verbleibenden sind weiterhin Parameter, 
// hier bleiben allerdings keine uebrig, daher ist die Menge der
// Template-Parameter leer: <>
template <>								
class TypeInfo<bool>
{
public:
    // auch der return-Typ kann anders sein
    static double CalcSize() { return 1.0/8.0; }
};

int main() {
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

	cout << "1)    size of int: " << TypeInfo<int>::CalcSize() << endl;

	cout << "2)    size of double: " << TypeInfo<double>::CalcSize() << endl;

	cout << "3)    size of bool: " << TypeInfo<bool>::CalcSize() << endl << endl;
     
    return 0;
}

