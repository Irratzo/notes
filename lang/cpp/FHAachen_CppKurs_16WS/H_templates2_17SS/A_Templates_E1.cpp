// author: a.voss@fh-aachen.de

#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    cout << endl << "--- " << __FILE__ << " ---" << endl << endl;
    
    // Eine template (generic) class set, hier mit int-Elementen.
    // set modelliert eine (mathematische) Menge von Daten. Es gibt 
    // keine dopelten Elemente.
    set<int> si = { 1,2,3 };
    si.insert(4);
	cout << "1)    size of si: " << si.size() << endl;

    // Eine andere Mengenklasse, basierend auf set mit chars.
    // Das ist eine andere Klasse als set<int> !
    set<char> sc = { 'A','B','C' };
	cout << "2)    size of sc: " << sc.size() << endl;

    // Eine template class vector, d.h. eine Art array mit int-Elementen.
    vector<int> v = { 1,2,3,4 };
    v.push_back(5);
	cout << "3)    size of v: " << v.size() << endl << endl;

    // Warum generische Klassen?
    // Wichtige Argument sind Typsicherheit sowie Reduzierung von 
    // im Prinzip gleichem Code, nur fuer unterschiedliche Datentypen. 
    // Bsp. Quicksort.
    
    return 0;
}

