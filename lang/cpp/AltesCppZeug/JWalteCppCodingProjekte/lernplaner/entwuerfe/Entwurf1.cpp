w#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <iterator>
#include <algorithm>

#include "Entwurf1.h"

using namespace std;

  typedef pair<string,int> onegroupdef;
  typedef vector<onegroupdef> groupdef;
  typedef vector <string> motherrowdef;

//nötig für die Sortierung des Eingabe-Pair-Vektors nach der zweiten Spalte
  bool sort_pred(const onegroupdef& elementlinks, const onegroupdef& elementrechts) {
    return elementlinks.second < elementrechts.second;
  }


int main () {

  //Einlesen der Eingabe
  int m;
  //Die Anzahl Gruppen, Laufindex i
  int n = 0;
  //Die Summe der Leute aller Gruppen, und Länge des Ausgabevektors motherrow, Laufindex j

  cin >> m;

  groupdef group;
  onegroupdef onegroup;

  for (int i=0; i<m; i++) {

    cin >> onegroup.first;
    cin >> onegroup.second;
    n+=onegroup.second;

    group.push_back(onegroup);
    
  }

  motherrowdef motherrow(n);
  //Der Vektor für die Endausgabe.

  sort(group.begin(), group.end(), sort_pred);
  //Aufsteigendes Sortieren der Gruppen nach zweiter Spalte, realisiert mit predicate wie von bit.ly/OTF8p1





}
