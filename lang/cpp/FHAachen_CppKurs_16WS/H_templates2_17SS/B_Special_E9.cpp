// author: a.voss@fh-aachen.de

#include <iostream>
#include <set>
#include <vector>
using namespace std;

template <typename T>
struct myis_pointer {
    static const bool value = false;
};

template <typename T>
struct myis_pointer<T*> {
    static const bool value = true;
};

template <typename T, bool isptr> 
struct mycollection {
};

template <typename T> 
struct mycollection<T,true> {
    static const int type = 1;
};

template <typename T> 
struct mycollection<T,false> {
    static const int type = 2;
};

template<class T> 
using Collection = mycollection<T,myis_pointer<T>::value>;

int main() {
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    
 
	cout << "1)    int = ptr? " << myis_pointer<int>::value << endl;
	cout << "2)    int* = ptr? " << myis_pointer<int*>::value << endl;

    Collection<double> c1;
    Collection<double*> c2;
	cout << "3)    c1 " << c1.type << endl;
	cout << "4)    c2 " << c2.type << endl;
    
    return 0;
}

