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
    // todo (a) ctor set(unsigned int max_elements) 

    // todo (b) ctor für z.B. set s2(7,{1,2});!
    
    // todo (c) bool contains(unsigned int n) 
    
    // todo (d) void set_value(unsigned int n)
    // todo (e) exception werfen, falls zu viele Zahlen

    // todo (f) void remove_value(unsigned int n)

    // todo (g) operator +

    // todo (h) Ausgabeoperator 
};

int main()
{    
	cout << "Name:     " << name << endl;
    cout << "Matr.Nr.: " << matrnr << endl;

    
    ////////////////////////////////////////////////////////////////
    // bitte jeweils Code einkommentieren, wenn Teilaufgabe gelöst
    ////////////////////////////////////////////////////////////////


    // todo (a), (h)
    // set s1(5);
    // cout << "s1: " << s1 << endl;
    
    // todo (b)
    // set s2(7,{1,2});
    // cout << "s2: " << s2 << endl << endl;
    
    // todo (c)
    // cout << "1 in s1? " << s1.contains(1) << endl;
    // cout << "2 in s2? " << s2.contains(2) << endl;
    // cout << "3 in s2? " << s2.contains(3) << endl << endl;
    
    // todo (d)          
    // for (unsigned int i=1; i<=7; ++i)       // 1,2 gibt es schon!
    // {
    //     s2.set_value(i);
    // }
    // cout << "s2: " << s2 << endl << endl;
    
    // todo (e)
    // try {
    //     s2.set_value(8);
    // } catch (invalid_argument e) {
    //     cout << "Fehler: " << e.what() << endl << endl;
    // }
    
    // todo (f)
    // s2.remove_value(3);
    // cout << "s2: " << s2 << endl;
    // s2.remove_value(10);
    // cout << "s2: " << s2 << endl << endl;
    
    // todo (g)
    // s1.set_value(3);
    // set s3 = s1+s2;
    // cout << "s3: " << s3 << endl << endl;
              
    return EXIT_SUCCESS;
}

