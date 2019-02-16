/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Thema Klausuraufgabe
 * 
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <stdexcept>
#include <algorithm>
using namespace std;

// Bitte ausfüllen!
const string name = "N.N.";
const string matrnr = "123456";

class set {
    unsigned int max_elements;
    vector<unsigned int> data;
    
public:
    set(unsigned int max_elements)
    : max_elements(max_elements)
    {
        data.reserve(max_elements);
    }

    set(unsigned int max_elements, const initializer_list<unsigned int>& l)
    : max_elements(max_elements), data(l)
    {
        data.reserve(max_elements);
    }
    
    bool contains(unsigned int n) 
    {
        for (auto x : data)
            if (x==n)
                return true;
        return false;
    }
    
    void set_value(unsigned int n)
    {
        if (contains(n))
            return;
        if (data.size()>=max_elements)
            throw invalid_argument("too many elements");
        data.push_back(n);
    }
    
    void remove_value(unsigned int n)
    {
        // http://en.wikipedia.org/wiki/Erase-remove_idiom
        data.erase(remove(data.begin(), data.end(), n), data.end());
    }
    
    friend set operator+(const set& s1, const set& s2)
    {
        set rc(s1.max_elements+s2.max_elements);
        for (auto x:s1.data)
            rc.set_value(x);
        for (auto x:s2.data)
            rc.set_value(x);
        return rc;
    }
    
    friend ostream& operator<<(ostream& os, const set& s)
    {
        os << "{ ";
        for (auto x : s.data)
            os << x << " ";
        os << "} (" << s.max_elements << ")";
        return os;
    }
};

int main()
{    
	cout << "Name:     " << name << endl;
    cout << "Matr.Nr.: " << matrnr << endl;
    
    set s1(5);
    cout << "s1: " << s1 << endl;
    
    set s2(7,{1,2});
    cout << "s2: " << s2 << endl << endl;
    
    cout << "1 in s1? " << s1.contains(1) << endl;
    cout << "2 in s2? " << s2.contains(2) << endl;
    cout << "3 in s2? " << s2.contains(3) << endl << endl;
              
    for (unsigned int i=1; i<=7; ++i)       // 1,2 gibt es schon!
    {
        s2.set_value(i);
    }
    cout << "s2: " << s2 << endl << endl;
    
    try {
        s2.set_value(8);
    } catch (invalid_argument e) {
        cout << "Fehler: " << e.what() << endl << endl;
    }
    
    s2.remove_value(3);
    cout << "s2: " << s2 << endl;
    s2.remove_value(10);
    cout << "s2: " << s2 << endl << endl;
    
    s1.set_value(3);
    set s3 = s1+s2;
    cout << "s3: " << s3 << endl << endl;
              
    return EXIT_SUCCESS;
}

