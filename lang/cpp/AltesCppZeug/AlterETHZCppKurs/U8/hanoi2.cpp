/***
 * D-ITET Informatik 1, Uebungsserie 8, Aufgabe 3
 *
 * Autor: Johannes Wasmer
 * Datum: 20.11.2011
 *
 * 
 * Plays the game Towers of Hanoi
 */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void show_step(int q, char x, char y) {}
void carry_disc(char x, char y) {
  cout << "Trage oberste Scheibe von " << x << " nach " << y << endl;
}
void hanoi(int n, char a, char b, char c) {
  if (n>1) {
    hanoi(n-1,a,c,b);
    show_step(n-1,a,b);
    carry_disc(a,b);
    hanoi(n-1,c,b,a);
  } else {
    carry_disc(a,b);
  }
}
void test_hanoi(int k) {
  hanoi(k,'A','B','C'); //5 Scheiben
}

int main () {

  char yesno = 'j';
  int dnum = 0;
  
  cout << "Die Tuerme von Hanoi" << endl;

  do {
    cout << "Gebe die Anzahl der Scheiben an (mehr als 9 bringt Unglueck): " ;

    cin >> dnum;

    // vector<vector<char> > viz;
    // for (int i=1; i<=dnum; i++) {
    //   viz.push_back (vector<char> (0, char (i)));
    // }
    //   cout << viz[0][1];
  

    /*
    //Array zur Visualisierung
    string * viz;
    viz = new string [2];
 

    //Array auf Anfangsstellung
    //for (int i = 1; i<=dnum; i++) {
    //  viz[0] += i*10^(dnum-i);
    //}
    for (int i=1;i<=dnum;i++) {
    viz[0][i-1] = i;
  }

  cout << string(viz[0][2])<< endl;
  */

  test_hanoi(dnum);

  cout << "Nochmal (j,n)?";
  cin >> yesno;
  } while (yesno == 'j');

  return 0;

}
