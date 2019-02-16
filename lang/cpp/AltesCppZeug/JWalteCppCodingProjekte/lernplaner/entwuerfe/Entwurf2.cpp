//Entwurf2 -> Entwurf3: siehe Entwurf2 NOTE08, NOTE09, und im Text S 70,71

//Entwurf2
//Kommentare und Testroutinen sind mit //NOTEXX und //TEST_EntwurfX_XX gekennzeichnet
//(und auf cpp und header verteilt)
//Ist ein solcher auf mehrere Stellen verteilt, hängt ein - an
//jeder TESTXX(-) muss ein SUCCESS oder FAIL mit NOTEYY haben
//
//AUFÄUMXX: Dinge, die initialisiert wurden oder sonstwas, und zur gelungenen Schleifen-Iteration an einer noch unbekannten Stelle weiter unten aufgeräumt werden müssen
//jedes AUFRÄUMXX(-) muss ein REMEDIED oder UNREMEDIED haben.
//
//ALTXX: durch Änderungen obsolet gewordene Codeteile

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <climits> //für UINT_MAX, siehe unten

#include "Entwurf2.h"

using namespace std;


//____________________________________________________________
//Nötige Deklarationen für Eingabe und Vorbereitung
//START

  typedef pair<string,unsigned int> onegroupdef;
  typedef vector<onegroupdef> groupdef;
  typedef vector <string> motherrowdef;

//nötig für die Sortierung des Eingabe-Pair-Vektors nach der zweiten Spalte
  bool sort_pred(const onegroupdef& elementlinks, const onegroupdef& elementrechts) {
    return elementlinks.second < elementrechts.second;
  }

//Nötige Deklarationen für Eingabe und Vorbereitung
//FINISH
//____________________________________________________________




//____________________________________________________________
//SeatRowS Deklarationen START

//Konstruktor
//SeatRowS::SeatRowS(?)
//{?}

//Dekunstruktor
//SeatRowS::~SeatRowS()
//{?}

void SeatRowS::get_group_i(groupdef thegroup, unsigned int the_i){
  //NOTE05: habe calc_distribution_i() dieser Funktion einverleibt, siehe Header

  groupname = thegroup[the_i].first;
  peopleON = thegroup[the_i].second;

  unsigned int plast = thegroup[the_i-1].second;

  peoplebase = peopleON / plast;

  peoplerest = peopleON % plast;

  restdistance = ceil( (double)plast / peoplerest );

  peoplerestrest = peopleON % (plast / restdistance);

  peopledivrest = peoplerest - peoplerestrest;

  if (peoplerestrest == 0)
    restrestdistance = 0;
else
  restrestdistance = ceil( (double)plast / peoplerestrest);

  //TEST01- START: Funktioniert calc_distributionON()?
  //SUCCESS
  // cout << peopleON << ' ' << plast << endl;
  // cout << peoplebase << endl << peoplerest << endl << restdistance << endl << peoplerestrest << endl << peopledivrest << endl << restrestdistance << endl;
  //TEST 01- FINISH


}

void SeatRowS::add_people (unsigned int addp, vector<SeatRow>& therow, unsigned int the_k) {
//Verteilung der Leute AUF die freien Sitzreihen, dh Übergabe an die row[k]-Objekte
//Unklar, ob das eine SeatRowS-Funktion oder eine SeatRow-Funktion sein soll

  therow[the_k].peopleIN += addp;

  //NOTE01: Hm, das funktioniert jetzt ohne *. Aber wenn row[k] dynamisch ist, also mit new initialisiert, wird das schätze ich zu Problemen führen.

  //TEST02-: Funzt add_people, sodass row[k] resized werden kann? 
  //START
  //SUCCESS (mit ZusatzFunktion get_peoplebase())
  //    cout << therow[the_k].peopleIN << endl;
  //TEST02- FINISH

}

