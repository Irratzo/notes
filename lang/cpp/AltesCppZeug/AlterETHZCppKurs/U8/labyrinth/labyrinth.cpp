/***
* D-ITET Info 1, Uebung 8, Aufgabe 1
*
* Header-File des Labyrinth Frameworks
*
* Ein Labyrinth ist
* ein zweidimensionales Array von char
* dar. Ein 'X' bedeutet ein Hindernis, 
* ein Leerzeichen freien Raum.
*
* Das Framework bietet Funktionen, um
* ein solches Labyrinth von einem Textfile
* einzulesen, auf dem Terminal auszudrucken,
* und einzelne Zeichen zu lesen und zu schreiben
*/

#include "labyrinth.h"
#include <iostream>
#include <cstring>
#include <stdio.h>

using namespace std;

//die wirkliche groesse des Labyrinths
//diese Zahlen werden aus dem Labyrinth-File eingelesen
int size_x;
int size_y;

//labyrinthOriginal enthaelt die original zeichen aus dem
//labyrinth file. Es wird durch resetLabyrinth() in die
//oeffentliche labyrinth-variable kopiert
//das labyrinthOriginal hat vertauschte X und Y coordinaten!
//dies macht das Einlesen einfacher
char labyrinth_original[80][80];

//die "gebrauchs-version" des labyrinths. Wenn
//zeichen geschrieben werden, wird diese Version veraendert
char labyrinth[80][80];

//die Groesse des Labyrinths in X- und Y-Richtung
int sizeX() {
    return size_x;
}
int sizeY() {
    return size_y;
}

//laedt das labyrinth
int loadLabyrinth(char *filename) {
    FILE *fp;
    
    //das file oeffnen
        
    //die groesse des labyrinths einlesen
            
    //jeweils eine zeile als original einlesen
    char dump[2];
        //skip newlines
        fgets(dump, 2, fp);
    }

    //file schliessen
    fclose(fp);
    
    //in die labyrinth matrix kopieren
    resetLabyrinth();
    return 0;
}

//labyrinth resetten
void resetLabyrinth() {
    int x, y;
    //das original in die "Gebrauchs-Version" kopieren
        }
    }
}

//das labyrinth auf dem terminal ausgeben
void printLabyrinth() {
    
    cout << endl << endl;
    
    //die zehner der oberen Koordinatenachse
    cout << "\t";
    for (x = 0; x < size_x; x++) {
            cout << x / 10;
        } else {
            cout << " ";
        }
    }
    
    //die einer der Koordinatenachse
    cout << endl;
    cout << "\t";
    for (x = 0; x < size_x; x++) {
    }
    cout << endl;
    
    //das Labyrinth zeilenweise ausgeben
        //die Zahl der y-Achse
        cout << y << "\t";
        
        //die einzelnen Felder
        }
        cout << endl;
    }
}

char zeichenAnPosition(int x, int y) {
    return labyrinth[x][y];
}
void setzeZeichen(char zeichen, int x, int y) {
    labyrinth[x][y] = zeichen;
}