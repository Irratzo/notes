/*	Author: A.Voss@FH-Aachen.de
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << endl << "---" << endl << endl;
    
    // - zwei lokale Variablen n,m
    // - liegen auf dem Stack hintereinander oder nah beieinander, das 
    //   haengt vom Compiler ab, d.h. ihre Speicheradressen sind nicht
    //   weit von einander entfernt
    int n = 1; 
    int m = 2; 
    cout << "01) Wert von n: " << n << endl;
    cout << "    Wert von m: " << m << endl;
    cout << "    Speicheradresse von n, aka &n: " << hex << &n << dec << endl;
    cout << "    Speicheradresse von m, aka &m: " << hex << &m << dec << endl;

    cout << endl << "---" << endl << endl;

    // - eine weitere lokale Variable p, ein "Zeiger auf int", liegt  
    //   ebenfalls auf dem Stack, d.h. ihre Speicheradresse ist 
    //   nahe bei n und m
    // - der Wert (!) von p ist jetzt eine der Adressen, hier zunaechst 
    //   die von n
    // - man sagt, "sie zeigt auf n"
    // - der Wert, auf den sie zeigt, ist demnach der von n
    int* p = &n;
    cout << "02) Wert von p: " << hex << p << dec << endl;
    cout << "    Speicheradresse von p, aka &p: " << hex << &p << dec << endl;
    cout << "    Wert, auf den p zeigt, aka *p: " << *p << endl;

    cout << endl << "---" << endl << endl;

    // - die Variable p kann auf verschiedene andere int-Variablen "zeigen",
    //   dazu muessen wir nur ihren Wert (!) aendern, hier zeigt sie 
    //   jetzt auf m
    // - der Wert, auf den sie dann zeigt, ist demnach der von m
    p = &m;
    cout << "03) Wert von p: " << hex << p << dec << endl;
    cout << "    Speicheradresse von p, aka &p: " << hex << &p << dec << endl;
    cout << "    Wert, auf den p zeigt, aka *p: " << *p << endl;

    cout << endl << "---" << endl << endl;
    
    // - eine weitere lokale Variable k, nahe bei n,m und p
    // - der Zeiger p kann auch dazu verwendet werden, den Wert, auf
    //   den er zeigt, zu aendern
    // - hier zeigt er auf k und dieser Wert von k wird ueber p geaendert,
    //   danach hat k einen neuen Wert
    // - der Zeiger p hat die ganze Zeit ueber den gleichen Wert
    // - man spricht auch beim *-Operator in Verbindung mit Zeigern vom 
    //   Dereferenzieren
    int k = 3;
    cout << "04) Wert von k: " << k << endl;
    cout << "    Speicheradresse von k, aka &k: " << hex << &k << dec << endl;

    p = &k;
    cout << "    Wert von p: " << hex << p << dec << endl;
    cout << "    Wert, auf den p zeigt, aka *p: " << *p << endl;

    cout << "    *p = 4" << endl;
    *p = 4;

    cout << "    Wert von k: " << k << endl;
    cout << "    Wert von p: " << hex << p << dec << endl;
    cout << "    Wert, auf den p zeigt, aka *p: " << *p << endl;
 
    cout << endl << "---" << endl << endl;
   
    return EXIT_SUCCESS;
}