void SeatRowS::update_rows_i(std::vector<SeatRow>& therow, std::vector<std::string>& themotherrow) {
  //Übernommen von S.47,54
      //Wird eine der Sitzreihen durch das Einfügen von Leuten schon komplett besetzt, dann muss sie nicht weiter betrachtet werden. Vor ihrem Löschen werden in der motherrow die entsprechenden Sitze mit den Leuten der in der i-Schleife gerade betrachteten Gruppe gefüllt.

  unsigned int k = 0;

  //von S.47 für Array verschieben; nicht nötig mit vector.erase
  //NOTE07: DOCH, brauche es: erase verkleinert den Vektor, dh wenn ich bei 30 bin und 30 rauslösche, ist die nächste zu betrachtende Position nicht 31, sondern wieder 30
  //Vielleicht sollt ichs mit ner while-Schleife statt for probieren
  unsigned int k2 = 0;
  //das ist auch nötig, sonst wirds in jeder Iteration deklariert, segfault oder

  do{

    //NOTE09-: wenn ich die If(){}-Klammer in updaterows als eigentliche updaterows-Funktion definiere, ists einfacher -> neuer Entwurf.
    if(therow[k].peopleIN == rowlengths[k]) {

      for (k2 = 0; k2 < therow[k].peopleIN; k2++)
	themotherrow[ rowstarts[k]+k2 ] = groupname;

      therow.erase(therow.begin()+k);
      rowstarts.erase(rowstarts.begin()+k);
      rowlengths.erase(rowlengths.begin()+k);

      k--;
      rows--;
    }

    k++;
  }while(k < rows);

  //Beispiel: rows=10; k=5, rows=10, if(true) -> k=5, rows=9; k=5, rows=9, if(false) -> k=6, rows=9; k=6, rows=9, if(false) -> k=7, rows=9, ...

  //NOTE07-: Die vorschleife ist damit veraltet
  //ALT02 START
  // for (k=0; k < rows; k++) {
  //   if (therow[k].peopleIN == rowlengths[k]) {
  //     //NOTE03: Kondition angepasst: die Verteilung AUF die Sitzreihen wird nicht wie im Text in peoplebase gespeichert, sondern in den row-Objekten; siehe auch Kommentar S.68


  //     for (unsigned int k2 = 0; k2 < therow[k].peopleIN; k2++)
  // 	themotherrow[ rowstarts[k]+k2 ] = groupname;

  //     therow.erase(therow.begin()+k);
  //     rowstarts.erase(rowstarts.begin()+k);
  //     rowlengths.erase(rowlengths.begin()+k);
  //     //NOTE04: cplusplus.com schreibt hier myvector.begin()+5 "erases the 6th element" - da k bei 0 anfängt, ist das äquivalent

  //   }
  // }
  //ALT02 FINISH
 
}


