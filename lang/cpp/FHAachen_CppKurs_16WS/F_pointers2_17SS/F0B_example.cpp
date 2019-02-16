/*	Author: A.Voss@FH-Aachen.de
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << endl << "---" << endl << endl;
    
    // - ein Feld der Laenge 3 mit drei Werten
    // - Zugriff lesend ganz klassisch ueber []-Operatoren
    int a[] = { 7, 11, 13 };
    cout << "01) Werte von a, d.h." 
         << " a[0]: " << a[0] 
         << ", a[1]: " << a[1] 
         << ", a[2]: " << a[2] 
         << endl;

    cout << endl << "---" << endl << endl;

    // - die Speicheradressen der Elemente liegen hintereinander 
    cout << "02) Speicheradresse von a[0], aka &(a[0]): " << hex << &(a[0]) << dec << endl; 
    cout << "    Speicheradresse von a[1], aka &(a[1]): " << hex << &(a[1]) << dec << endl; 
    cout << "    Speicheradresse von a[2], aka &(a[2]): " << hex << &(a[2]) << dec << endl; 

    cout << endl << "---" << endl << endl;

    // - a ist das Feld, gleichbedeutend mit der Adresse des ersten Elementes
    // - a+1, a+2 ist die Speicheradresse des naechsten bzw. uebernaechsten Elementes
    // - man beachte, a+1 ist nicht die naechste Adresse in Bytes sondern 
    //   die Adresse des naechsten int-Wertes, also hier 4 Bytes weiter; 
    //   a+2 analog 8 Bytes weiter, genannt "Zeigerarithmetik"
    cout << "03) Speicheradresse von a: " << hex << a << dec << endl; 
    cout << "    Speicheradresse von a+1: " << hex << a+1 << dec << endl; 
    cout << "    Speicheradresse von a+2: " << hex << a+2 << dec << endl; 

    cout << endl << "---" << endl << endl;

    // - man kann so auch auf die Werte a[0]..a[2] zugreifen
    cout << "04) Wert von *(a+0): " << dec << *(a+0) << endl; 
    cout << "    Wert von *(a+1): " << *(a+1) << endl; 
    cout << "    Wert von *(a+2): " << *(a+2) << endl; 

    cout << endl << "---" << endl << endl;

    // - statt mit a+1,a+2 etc. kann man auch uber einen Zeiger auf die
    //   Elemente zugreifen
    // - p wird explizit mit der Adresse des ersten Elementes init.,
    //   alternativ waere auch p=a moeglich
    int* p = &(a[0]);
    cout << "05) Wert von p: " << hex << p << dec << endl;
    cout << "    Wert, auf den p zeigt, aka *p: " << *p << endl;
    cout << "    Wert von *(p+2): " << *(p+2) << endl; 

    cout << endl << "---" << endl << endl;

    // - Schleife ueber a mit dem Zeiger p
    // - man beachte, dass die Zeigerarithmetik auch mit Minus funktioniert,
    //   also p-a ist die Entfernung von p zu a gemessen in int-Laengen, nicht
    //   in Bytes, deswegen funktioniert p-a<3
    cout << "06) Loop ueber a mit p:" << endl;
    for (p = a; p-a < 3; ++p) {
        cout << "    Loop: " << (p-a) << endl;
        cout << "        Wert von p: " << hex << p << dec << endl;
        cout << "        Wert, auf den p zeigt, aka *p: " << *p << endl;
    }

    cout << endl << "---" << endl << endl;

    // - Schleife ueber a mit Index i
    cout << "07) Loop ueber a mit i:" << endl;
    p = a;
    for (int i = 0; i < 3; ++i) {
        cout << "    Loop: " << i << endl;
        cout << "        Wert von p+i: " << hex << p+i << dec << endl;
        cout << "        Wert, auf den p+i zeigt, aka *(p+i): " << *(p+i) << endl;
    }

    cout << endl << "---" << endl << endl;

    // - Schleife ueber ein dynamisch allokiertes Feld v der Laenge 5
    // - Init. mit 100,101,...104
    const int len = 5;
    int* v = new int[len];
    for (p=v; (p-v)<len; ++p) {
        *p = 100 + (int)(p-v);
    }

    // - Ausgabe der Werte entweder ueber den []-Operator oder ueber 
    //   den Zeiger
    cout << "08) Loop ueber v mit i:" << endl;
    for (int i=0; i<len; ++i) {
        cout << "    Loop: " << i << endl;
        cout << "        Wert v[i]: " << v[i] << endl;
        cout << "        Wert *(v+i): " << *(v+i) << endl;
    }
    
    delete [] v;

    cout << endl << "---" << endl << endl;

    return EXIT_SUCCESS;
}

