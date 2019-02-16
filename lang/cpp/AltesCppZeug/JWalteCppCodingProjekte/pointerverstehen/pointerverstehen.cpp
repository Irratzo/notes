 
#include <iostream>


using namespace std;


int main () {

  int *p1 = new int;
  int *p2 = new int;
  int *const p1backup = new int;
  int *const p2backup = new int;
  p1 = p1backup;
  p2 = p2backup;

  int x1 = 1;
  int x2 = 2;

  cout << "Pointer verstehen: Mit 2 Pointern und zwei Variablen alle moeglichen Zuweisungen durchgehen." << endl << "Modell: " << endl;
  cout << "_____________________________________________________________" << endl;
  cout << "||Nummer Ebene:||     III     |       II       |     I     ||" << endl;
  cout << "||Speicherebene|| Ptr-Adressen|  Adressebene   | Wertebene ||" << endl;
  cout << "||             ||             | /Ptr-Wertebene |           ||" << endl;
  cout << "||_____________||_____________|________________|___________||" << endl;
  cout << "||Pointer:     || {    &p     |        p       |    *p   } ||" << endl;
  cout << "||Variable:    ||             | {     &x       |     x   } ||" << endl;
  cout << "||_____________||_____________|________________|___________||" << endl;
  cout << "(Anmerkung: I ist vom Typ 'type', II/III sind vom Typ ''type' adress type')" << endl;
  cout << endl;

  cout << "_____________________________________________________________" << endl;
  cout << "1.) ANFANGSWERTE NACH INITIALISIERUNG" << endl;
  cout << "_____________________________________________________________________" << endl;
  cout << "||Zuweisungen: ||     III        |       II       |     I          ||" << endl;
  cout << "||p1           ||     &p1        |      p1 = -    |  *p1= -        ||" << endl;
  cout << "||p2           ||     &p2        |      p2 = -    |  *p2= -        ||" << endl;
  cout << "||x1           ||                |      &x1       |   x1= 1;       ||" << endl;
  cout << "||x2           ||                |      &x2       |   x2= 2;       ||" << endl;
  cout << "||_____________||________________|________________|________________||" << endl;
  cout << "||p1:          || " << &p1 << " | ";
  cout <<                                         p1 << "       | ";
  cout <<                                                    *p1 << "              ||" << endl;
  cout << "||p2:          || " << &p2 << " | ";
  cout <<                                         p2 << "       | ";
  cout <<                                                    *p2 << "              ||" << endl;
  cout << "||_____________||________________|________________|________________||" << endl;
  cout << "||x1:          ||                | " << &x1 << " | ";
  cout <<                                                     x1 << "              ||" << endl;
  cout << "||x2:          ||                | " << &x2 << " | ";
  cout <<                                                     x2 << "              ||" << endl;
  cout << "||_____________||________________|________________|________________||" << endl;
  cout << endl;


  p1 = p2;
  p2 = &x1;
  x1 = x2;
  x2 = *p1;


  cout << "_____________________________________________________________________" << endl;
  cout << "2.) ZUWEISUNGEN IN DERSELBEN EBENE" << endl;
  cout << "_____________________________________________________________________" << endl;
  cout << "||Zuweisungen: ||     III        |       II       |     I          ||" << endl;
  cout << "||p1           ||     &p1        |      p1 = p2   |  *p1= -        ||" << endl;
  cout << "||p2           ||     &p2        |      p2 = &x1  |  *p2= -        ||" << endl;
  cout << "||x1           ||                |      &x1       |   x1= x2;      ||" << endl;
  cout << "||x2           ||                |      &x2       |   x2= *p1;     ||" << endl;
  cout << "||_____________||________________|________________|________________||" << endl;
  cout << "||p1:          || " << &p1 << " | ";
  cout <<                                         p1 << "       | ";
  cout <<                                                    *p1 << "              ||" << endl;
  cout << "||p2:          || " << &p2 << " | ";
  cout <<                                         p2 << " | ";
  cout <<                                                    *p2 << "              ||" << endl;
  cout << "||_____________||________________|________________|________________||" << endl;
  cout << "||x1:          ||                | " << &x1 << " | ";
  cout <<                                                     x1 << "              ||" << endl;
  cout << "||x2:          ||                | " << &x2 << " | ";
  cout <<                                                     x2 << "              ||" << endl;
  cout << "||_____________||________________|________________|________________||" << endl;


  //Varibale reset
  p1 = p1backup;
  p2 = p2backup;
  x1 = 1;
  x2 = 2;

  //    p1 = &p2; //error:          cannot convert ‘int**’ to ‘int*’  in assignment
  //    p2 = x1;  //error: invalid conversion from ‘int’   to ‘int*’  [-fpermissive]
  //    x1 = &x2; //error: invalid conversion from ‘int*’  to ‘int’   [-fpermissive]
  //    x2 = &p1; //error: invalid conversion from ‘int**’ to ‘int’   [-fpermissive]
  //    p1 = *p2; //error: invalid conversion from ‘int’   to ‘int*’  [-fpermissive]
  //    x1 = p1;  //error: invalid conversion from ‘int*’  to ‘int’   [-fpermissive]

  p1[0] = 5;
  p1[2] = 42;
  cout << endl << endl << *p1 << endl << p1[1] << endl << p1[2] << endl << endl;
  cout << endl << *&p1[0] << endl << endl;
  cout << endl << *(p1+2) << endl << endl;

  //p1++; p1++;
  //cout << *p1 << endl;

  p1 += 2; cout << *p1 << endl;

  cout << "_____________________________________________________________________" << endl;
  cout << "2.) ZUWEISUNGEN VON HOEHERER EBENE" << endl;
  cout << "    -- Variabeln jeweils auf Anfangswerte zurueckgesetzt -- "<< endl;
  cout << "_____________________________________________________________________" << endl;
  cout << "p1 = &p2; //error:          cannot convert ‘int**’ to ‘int*’  in assignment" << endl;
  cout << "x1 = &x2; //error: invalid conversion from ‘int*’  to ‘int’   [-fpermissive]" << endl;
  cout << "x2 = &p1; //error: invalid conversion from ‘int**’ to ‘int’   [-fpermissive]" << endl;
  cout << "x1 = p1; //error: invalid conversion from ‘int*’   to ‘int’   [-fpermissive]" << endl;

  cout << "_____________________________________________________________________" << endl;
  cout << "3.) ZUWEISUNGEN VON TIEFERER EBENE" << endl;
  cout << "    -- Variabeln jeweils auf Anfangswerte zurueckgesetzt -- "<< endl;
  cout << "_____________________________________________________________________" << endl;
  cout << "p1 = *p2; //error: invalid conversion from ‘int’   to ‘int*’  [-fpermissive]" << endl;
  cout << "p2 = x1;  //error: invalid conversion from ‘int’   to ‘int*’  [-fpermissive]" << endl;
 

  return 0;

}
