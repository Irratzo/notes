/*	Author: A.Voss@FH-Aachen.de
 */

#include <iostream>
#include <iomanip>
using namespace std;

// - eine Funktion, die die uebergebene Variable auf 23 setzt
// - dazu wird nicht die Adresse uebergeben, sondern eine Referenz (ein Alias)
//   auf die Variable, in die der Wert reingeschrieben wird
// - n "ist" die Variable, die gesetzt wird 
void init(int& n) {
    n = 23;
}

// - eine Funktion, die Speicher reserviert und diesen Zeiger
//   "zurueck" geben moechte
// - analog zu init wird eine Referenz auf die zu veraendernde
//   Variable uebergeben, nur dass der Typ dieser Variablen nun
//   ein Zeiger ist, daher haben wir eine Referenz auf einen
//   int-Zeiger
void reserve(int*& pn) {
    pn = new int[3];
    *(pn+0) = 11;
    *(pn+1) = 12;
    *(pn+2) = 13;
}

int main()
{
    cout << endl << "---" << endl << endl;
    
    // - eine Variable n und eine Referenz auf n
    // - nochmal: rn ist ein "Alias" fuer n, d.h. veraendert man
    //   rn, veraendert man direkt n
    // - man beachte, rn kann nur einmal initialisiert werden, das ist
    //   ein Unterschied zu Zeigern, die immer neu gesetzt werden koennen
    int n = 1; 
    int& rn = n; 
    cout << "01) Wert von n: " << n << endl;
    cout << "    Wert von rn: " << rn << endl;
 
    cout << endl << "---" << endl << endl;

    // - n wird ueber den Alias geaendert
    rn = 2;
    cout << "02) Wert von n: " << n << endl;
    cout << "    Wert von rn: " << rn << endl;

    cout << endl << "---" << endl << endl;
 
    // - ein int Feld und eine Referenz auf das dritte Element (Index 2)
    // - das dritte Element wird ueber ra2 referenziert
    int a[] = { 7, 11, 13 };
    int& ra2 = a[2];
    
    // - das dritte Element wird ueber ra2 veraendert
    // - das zweite Element wird ueber eine Referenz auf a[1] ueber init
    //   veraendert
    // - man beachte, dass *(a+1) vom Typ int ist, deshalb ist der Aufruf
    //   von init in Ordnung
    ra2 = 17;
    init(*(a+1));
    cout << "03) Werte von a, d.h." 
         << " a[0]: " << a[0] 
         << ", a[1]: " << a[1] 
         << ", a[2]: " << a[2] 
         << endl;

    cout << endl << "---" << endl << endl;

    // - in v soll nach Aufruf von reserve der Anfang eines reservierten 
    //   int-Feldes stehen
    // - es wird analog zu init eine Referenz auf die Variablen, hier v, uebergeben
    // - dadurch haben wir eine Referenz auf v, d.h. vom Typ Ref. auf *int, siehe reserve
    // - v wird zuerst mit "null" initialisiert, das ist die Konstante nullptr
    int* v = nullptr;
    cout << "04) Wert von v: " << hex << v << dec << endl;
    reserve(v);
    cout << "    Wert von v: " << hex << v << dec << endl;
    cout << "    Wert von v[0]: " << v[0] << endl;
    cout << "    Wert von v[1]: " << v[1] << endl;
    cout << "    Wert von v[2]: " << v[2] << endl;
    delete [] v;

    cout << endl << "---" << endl << endl;
 
    return EXIT_SUCCESS;
}

