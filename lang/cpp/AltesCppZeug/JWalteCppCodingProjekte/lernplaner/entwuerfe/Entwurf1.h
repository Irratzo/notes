#ifndef ENTWURF1_H
#define ENTUWRF1_H


//Geruest der Klasse Seatingrow (Funktionen und Variablen der (inneren) k-Schleife(Verteilung IN die freien Sitzreihen))
//Seatingrow stellt eine zusammenhängende Teilreihe der motherrow-Sitzreihe dar, zusammen mit einer Teilmenge der Leute aus einer Gruppe. Ihr Zweck ist es, deren Gleichverteilung IN dieser Sitzreihe, und die Ausgabe des Ergebnisses zu vereinfachen.

class Seatingrow {
 private: //alle Variablen
  int length;
  int people;

  //Die Verteilungsparameter, u.a. für die Funktion calc_distribution()
  int peopledistance;
  int seatsrest;
  int seatsrestdistance;

  std::vector<bool>* seattaken;
  //Länge length, Laufindex l
  //ist true, falls Person dem Sitz zugeteilt wurde - dynamisch wegen späterer Initialisierung mit row.length (?nötig?). Die Initialisierungsfunktion enthält den temporären int-Vektor seatforperson (siehe S. 50,51).

  std::vector<unsigned int>* restseats;
  //Länge rowseatsrest, Laufindex q
  //enthält die Positionen, an denen die anfangs am Ende hängenden freien Reststize in seattaken eingefügt werden.

  //unsigned int inscount;
  //Zähler für die public(?)-Funktion takeseats, siehe RC|O 27,30. Unklar, ob als Member nötig.

 public: //alle Methoden: das Interface

void add_people(int addp);
//in i-Schleife (Verteilung Leute AUF die freien Sitzreihen) für die Übergabe der Leute an die Objekte verwantwortlich

 void calc_distribution();
 //berechnet, sobald die Werte für length und people festgesetzt sind (am Anfang der k-Schleife), die Verteilungsparameter

 void takeseats();
 //füllt den Vektor seattaken

 bool is_seattaken(unsigned int seat);
 //gibt den Wert seattaken[seat] zurück (also ob dieser Sitz besetzt ist)

 void updaterows2();
 //Der Teil in der k-Schleife auf S.59 (Zwischenspeichern der durch die Verteilung IN den freien Sitzreihen resultierten Änderungen an selbigen). Ob das als Member-Funktion geht, ist noch unklar, siehe u.a. S.61.

};



//Funktionen der (äußeren) i-Schleife (Verteilung AUF die freien Sitzreihen)

void updaterows(unsigned int &thefreerows, unsigned int &thepeople, std::vector<int>* thefreerowlengths, std::vector<int>* thefreerowstarts, std::vector<Seatingrow>* therows, std::vector<std::string>* themotherrow, std::vector<std::pair<std::string, int> > thegroup);
//Falls in der i-Schleife freie Sitzreihen voll besetzt werden, löscht die Funktion diese aus der Betrachtung und füllt die besetzten Plätze in der mottherrow aus (wenns ne Member-Funktion einer Klasse SeatrowS (Plural!) wäre, müsste ich mich mit der Parameter-Übergabe nicht herumschlagen...)
//Frage: Übergabe wie, sodass sie geändert werden (by ref, by ?)

void pasterests(unsigned int thepeopledivrest, unsigned int therestdistance, unsigned int therestrestdistance, unsigned int &thefreefrows, std::vector<int>* thefreerowlengths, std::vector<int>* thefreerowstarts, std::vector<Seatingrow>* therows, std::vector<std::string>* themotherrow, std::vector<std::pair<std::string, int> > thegroup);
//siehe S.48, verteilt den PeopleRest und Restrest auf die freigebliebenen Sitzreihen. Wäre schön als Funktion (noch schöner als Member-Funktion einer Klasse SeatrowS, muss aber nicht.

//kein Name: ev. zweite Funktion zum Verteilen auf motherrow, siehe RC|F 29.

//void updaterows2(); im Moment als Seatrow-Member-Funktion, siehe RC|F 31

void cleanup(unsigned int thek2, unsigned int &thefreefrows, std::vector<int>* thefreerowlengths, std::vector<int>* thefreerowstarts, std::vector<int>* thefreerowlengthtmps, std::vector<int>* thefreerowstarttmps, std::vector<Seatingrow>* therows);
//unterer Teil S.59 (Teil in i-Schleife nach Beendigung k-Schleife) ev. nicht als Funktion



#endif