void SeatRowS::paste_rests(std::vector<SeatRow>& therow, std::vector<std::string>& themotherrow) {
//übernommen von S.48

//Zuerst für divrest, also der Teil von (rows mod peopleON), der restlos auf die Sitzreihen aufteilbar ist (restrest ist der Rest davon)

//1.) Initialisiere Vektoren, die aussagen, zu welcher Sitzreihe laut Verteilungsparametern zusätzliche Leute (aus divrest, restrest) hinzukommen sollen.
  unsigned int v;

  for (v=0; v < peopledivrest; v++){
    rowforrest.push_back(v * restdistance);
    foundrowforrest.push_back(false);
  }

  //Diese Initialisierung der nötigen Vektoren (siehe S.48) nimmt an, dass diese SeatRowS-Member beim Aufruf der Funktion als leere Vektoren initialisiert sind.
  //AUFRÄUM01: Entsprechend müssen sie am Ende (weil das SeatRowS-Objekt nach jetzigem Kenntnisstand die i-Schleifen-Iterationen ja überlebt) gecleaned, also wieder leer werden.
  //UNREMEDIED

  //2.) Wenn eine dieser Reihen tatsächlich existiert (sie könnte schon verschwunden sein, siehe S.48), füge die hinzugekommenen Personen (aus divrest, restrest separat, da es sich ja um unterschiedliche Reihen handelt) hinzu - und zwar einen nach dem anderen und prüfe jedesmal, ob die betreffende Reihe dadurch schon voll ist und nicht mehr betrachtet werden darf (update füllt in diesem Fall die Reihe in motherrow aus)

  unsigned int k = 0;


  //jede verschwundene Reihe hat einen niedrigeren Index als die nächtbetrachtete. Das heisst, alle nachfolgenden Vektorglieder rücken eins nach vorne, k muss verharren, rows abnehmen.
  //Für rowforrest, foundrowforrest bedeutet es: alle rowforrests-Mitglieder, die größer sind als k, müssen um 1 abnehmen (ich glaube, ich brauche den Boolvektor gar nicht, aber egal jetzt).

  do{

      if (rowstarts[k] == rowforrest[v]) {
	add_people(1,therow,k);
	foundrowforrest[v] = true;
      }



k++
  }while(k < rows);


  for (k=0; k < rows; k++) {
    for (v=0; v < peopledivrest; v++) {
      if (rowstarts[k] == rowforrest[v]) {

	add_people(1,therow,k);
	foundrowforrest[v] = true;

      }
    }

    //ALT03 START
    //    update_rows_i(therow,themotherrow);
    //ALT03 FINISH
    //NOTE08-: update_rows_i tuts es nicht für paste_rests. Im Gegensatz zu oben muss hier nur eine row überprüft werden. Es macht auch wenig Sinn, einen Überprüfungsbereich anzugeben. 
    //NOTE08-:Ich benenne stattdessen update_rows_i um in paste_base und füge dort am Anfang noch das Anfügen aller peoplebase in alle row[k].peopleIN dazu. 
    //NOTE08-: Und ich mache das Update hier in paste_rests separat.

  }


  //3.) Es kann Reihen geben, auf die zusätzliche Leute verteilt werden sollen, die aber schon voll besetzt und durch updaterows aus der Betrachtung verschwunden sind. Diese wurden im Schritt 2.) ermittelt und in den bool-Vektoren aus Schritt 1.) gespeichert (false für "in Schritt 2.) nicht verwendet"). Für diese wird nun die nächstliegende freie Reihe gesucht (separat für divrest und restrest), und die Leute dort, einen nach dem anderen eingesetzt, ebenfalls mit der Nachprüfung, ob die Reihe dadurch gefüllt wurde.

unsigned int nearestfreerowdistance = UINT_MAX;
unsigned int nearestfreerow = 0;

 for (v=0; v < peopledivrest; v++) {
   if (!foundrowforrest[v]) {

     for (k=0; k < rows; k++) {
       if ( abs(rowstarts[k]-rowforrest[v]) < nearestfreerowdistance ) {

	 nearestfreerowdistance = abs(rowstarts[k]-rowforrest[v]);
       nearestfreerow = k;
       }
     }

     add_people(1,therow,nearestfreerow);
     update_rows_i(therow,themotherrow);

   }
 }



 //analog mit restrest

 //1.) finde die für die Verteilung vorgesehene Reihenindizes
  for (v=0; v < peoplerestrest; v++){
    rowforrestrest.push_back(v * restrestdistance);
    foundrowforrestrest.push_back(false);
  }

  //2.) wenn sie existieren, fülle ein

  for (k=0; k < rows; k++) {
    for (v=0; v < peoplerestrest; v++) {
      if (rowstarts[k] == rowforrestrest[v]) {

	add_people(1,therow,k);
	foundrowforrestrest[v] = true;

      }
    }
    update_rows_i(therow,themotherrow);
  }

  //3.) wenn nicht, finde die nächstelegenen

 nearestfreerowdistance = UINT_MAX;
nearestfreerow = 0;

 for (v=0; v < peoplerestrest; v++) {
   if (!foundrowforrestrest[v]) {

     for (k=0; k < rows; k++) {
       if ( abs(rowstarts[k]-rowforrestrest[v]) < nearestfreerowdistance ) {

	 nearestfreerowdistance = abs(rowstarts[k]-rowforrestrest[v]);
       nearestfreerow = k;
       }
     }

     add_people(1,therow,nearestfreerow);
     update_rows_i(therow,themotherrow);

   }
 }


 //NOTE06: Das geht doch gar nicht: updaterows kann den Laufindex der Reihen ändern. Dann stimmt die Position der noch einzufügenden Reste nicht mehr. Wir brauchen einen Rückgabewert von update_rows_i (bool oder int), sodass wir wissen, falls die aktuelle Reihe verschwand. Wenn sie kleiner ist als die als nächstbetrachtete Reihe, muss vom Laufindex der Iteration eins abgezogen werden, sonst nicht.
 //NOTE06-: Ich hatte das doch schon an einer anderen Stelle im Text, wo ich es mit einer Variable inscount gelöst hatte (oder war es was anderes?)
 //NOTE06-: Habe das auf S.69,70 aufgepfriemelt, siehe auch weiter bei NOTE07
}


