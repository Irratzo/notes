/***
 * D-ITET Informatik 1, Uebungsserie 8, Aufgabe 2
 *
 * Koautor: Johannes Wasmer
 * Datum: 23.11.2011
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
#include <stdlib.h>

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
  int y;
    
  //das file oeffnen
  if (!(fp = fopen(filename, "r")))
    {
      cout << "Labyrinth-Datei existiert nicht\n";
      getchar();
      return -1;
    }
        
  //die groesse des labyrinths einlesen
  fscanf(fp, "%d %d\n", &size_x, &size_y);
            
  //jeweils eine zeile als original einlesen
  char dump[2];
  for (y = 0; y< size_y; y++) {
    fgets(labyrinth_original[y], size_x+1, fp);
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
  for (x = 0; x < size_x; x++) {
    for (y = 0; y < size_y; y++) {
      labyrinth[x][y] = labyrinth_original[y][x];
    }
  }
}

//das labyrinth auf dem terminal ausgeben
void printLabyrinth() {
  int x, y;
    
  cout << endl << endl;
    
  //die zehner der oberen Koordinatenachse
  cout << "\t";
  for (x = 0; x < size_x; x++) {
    if (x%10 == 0) {
      cout << x / 10;
    } else {
      cout << " ";
    }
  }
    
  //die einer der Koordinatenachse
  cout << endl;
  cout << "\t";
  for (x = 0; x < size_x; x++) {
    cout << x%10;
  }
  cout << endl;
    
  //das Labyrinth zeilenweise ausgeben
  for (y = 0; y < size_y; y++) {
    //die Zahl der y-Achse
    cout << y << "\t";
        
    //die einzelnen Felder
    for (x = 0; x < size_x; x++) {
      cout << labyrinth[x][y];
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

bool pathFinder(int sx, int sy, int zx, int zy) {
  
  if (sx == zx && sy == zy) return true;
  if (zeichenAnPosition(sx,sy) != ' ') {
    return false;
  }

  setzeZeichen('>',sx,sy);

  if(pathFinder(sx+1,sy,zx,zy)) 
    return true;
  
  setzeZeichen('<',sx,sy);

  if(pathFinder(sx-1,sy,zx,zy))
    return true;
 
  setzeZeichen('^',sx,sy);

  if(pathFinder(sx,sy-1,zx,zy))
    return true;

  setzeZeichen('v',sx,sy);

  if(pathFinder(sx,sy+1,zx,zy))
    return true;

  setzeZeichen('.',sx,sy);
  return false;
}

int main(int argc, char** argv) {

  if (argc < 2) 
    cout << argv[0] << " <filename> " << endl;
	
  loadLabyrinth(argv[1]);
  char doagain = 'k'; 

  do {
    printLabyrinth();

    int xanf = 0;
    int yanf = 0;
    int xend = 0;
    int yend = 0;

    cout << "Geben Sie die X-Koordinate fuer den Start ein: " ;
    cin >> xanf;
    cout << "Geben Sie die Y-Koordinate fuer den Start ein: " ;
    cin >> yanf;
    while (zeichenAnPosition(xanf,yanf) == 'X' || xanf > 39 || yanf > 19 || xanf < 0 || yanf < 0) {
      setzeZeichen('@',xanf,yanf);
      printLabyrinth();
      cout << "Die angegebene Koordinate ist Mauerwerk oder liegt ausserhalb des Labyrinthes. Bitte waehlen Sie einen anderen Startwert aus. Zur Orientierung ist Ihre Auswahl im Labyrinth mit '@' markiert." << endl;
      cout << "Geben Sie die X-Koordinate fuer den Start ein: " ;
      cin >> xanf;
      cout << "Geben Sie die Y-Koordinate fuer den Start ein: " ;
      cin >> yanf;
    }
    resetLabyrinth();
    setzeZeichen('S',xanf,yanf);

    cout << "Geben Sie die X-Koordinate fuer das Ziel ein: " ;
    cin >> xend;
    cout << "Geben Sie die Y-Koordinate fuer das Ziel ein: " ;
    cin >> yend;
    while (zeichenAnPosition(xend,yend) == 'X' || xanf > 39 || yanf > 19 || xanf < 0 || yanf < 0) {
      setzeZeichen('@',xanf,yanf);
      printLabyrinth();
      cout << "Die angegebene Koordinate ist Mauerwerk oder liegt ausserhalb des Labyrinthes. Bitte waehlen Sie einen anderen Startwert aus. Zur Orientierung ist Ihre Auswahl im Labyrinth mit '@' markiert." << endl;
      cout << "Geben Sie die X-Koordinate fuer das Ziel ein: " ;
      cin >> xend;
      cout << "Geben Sie die Y-Koordinate fuer das Ziel ein: " ;
      cin >> yend;
    }
    resetLabyrinth();
 
    //test bool value:
    bool found = pathFinder(xanf,yanf,xend,yend);
    setzeZeichen('S',xanf,yanf);
    setzeZeichen('Z',xend,yend);
    printLabyrinth();
    if (found)
      cout << "Ziel gefunden!" << endl;
    else 
  cout << "Ziel kann nicht erreicht werden." << endl;
 
    cout << "Wiederholen (j,n)?";
    cin >> doagain;
 
    resetLabyrinth();

  } while (doagain == 'j');


  return 0;

}


