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

/*
aendert die entsprechende kreuzung in labyrinth_original
ACHTUNG! labyrinth_original hat vertauschte x- und y-Koordinaten!

Crash-Kurs Funktionsparameter:
- fct(..., int var, ...) {... var ...}
Kopie von playerX in Funktion. Wird nur IN Funktion geändert.
- fct(..., int *var, ...) {... *var ...}
Zeiger auf die echte var. Bei Funktionsaufruf mit fct(&var) angeben.
- fct(..., int &var, ...) {... var ...}
Referenz auf echte var. Fktaufruf mit fct(var). Kann nicht auf andere Var
umgebogen werden nach Parameterübergabe.

*/
void setzeKreuzung(int &playerX, int &playerY, char move);


/*base class K3

 */
class K3 {
 protected:
  int *player, *wall, *block, *entry, *exit, *perm, *permindex;
  char *LorR;
 public:
  K3 (char, char, char, char, char); //constructor for translating coordinates
  ~K3 ();       //destructor
  void permutate();
  int ret_entry () {return *entry;}
  int ret_exit () {return *exit;}
  int ret_block () {return *block;}
  int ret_player () {return *player;}
  void bubblesort ();
};

/*
class K3R: public K3 {
 public: 
  K3R (char, char, char, char); //constructor for translating coordinates
  ~K3R ();       //destructor
  void permutate();
};

class K3L: public K3 {
 public: 
  K3L (char, char, char, char); //constructor for translating coordinates
  ~K3L ();       //destructor
  void permutate();
};

*/


#endif
