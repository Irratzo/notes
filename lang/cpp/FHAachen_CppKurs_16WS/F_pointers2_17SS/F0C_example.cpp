/*	Author: A.Voss@FH-Aachen.de
 */

#include <iostream>
#include <iomanip>
using namespace std;

// - eine Funktion, die die uebergebene Variable auf 23 setzt
// - dazu wird die Adresse uebergeben, also der Zeiger, wo der
//   Wert reingeschrieben wird
void init(int* pn) {
    *pn = 23;
}

// - eine Funktion, die Speicher reserviert und diesen Zeiger
//   "zurueck" geben moechte
// - analog zu init wird jetzt ein Zeiger auf die zu veraendernde
//   Variable uebergeben, nur dass der Typ dieser Variablen nun
//   selber ein Zeiger ist, daher haben wir einen Zeiger auf einen
//   int-Zeiger
void reserve(int** ppn) {
    *ppn = new int[3];
    *(*ppn+0) = 11;
    *(*ppn+1) = 12;
    *(*ppn+2) = 13;
}

int main()
{
    cout << endl << "---" << endl << endl;
    
    // - eine int-Variable, ein Zeiger auf eine int-Variable (int-Zeiger)
    //   und ein Zeiger auf einen int-Zeiger
    // - der int-Zeiger zeigt auf n und der int-int-Zeiger auf den int-Zeiger
    // - man kann die Typdeklaration von rechts nach links lesen, * heisst
    //   "Zeiger auf", also 
    //     int* liest sich "Zeiger auf int"
    //     int** liest sich "Zeiger auf Zeiger auf int"
    // - die Variablen n,pn und ppn liegen lokal auf dem Stack zusammen
    int n = 1; 
    int* pn = &n;
    int** ppn = &pn;

    cout << "01) Wert von n: " << n << endl;
    cout << "    Speicheradresse von n, aka &n: " << hex << &n << dec << endl;
    cout << "    Wert von pn: " << hex << pn << dec << endl;
    cout << "    Speicheradresse von pn, aka &pn: " << hex << &pn << dec << endl;
    cout << "    Wert von ppn: " << hex << ppn << dec << endl;
    cout << "    Speicheradresse von ppn, aka &ppn: " << hex << &ppn << dec << endl;

    cout << endl << "---" << endl << endl;

    // - der Wert von n wird veraendert und ueber den int-Zeiger und den
    //   int-int-Zeiger gelesen, einmal dereferenziert (*) bzw. 
    //   zweimal dereferenziert (**)
    // - pn ist der Zeiger, *pn der Wert, hier n
    //   ppn ist der int-int-Zeiger, *ppn der int-Zeiger und **ppn der Wert n
    n = 2;
    cout << "02) Wert von n: " << n << endl;
    cout << "    Wert von n ueber pn: " << *pn << endl;
    cout << "    Wert von n ueber ppn: " << **ppn << endl;

    cout << endl << "---" << endl << endl;

    // - Anwendung von Zeigern, z.B. um Werte von Variablen zu aendern,
    //   die ausserhalb der Funktion leben, in der sie geaendert werden
    // - hier soll n initialisiert=gesetzt werden
    // - dazu wird die Adresse von n, also &n, uebergeben
    init(&n);
    cout << "03) Wert von n: " << n << endl;

    cout << endl << "---" << endl << endl;

    // - in v soll nach Aufruf von reserve der Anfang eines reservierten 
    //   int-Feldes stehen
    // - es wird analog zu init die Adresse der Variablen, hier v, uebergeben
    // - dadurch haben wir einen Zeiger auf v, d.h. vom Typ **int, siehe reserve
    // - v wird zuerst mit "null" initialisiert, das ist die Konstante nullptr
    int* v = nullptr;
    cout << "04) Wert von v: " << hex << v << dec << endl;
    reserve(&v);
    cout << "    Wert von v: " << hex << v << dec << endl;
    cout << "    Wert von v[0]: " << v[0] << endl;
    cout << "    Wert von v[1]: " << v[1] << endl;
    cout << "    Wert von v[2]: " << v[2] << endl;
    delete [] v;
 
    cout << endl << "---" << endl << endl;
  
    return EXIT_SUCCESS;
}

