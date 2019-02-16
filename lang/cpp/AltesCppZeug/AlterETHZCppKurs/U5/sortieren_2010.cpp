/***
* Musterloesung D-ITET Info 1,
*
* Dieses Programm sortiert die Zahlen, die als
* Parameter beim aufruf uebergeben werden und gibt diese
* auf dem Terminal aus
*/

#include <iostream>
#include <cstring>
#include <stdlib.h>

using namespace std;

/*
sortiert die liste mit der lenge length
*/
void sortierenDurchEinfuegen(int liste[], int length) {
    int i;
    
    //die liste durchlaufen
    for (i = 0; i < length; i++) {
        int j;
        //den Wert an der aktuellen position...
        int v = liste[i];
        
        //so lange die Vorgaenger nach 
        //hinten schieben, bis ein Vorgaenger 
        //kleiner oder gleich ist wie v
		j = i;
        while (j > 0 && v < liste[j-1]) {
            //den Vorgaenger um eines nach hinten schieben
            liste[j] = liste[j-1];
			j--;
        }
        
        //jetzt ist die position gefunden
        //und Platz geschaffen, also
        //das v hier einfuegen.
        liste[j] = v;
    }
}

int main(int argc, char* argv[]) {

    //wie viele Zahlen muessen sortiert
    //werden? (argc-1, da der erste parameter
    //der Programmname ist)
    int anzahlZahlen = argc - 1;
    
    //die eingabeparameter in ein array von 
    //Zahlen wandeln
    int* liste = new int[anzahlZahlen];
    for (int i = 1; i < argc; i++) {
        liste[i-1] = atoi(argv[i]);
    }
    
    //sortieren
    sortierenDurchEinfuegen(liste, anzahlZahlen);
    
    //und ausgeben
    for (int i = 0; i < anzahlZahlen; i++) {
        cout << liste[i] << " ";
    }
    cout << endl;
}