void SeatRowS::cleanup(unsigned int thek2, std::vector<unsigned int>* thefreerowlengthtmps, std::vector<unsigned int>* thefreerowstarttmps, std::vector<SeatRow>* therow) {}



//SeatRowS Deklarationen FINISH
//____________________________________________________________



//____________________________________________________________
//SeatRow Deklarationen START

//Konstruktor
//SeatRow::SeatRow(?)
//{?}

//Dekunstruktor
//SeatRow::~SeatRow()
//{?}

void SeatRow::calc_distribution_k() {

  peopledistance = length / peopleIN;

  seatsrest = length % peopleIN;

  seatsrestdistance = peopleIN / seatsrest;

}

void SeatRow::take_seats() {

}


//SeatRow Deklarationen FINISH
//____________________________________________________________




int main () {


//____________________________________________________________
  //Einlesen der Eingabe, Vorbereitung auf Betreten der i-Schleife
  //START

  unsigned int m;
  //Die Anzahl Gruppen, Laufindex i
  unsigned int n = 0;
  //Die Summe der Leute aller Gruppen, und Länge des Ausgabevektors motherrow, Laufindex j

  cin >> m;

  groupdef group;
  onegroupdef onegroup;

  for (unsigned int i=0; i<m; i++) {

    cin >> onegroup.first;
    cin >> onegroup.second;
    n+=onegroup.second;

    group.push_back(onegroup);
    
  }

  motherrowdef motherrow(n);
  //Der Vektor für die Endausgabe.

  sort(group.begin(), group.end(), sort_pred);
  //Aufsteigendes Sortieren der Gruppen nach zweiter Spalte, realisiert mit predicate wie von bit.ly/OTF8p1


  //Einlesen der Eingabe, Vorbereitung
  //FINISH
//____________________________________________________________

  //TEST01- START
  //SUCCESS
  //     SeatRowS test;
  //     test.calc_distributionON(group,2);
  //TEST01 FINISH

  //TEST02- START (braucht TEST01-)
  //SUCCESS
  //      vector<SeatRow> testes(3);
  //     test.add_people(test.get_peoplebase(),testes,1);
  //     cout << testes[1].get_people() << endl;
  //TEST02- a)
     //SUCCESS (unabhängig von resize) mit add_people(vektor Seatrow&) call by ref
     //      testes.pop_back();
     //      test.add_people(3,testes,1);
     // 	  for (int k=0; k<3; k++)
     // cout << testes[k].get_people() << ' ';
     // cout << endl;
  //TEST02 FINISH


//____________________________________________________________
//i-Schleife (Verteilung der Leute AUF die Sitzreihen)
//vor Betreten der k-Schleife
//START



//i-Schleife vor Betreten der k-Schleife
//FINISH
//____________________________________________________________




//____________________________________________________________
//k-Schleife (Verteilung der Leute IN den Sitzreihen)
//START



//k-Schleife FINISH
//____________________________________________________________




//____________________________________________________________
//i-Schleife 
//Aufräumen, Vorbereiten der Ausgabe für die nächste i-Schleifen-Iteration
//START


//i-Schleife nach k-Schleife FINISH
//____________________________________________________________




//____________________________________________________________
//Aufräumen nach Beendigung der i-Schleife
//START


//Aufräumen nach Beendigung der i-Schleife
//FINISH
//____________________________________________________________


}
