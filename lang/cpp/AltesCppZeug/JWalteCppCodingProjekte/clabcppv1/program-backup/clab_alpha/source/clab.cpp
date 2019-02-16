/*clab info
clab baut auf labyrinth.cpp aus Informatik I auf.

*/

#include "clab.h"
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
    
    //    cout << endl << endl;
    cout << endl;
    
    //die zehner der oberen Koordinatenachse
    // cout << "\t";
    // for (x = 0; x < size_x; x++) {
    //     if (x%10 == 0) {
    //         cout << x / 10;
    //     } else {
    //         cout << " ";
    //     }
    // }
    
    //die einer der Koordinatenachse
    // cout << endl;
    // cout << "\t";
    // for (x = 0; x < size_x; x++) {
    //     cout << x%10;
    // }
    // cout << endl;
    
    //das Labyrinth zeilenweise ausgeben
    for (y = 0; y < size_y; y++) {
        //die Zahl der y-Achse
      //        cout << y << "\t";
        
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

void setzeKreuzung(int &playerX, int &playerY, char move) {

  switch (move) {
  case 'w':
    labyrinth_original[playerY-1][playerX] = 'O'; 
    labyrinth_original[playerY+1][playerX] = 'O'; 
    labyrinth_original[playerY][playerX-1] = ' '; 
    labyrinth_original[playerY][playerX+1] = ' '; 
    playerY -= 2;
    break;
  case 's':
    labyrinth_original[playerY-1][playerX] = 'O'; 
    labyrinth_original[playerY+1][playerX] = 'O'; 
    labyrinth_original[playerY][playerX-1] = ' '; 
    labyrinth_original[playerY][playerX+1] = ' '; 
    playerY += 2;
    break;
  case 'a':
    labyrinth_original[playerY-1][playerX] = ' '; 
    labyrinth_original[playerY+1][playerX] = ' '; 
    labyrinth_original[playerY][playerX-1] = 'O'; 
    labyrinth_original[playerY][playerX+1] = 'O'; 
    playerX -= 2;
    break;
  case 'd':
    labyrinth_original[playerY-1][playerX] = ' '; 
    labyrinth_original[playerY+1][playerX] = ' '; 
    labyrinth_original[playerY][playerX-1] = 'O'; 
    labyrinth_original[playerY][playerX+1] = 'O'; 
    playerX += 2;
    break;
  }
}

 char move = '0';

void setze3erK(int &playerX, int &playerY, int rentry, int rexit, int rblock, int rplayer) {

  switch (rentry) {
  case 0:
    labyrinth_original[playerY+1][playerX] = ' ';
    break;
  case 1:
    labyrinth_original[playerY][playerX-1] = ' ';
    break;
  case 2:
    labyrinth_original[playerY-1][playerX] = ' ';
    break;
  case 3:
    labyrinth_original[playerY][playerX+1] = ' ';
    break;
  }

  switch (rexit) {
  case 0:
    labyrinth_original[playerY+1][playerX] = ' ';
    break;
  case 1:
    labyrinth_original[playerY][playerX-1] = ' ';
    break;
  case 2:
    labyrinth_original[playerY-1][playerX] = ' ';
    break;
  case 3:
    labyrinth_original[playerY][playerX+1] = ' ';
    break;
  }

  switch (rblock) {
  case 0:
    labyrinth_original[playerY+1][playerX] = '0';
    break;
  case 1:
    labyrinth_original[playerY][playerX-1] = '0';
    break;
  case 2:
    labyrinth_original[playerY-1][playerX] = '0';
    break;
  case 3:
    labyrinth_original[playerY][playerX+1] = '0';
    break;
  }

  if (rblock == rplayer) {
    switch (rplayer) {
    case 0: 
      playerY += 2;
      break;
    case 1:
      playerX -= 2;
      break;
    case 2:
      playerY -= 2;
      break;
    case 3:
      playerX += 2;
      break; 
    }
  }
  else {
    switch (rplayer) {
    case 0: 
      playerY += 1;
      break;
    case 1:
      playerX -= 1;
      break;
    case 2:
      playerY -= 1;
      break;
    case 3:
      playerX += 1;
      break; 
    }
  }


  if ((zeichenAnPosition(playerX, playerY) == 'O') || (zeichenAnPosition(playerX, playerY) == '0'))
    move = 'r';

}

//K3 Definitionen BEGIN

void K3::bubblesort () {
  int n = 3;
  bool sorted;

  do {
    sorted = false;
    for (int i=0;i<n-1;i++) {
      if (perm[i] > perm[i+1]) {
	perm[3]=perm[i];
	perm[i]=perm[i+1];
	perm[i+1]=perm[3];

	sorted = true;
	
	if (LorR[0] == 'R') {
	  if ((*wall==0 && *entry==2 && *block==3 && *exit==1) || (*wall==1 && *entry==2 && *block==3 && *exit==0) || (*wall==2 && *entry==1 && *block==3 && *exit==0) || (*wall==3 && *entry==1 && *block==2 && *exit==0)) 
	    continue;

	    permindex[3]=permindex[i];
	    permindex[i]=permindex[i+1];
	    permindex[i+1]=permindex[3];

	}

	else{
	  if ((*wall==0 && *entry==3 && *block==1 && *exit==2) || (*wall==1 && *entry==3 && *block==0 && *exit==2) || (*wall==2 && *entry==3 && *block==0 && *exit==1) || (*wall==3 && *entry==2 && *block==0 && *exit==1)) 
	    continue;

	    permindex[3]=permindex[i];
	    permindex[i]=permindex[i+1];
	    permindex[i+1]=permindex[3];
	  
	  }


      }
    }
    n--;
  }while(sorted && (n>1));


}


//K3 constructor
K3::K3(char south, char west, char north, char east, char RorL) {
  wall = new int;
  entry = new int;
  block = new int;
  exit = new int;
  perm = new int [4];
  perm[3] = 0;
  permindex = new int [4];
  permindex[0] = 0;
  permindex[1] = 1;
  permindex[2] = 2;
  LorR = new char[1];

  LorR[0] = RorL;

  if (south == 'O')
    *wall = 0;
  else if (west == 'O')
    *wall = 1;
  else if (north == 'O')
    *wall = 2;
  else if (east == 'O')
    *wall = 3;
  else {} 

  if (south == 'P')
    *entry = 0;
  else if (west == 'P')
    *entry = 1;
  else if (north == 'P')
    *entry = 2;
  else if (east == 'P')
    *entry = 3;
  else {}
  perm[0] = *entry;

  if (south == '0')
    *block = 0;
  else if (west == '0')
    *block = 1;
  else if (north == '0')
    *block = 2;
  else if (east == '0')
    *block = 3;
  else {}
  perm[1] = *block;

  if (south == ' ')
    *exit = 0;
  else if (west == ' ')
    *exit = 1;
  else if (north == ' ')
    *exit = 2;
  else if (east == ' ')
    *exit = 3;
  else {}
  perm[2] = *exit;

  player = new int;
  *player = *exit;

  bubblesort();

}

//K3 deconstructor
K3::~K3() {
  delete player;
  delete wall;
  delete block;
  delete entry;
  delete exit;
  delete perm;
  delete permindex;
  delete LorR;
}

void K3::permutate () {

  if (LorR[0] == 'R') {

    if ((*wall==0 && *entry==2 && *block==3 && *exit==1) || (*wall==0 && *entry==3 && *block==1 && *exit==2) || (*wall==1 && *entry==2 && *block==3 && *exit==0) || (*wall==1 && *entry==3 && *block==0 && *exit==2) || (*wall==2 && *entry==1 && *block==3 && *exit==0) || (*wall==2 && *entry==3 && *block==0 && *exit==1) || (*wall==3 && *entry==1 && *block==2 && *exit==0) || (*wall==3 && *entry==2 && *block==0 && *exit==1)) {

    perm[3] = perm[2];
    perm[2] = perm[1];
    perm[1] = perm[0];
    perm[0] = perm[3];

    }
    else{

    perm[3] = perm[0];
    perm[0] = perm[1];
    perm[1] = perm[2];
    perm[2] = perm[3];

    }
  }
  else{

    if ((*wall==0 && *entry==2 && *block==3 && *exit==1) || (*wall==0 && *entry==3 && *block==1 && *exit==2) || (*wall==1 && *entry==2 && *block==3 && *exit==0) || (*wall==1 && *entry==3 && *block==0 && *exit==2) || (*wall==2 && *entry==1 && *block==3 && *exit==0) || (*wall==2 && *entry==3 && *block==0 && *exit==1) || (*wall==3 && *entry==1 && *block==2 && *exit==0) || (*wall==3 && *entry==2 && *block==0 && *exit==1)) {

    perm[3] = perm[0];
    perm[0] = perm[1];
    perm[1] = perm[2];
    perm[2] = perm[3];

    }
    else{

    perm[3] = perm[2];
    perm[2] = perm[1];
    perm[1] = perm[0];
    perm[0] = perm[3];

    }

  }

    *entry = perm[permindex[0]];
    *block = perm[permindex[1]];
    *exit = perm[permindex[2]];

}

//K3 Definitionen END
 


int main(int argc, char** argv) {

if (argc < 2) {
	cout << argv[0] << " <filename> " << endl; }
	
loadLabyrinth(argv[1]);
char doagain = 'k'; 

 cout << "-------------------------------------------------" << endl;
 cout << "Du bist P. Finde den Ausgang F aus dem Irrgarten." << endl;
 cout << "Eingaben: w,a,s,d = hoch,links,runter,rechts." << endl;
 cout << "Du hast Dich eingemauert? r setzt alles auf Anfang." << endl;
 cout << "Das bedeutet dann, dass Du einmal gestorben bist." << endl;
 cout << "e beendet das Spiel." << endl;
 cout << "Wird ein + ueberquert, drehen sich die Waende!" << endl;
 cout << "Geladener Irrgarten: " << argv[1] << endl;
 cout << "-------------------------------------------------" << endl;
 cout << "DAS SPIEL BEGINNT." << endl;

 //suche und setze Start- und Finishposition
 //und setze player auf start BEGIN

 int startX, startY, finishX, finishY, playerX, playerY = 0;
 char start, finish, player = '0';

 for (startY=0;startY < size_y; startY++) {  
   for (startX=0;startX < size_x; startX++) {
     if (zeichenAnPosition(startX,startY) == 'S') {

       break;
     }
   }
   if (zeichenAnPosition(startX,startY) == 'S') {
     break;
   } 
 }
 
 playerX = startX;
 playerY = startY;
 setzeZeichen ('P',playerX,playerY);
 
 for (finishY=0;finishY < size_y; finishY++) {  
   for (finishX=0;finishX < size_x; finishX++) {
     if (zeichenAnPosition(finishX,finishY) == 'F') {

       break;
     }
   }
   if (zeichenAnPosition(finishX,finishY) == 'F') {
     break;
   }
 }

 //suche und setze Start- und Finishposition
 //und setze player auf start END

 //beginne Spiel BEGIN

 int moveEval = 0;
 int moveCounter = 0;
 int deaths = 0;
 int coordtranslator = 0;
 char south, north, west, east = '0';
 int re_entry, re_exit, re_block, re_player = 0;
 char RorL = '0';

 do {

   setzeZeichen('P',playerX,playerY);
   printLabyrinth();

   cin >> move;
   moveCounter++;

   if (move == 'w') {
     moveEval = playerY - 1;
     if (zeichenAnPosition(playerX,moveEval) != 'O') {
       if (zeichenAnPosition(playerX,moveEval) != '0') {
	 playerY--; 
	   RorL = zeichenAnPosition(playerX,playerY);
	 if (zeichenAnPosition(playerX,moveEval) == '+') {
	   if ((zeichenAnPosition(playerX, playerY - 2) == 'O') || (zeichenAnPosition(playerX, playerY - 2) == '0'))
	     move = 'r';
	   setzeKreuzung(playerX,playerY,move);
	 }
	 else if ((RorL == 'R') || (RorL == 'L')) {
	   moveEval = playerY + 1;
	   south = zeichenAnPosition(playerX,moveEval);
	   moveEval = playerX - 1;
	   west = zeichenAnPosition(moveEval,playerY);
	   moveEval = playerY - 1;
	   north = zeichenAnPosition(playerX,moveEval);
	   moveEval = playerX + 1;
	   east = zeichenAnPosition(moveEval,playerY);
	   K3 turn3 (south,west,north,east,RorL);
	   turn3.permutate();
	   re_entry = turn3.ret_entry();
	   re_exit = turn3.ret_exit();
	   re_block = turn3.ret_block();
	   re_player = turn3.ret_player();
	   setze3erK(playerX,playerY,re_entry,re_exit,re_block,re_player);
	 }
	 else {}
       }
     }
     resetLabyrinth();
   }
   else if (move == 's') {
     moveEval = playerY + 1;
     if (zeichenAnPosition(playerX,moveEval) != 'O') {
       if (zeichenAnPosition(playerX,moveEval) != '0') {
	 playerY++; 
	   RorL = zeichenAnPosition(playerX,playerY);
	 if (zeichenAnPosition(playerX,moveEval) == '+') {
	   if ((zeichenAnPosition(playerX, playerY + 2) == 'O') || (zeichenAnPosition(playerX, playerY + 2) == '0'))
	     move = 'r';
	   setzeKreuzung(playerX,playerY,move);
	 }
	 else if ((RorL == 'R') || (RorL == 'L')) {
	   moveEval = playerY + 1;
	   south = zeichenAnPosition(playerX,moveEval);
	   moveEval = playerX - 1;
	   west = zeichenAnPosition(moveEval,playerY);
	   moveEval = playerY - 1;
	   north = zeichenAnPosition(playerX,moveEval);
	   moveEval = playerX + 1;
	   east = zeichenAnPosition(moveEval,playerY);
	   K3 turn3 (south,west,north,east,RorL);
	   turn3.permutate();
	   re_entry = turn3.ret_entry();
	   re_exit = turn3.ret_exit();
	   re_block = turn3.ret_block();
	   re_player = turn3.ret_player();
	   setze3erK(playerX,playerY,re_entry,re_exit,re_block,re_player);
	 }
	 else {}
       }
     }
     resetLabyrinth();
   }
   else if (move == 'a') {
     moveEval = playerX - 1;
     if (zeichenAnPosition(moveEval,playerY) != 'O') {
       if (zeichenAnPosition(moveEval,playerY) != '0') {
	 playerX--; 
	   RorL = zeichenAnPosition(playerX,playerY);
	 if (zeichenAnPosition(moveEval,playerY) == '+') {
	   if ((zeichenAnPosition(playerX - 2, playerY) == 'O') || (zeichenAnPosition(playerX - 2, playerY) == '0'))
	     move = 'r';
	   setzeKreuzung(playerX,playerY,move);
	 }
	 else if ((RorL == 'R') || (RorL == 'L')) {
	   moveEval = playerY + 1;
	   south = zeichenAnPosition(playerX,moveEval);
	   moveEval = playerX - 1;
	   west = zeichenAnPosition(moveEval,playerY);
	   moveEval = playerY - 1;
	   north = zeichenAnPosition(playerX,moveEval);
	   moveEval = playerX + 1;
	   east = zeichenAnPosition(moveEval,playerY);
	   K3 turn3 (south,west,north,east,RorL);
	   turn3.permutate();
	   re_entry = turn3.ret_entry();
	   re_exit = turn3.ret_exit();
	   re_block = turn3.ret_block();
	   re_player = turn3.ret_player();
	   setze3erK(playerX,playerY,re_entry,re_exit,re_block,re_player);
	 }
	 else {}
       }
     }
     resetLabyrinth();
   }
   else if (move == 'd') {
     moveEval = playerX + 1;
     if (zeichenAnPosition(moveEval,playerY) != 'O') {
       if (zeichenAnPosition(moveEval,playerY) != '0') {
	 playerX++; 
	   RorL = zeichenAnPosition(playerX,playerY);
	 if (zeichenAnPosition(moveEval,playerY) == '+') {
	   if ((zeichenAnPosition(playerX + 2, playerY) == 'O') || (zeichenAnPosition(playerX + 2, playerY) == '0'))
	     move = 'r';
	   setzeKreuzung(playerX,playerY,move);
	 }
	 else if ((RorL == 'R') || (RorL == 'L')) {
	   moveEval = playerY + 1;
	   south = zeichenAnPosition(playerX,moveEval);
	   moveEval = playerX - 1;
	   west = zeichenAnPosition(moveEval,playerY);
	   moveEval = playerY - 1;
	   north = zeichenAnPosition(playerX,moveEval);
	   moveEval = playerX + 1;
	   east = zeichenAnPosition(moveEval,playerY);
	   K3 turn3 (south,west,north,east,RorL);
	   turn3.permutate();
	   re_entry = turn3.ret_entry();
	   re_exit = turn3.ret_exit();
	   re_block = turn3.ret_block();
	   re_player = turn3.ret_player();
	   setze3erK(playerX,playerY,re_entry,re_exit,re_block,re_player);
	 }
	 else {}
       }
     }
     resetLabyrinth();
   }
   else if (move == 'r') {
     deaths++;
     playerX = startX;
     playerY = startY;
     loadLabyrinth(argv[1]);
     resetLabyrinth();
   }  
   else if (move == 'e') {
     playerX = finishX;
     playerY = finishY;
   }
   else {
     cout << "w,a,s,d fuer Bewegung, r fuer Neuanfang, e fuer Beenden." << endl;
   }

   if (move == 'r') {
     deaths++;
     playerX = startX;
     playerY = startY;
     loadLabyrinth(argv[1]);
     resetLabyrinth();
     cout << "Sie wurden eingemauert und reinkarniert." << endl;
   }  


   //   cout << "playerX= " << playerX << ", playerY =" << playerY << endl;
   cout << "Zug Nr. " << moveCounter << ". " << deaths << " mal gestorben." << endl;

  }while((playerX != finishX) || (playerY != finishY));

 if (move != 'e')
   cout << "Gewonnen! Benoetigte Zuege: " << moveCounter << ". Gestorben: " << deaths << " mal." << endl;
 else
   cout << "Bis zum naechsten Mal!" << endl;
 //beginne Spiel END


return 0;

}


