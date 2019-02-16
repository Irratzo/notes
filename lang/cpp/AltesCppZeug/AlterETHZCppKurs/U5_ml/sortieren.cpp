/***
* Musterloesung D-ITET Info 1, Uebung 5 Aufgabe 1
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
sortiert die liste mit der laenge length
*/
void sortierenDurchAufsteigen(int liste[], int length) {
    int i = length-1;
	bool vertauscht = true;
    
    //die liste durchlaufen solange noch Aenderungen
	//noetig sind
    while (vertauscht && i > 1){
		vertauscht = false;
        for (int j = 0; j < i; ++j){
			if (liste[j] > liste[j+1]){
				int lnext = liste[j+1];
				
				// Die beiden verglichenen Werte vertauschen
				liste[j+1] = liste[j];
				liste[j] = lnext;
				vertauscht = true;
			}
		}
		--i;
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
    sortierenDurchAufsteigen(liste, anzahlZahlen);
    
    //und ausgeben
    for (int i = 0; i < anzahlZahlen; i++) {
        cout << liste[i] << " ";
    }
    cout << endl;
}
