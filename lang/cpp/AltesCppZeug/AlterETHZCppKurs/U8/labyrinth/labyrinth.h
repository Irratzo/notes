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

#ifndef LABYRINTH_H 
#define LABYRINTH_H

//die Groesse des Labyrinths in X- und Y-Richtung
int sizeX();
int sizeY();

/* 
liesst die angegebene Datei und laedt
das labyrinth in die gegebene Variable
Wenn alles erfolgreich war, wird 
0 zurueckgegeben. Ansonsten eine 1

Die Groesse des Labyrinths in x und y Richtung
wird durch zwei Zahlen in der ersten Zeile des
Eingabefiles angegeben.

Die maximale Groesse ist 80x80
*/
int loadLabyrinth(char *filename);

/*
Bringt das labyrinth zurueck in den 
Ausgangszustand wie direkt nach dem Lesen der Datei
*/
void resetLabyrinth();

/*
gibt das labyrinth auf dem Terminal aus
*/
void printLabyrinth();

/*
gibt das Zeichen an der gegebenen Position
im Labyrinth zurueck
*/
char zeichenAnPosition(int x, int y);

/*
setzt das Zeichen an der gegebenen Position
*/
void setzeZeichen(char zeichen, int x, int y);

#endif
