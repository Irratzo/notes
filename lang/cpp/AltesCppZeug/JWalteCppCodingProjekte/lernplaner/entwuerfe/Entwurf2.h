//Entwurf2
//Kommentare und Testroutinen sind mit //NOTEYY und //TEST_EntwurfX_XX gekennzeichnet
//(und auf cpp und header verteilt)
//Ist ein solcher auf mehrere Stellen verteilt, hängt ein - an
//jeder TESTXX(-) muss ein SUCCESS oder FAIL mit NOTEYY haben
//
//AUFÄUMXX: Dinge, die initialisiert wurden oder sonstwas, und zur gelungenen Schleifen-Iteration an einer noch unbekannten Stelle weiter unten aufgeräumt werden müssen
//jedes AUFRÄUMXX(-) muss ein REMEDIED oder UNREMEDIED haben.
//
//ALTXX: durch Änderungen obsolet gewordene Codeteile


#ifndef ENTWURF1_H
#define ENTUWRF1_H

class SeatRowS;
class SeatRow;

//____________________________________________________________________________
//Funktionen der (äußeren) i-Schleife (Verteilung AUF die freien Sitzreihen)



//void updaterows2(); im Moment als Seatrow-Member-Funktion, siehe RC|F 31




//____________________________________________________________________________
// Gerüst der Klasse SeatRowS
//START

class SeatRowS {

  friend class SeatRow;

 private: //alle Variabeln

  unsigned int rows; //Anzahl der disjunkten freien Sitzreihen
  unsigned int peopleON;
  std::string groupname;

  std::vector<unsigned int> rowstarts; //ihre globalen Startpositionen iB auf motherrow
  std::vector<unsigned int> rowlengths; //ihre Längen

  //Die Verteilungsparameter
  unsigned int peoplebase;
  unsigned int peoplerest;
  unsigned int restdistance;
  unsigned int peoplerestrest;
  unsigned int peopledivrest;
  unsigned int restrestdistance;

  //Sonstige nötige Member
  std::vector<unsigned int> rowforrest, rowforrestrest;
  std::vector<bool> foundrowforrest, foundrowforrestrest;



 public: 

  //Konstruktor
  //  SeatRowS (?);
  //u.a. (?) nötig, weil einige Werte mit += geschrieben und deshalb mit 0 initialisiert werden müssen

  //Dekonstruktor
  //  ~SeatRowS (?);
  //nötig wegen Konstruktor


// alle Methoden von SeatRowS

  void get_group_i(std::vector<std::pair<std::string, unsigned int> > thegroup, unsigned int the_i);
  //NOTE05: habe calc_distribution_i() in diese Funktion einverleibt, weil selbe Argumente und Aufrufzeitpunkt
  //ALT01 START
  //  void calc_distribution_i(std::vector<std::pair<std::string, unsigned int> > thegroup, unsigned int the_i);
  // //Zur Initialisierung der Verteilungsparameter, siehe S.46
  // //Der Iterator, hier noch nur ne Zahl (bleibt hoffensichtlich so), ist einfach zum Zugriff auf die i-te group[i]
  //ALT02 FINISH

  void add_people(unsigned int addp, std::vector<SeatRow>& therow, unsigned int the_k);
//in i-Schleife (Verteilung Leute AUF die freien Sitzreihen) für die Übergabe der Leute an die Objekte verwantwortlich

//TEST02- START
//SUCCESS: folgende drei Funktionen zusätzlich benötigt für add_people

unsigned int get_peoplebase() {  return peoplebase; }

unsigned int get_peopledivrest() {  return peopledivrest; }

unsigned int get_peoplerestrest() {  return peoplerestrest; }

//TEST02- FINISH


