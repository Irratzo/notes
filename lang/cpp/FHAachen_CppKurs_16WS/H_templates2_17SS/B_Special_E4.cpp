// author: a.voss@fh-aachen.de

#include <iostream>
#include <set>
#include <vector>
using namespace std;

// Es sind auch int-Template-Parameter zugelassen, hier ein
// Vektor fixer Laenge.
// Und auch Template-Member
template <typename T, int N>
class MyVector 
{
public:
    enum { dim = N };
    T data[dim];
    
    T operator[](int i) const { return data[i]; }
    T& operator[](int i) { return data[i]; }
    
    // wozu?
    template <typename S>
    MyVector & operator=(const MyVector<S,N> & v)
    {
        for (int i=0; i<N; ++i)
            data[i] = (T)(v.data[i]);
        return *this;
    }
};

// template partial specialization
// fuer den Fall dim=0
template <typename T>
class MyVector<T,0>
{
public:
    enum { dim = 0 };
    T data;
    
    T operator[](int) const { return data; }
    T& operator[](int) { return data; }
};

// ein typedef template
template<class T> 
using MyVector3d = MyVector<T,3>;


int main() {
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;

    MyVector<int,3> v3;
    MyVector<int,0> v0;

	cout << "1)    size of v3: " << sizeof(v3) << endl;

	cout << "2)    size of v0: " << sizeof(v0) << endl;

    MyVector<double,3> d3;
	cout << "3)    size of d3: " << sizeof(d3) << endl;
    
    d3 = v3;
    v3 = v3;
    v3 = d3;
    // v3 = v0;
    
    MyVector3d<char> c3;
	cout << "4)    size of c3: " << sizeof(c3) << endl << endl;
     
    return 0;
}

