/***
* Musterloesung D-ITET Info 1, Uebungsserie 4, Aufgabe 1.2b
*
* Ein kleines Programm, dass zwei Vektoren addiert
*/

#include <iostream>
using namespace std;

const int maxLaenge = 100;

int main ()
{
   //die Laenge der Vektoren vom Benutzer erfragen
   unsigned int laenge = 0;
   cout << "Wie viele Komponenten sollen die Vektoren haben? ";
   cin >> laenge;

   if(!cin || laenge > 100) {
      cerr << "Zu viele Komponenten" << endl;
      return 1;
   }

   //die Eingabevektoren mit der richtigen Laenge erzeugen
   int a[maxLaenge], b[maxLaenge];

   //die einzelnen Komponenten von Vektor a erfragen
   for (unsigned int i = 0; i < laenge; i++) {
      cout << "Komponente " << i+1 << " von Vektor a? ";
      cin >> a[i];
   }

   cout << endl;

   //die einzelnen Komponenten von Vektor b erfragen
   for (unsigned int i = 0; i < laenge; i++) {
      cout << "Komponente " << i+1 << " von Vektor b? ";
      cin >> b[i];
   }

   //der Ergebnisvektor
   int ergebnis[maxLaenge];

   for (unsigned int i = 0; i < laenge; i++) {
      ergebnis[i] = a[i] + b[i];
   }

   cout << endl;

   //das Ergebnis komponentenweise ausgeben
   for (unsigned int i = 0; i < laenge; i++) {
      cout << "Komponente " << i+1 << " des Ergebnisvektors ist " << ergebnis[i] << endl;
   }

   //Programm beenden
   return 0;
}