 void update_rows_i(std::vector<SeatRow>& therow, std::vector<std::string>& themotherrow);
//Falls in der i-Schleife freie Sitzreihen voll besetzt werden, löscht die Funktion diese aus der Betrachtung und füllt die besetzten Plätze in der mottherrow aus 
//NOTE02: Frage: Übergabe wie, sodass sie geändert werden (by ref, by val -> siehe TEST02



void paste_rests(std::vector<SeatRow>& therow, std::vector<std::string>& themotherrow);
//siehe S.48, verteilt den PeopleRest und Restrest auf die freigebliebenen Sitzreihen. Wäre schön als Funktion (noch schöner als Member-Funktion einer Klasse SeatrowS, muss aber nicht.

//kein Name: ev. zweite Funktion zum Verteilen auf motherrow, siehe RC|F 29.

void cleanup(unsigned int thek2, std::vector<unsigned int>* thefreerowlengthtmps, std::vector<unsigned int>* thefreerowstarttmps, std::vector<SeatRow>* therow);
//unterer Teil S.59 (Teil in i-Schleife nach Beendigung k-Schleife) ev. nicht als Funktion



};

//Gerüst der Klasse SeatRowS
//FINISH
//____________________________________________________________________________




//____________________________________________________________________________
//Geruest der Klasse SeatRow 
//(Funktionen und Variablen der (inneren) k-Schleife(Verteilung IN die freien Sitzreihen))
//START

//SeatRow stellt eine zusammenhängende Teilreihe der motherrow-Sitzreihe dar, zusammen mit einer Teilmenge der Leute aus einer Gruppe. Ihr Zweck ist es, deren Gleichverteilung IN dieser Sitzreihe, und die Ausgabe des Ergebnisses zu vereinfachen.

class SeatRow {

  friend class SeatRowS;

 private: //alle Variablen

  unsigned int length;
  unsigned int peopleIN;

  //Die Verteilungsparameter, u.a. für die Funktion calc_distribution()
  unsigned int peopledistance;
  unsigned int seatsrest;
  unsigned int seatsrestdistance;

  std::vector<bool> seattaken;
  //Länge length, Laufindex l
  //ist true, falls Person dem Sitz zugeteilt wurde - dynamisch wegen späterer Initialisierung mit row.length (?nötig?). Die Initialisierungsfunktion enthält den temporären int-Vektor seatforperson (siehe S. 50,51).

  std::vector<unsigned int>* restseats;
  //Länge rowseatsrest, Laufindex q
  //enthält die Positionen, an denen die anfangs am Ende hängenden freien Reststize in seattaken eingefügt werden.

  //unsigned int inscount;
  //Zähler für die public(?)-Funktion takeseats, siehe RC|O 27,30. Unklar, ob als Member nötig.



 public: 

  //Konstruktor
  //  SeatRowS (?);
  //u.a. (?) nötig, weil einige Werte mit += geschrieben und deshalb mit 0 initialisiert werden müssen

  //Dekonstruktor
  //  ~SeatRowS (?);
  //nötig wegen Konstruktor


//alle Methoden: das Interface

 void calc_distribution_k();
 //berechnet, sobald die Werte für length und peopleIN festgesetzt sind (am Anfang der k-Schleife), die Verteilungsparameter

 bool seat_taken(unsigned int seat){ return seattaken[seat];}
 //gibt den Wert seattaken[seat] zurück (also ob dieser Sitz besetzt ist)

 void take_seats();
 //füllt den Vektor seattaken

 void update_rows_k();
 //Der Teil in der k-Schleife auf S.59 (Zwischenspeichern der durch die Verteilung IN den freien Sitzreihen resultierten Änderungen an selbigen). Ob das als Member-Funktion geht, ist noch unklar, siehe u.a. S.61.

 //TEST02- a) Kon/Destruktor, der peopleIN auf 0 initialisiert und Ausgabefunktion
 //START
 //SUCCESS: call by ref war der springende Punkt, damit add_people seine Berechnung auf den SeatRow-Vektor übergibt. Die Initialisierung auf 0 von peopleIN und resize Vektor hat darauf (siehe test_Entwurf2_02_....out) keinen Einfluss.
 // SeatRow(){peopleIN=0;}
 // ~SeatRow(){}
 // unsigned int get_people() {  return peopleIN;}
 //TEST02 FINISH

};


//Geruest der Klasse SeatRow 
//FINISH
//____________________________________________________________________________





#endif
