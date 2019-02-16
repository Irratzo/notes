/***
* Musterloesung D-ITET Info 1, Uebungsserie 4, Aufgabe 1
*
* Ein kleines Programm, dass zwei Vektoren addiert
*/

#include <iostream>
using namespace std;


int main ()
{

   //die Eingabevektoren Laenge 3 erzeugen
   int a[3], b[3];

   //die einzelnen Komponenten von Vektor a erfragen
   for (unsigned int i = 0; i < 3; i++) {
      cout << "Komponente " << i+1 << " von Vektor a? ";
      cin >> a[i];
   }

   cout << endl;

   //die einzelnen Komponenten von Vektor b erfragen
   for (unsigned int i = 0; i < 3; i++) {
      cout << "Komponente " << i+1 << " von Vektor b? ";
      cin >> b[i];
   }

   //der Ergebnisvektor
   int ergebnis[3];

   for (unsigned int i = 0; i < 3; i++) {
      ergebnis[i] = a[i] + b[i];
   }

   cout << endl;

   //das Ergebnis komponentenweise ausgeben
   for (unsigned int i = 0; i < 3; i++) {
      cout << "Komponente " << i+1 << " des Ergebnisvektors ist " << ergebnis[i] << endl;
   }

   //Programm beenden
   return 0;
}
