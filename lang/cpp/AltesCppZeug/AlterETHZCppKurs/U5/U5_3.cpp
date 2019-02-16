/***
 * D-ITET Informatik 1, Uebungsserie 5, Aufgabe 3
 *
 * Koautor: Johannes Wasmer
 * Datum: 01.11.2011
 *
 * Dieses Programm liest aus einer Datei einen Text ein und
 * gibt aus, wieviele Vokale, Konsonanten, Ziffern, Leerzeichen
 * und Sonderzeichen er enthält.
 */
 
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Eine Enumeration der Zeichenarten. Jeder Zeichenart ist ein int Wert zugeordnet.
//Variablen koennen diese Enumeration als Datentyp benutzen. 
//So werden Ausdruecke wie z.B. zeichenart zeichen1 = ziffer; moeglich
enum zeichenart {vokal = 0, konsonant = 1, ziffer = 2, leerzeichen = 3, sonderzeichen = 4};

//Diese Datenstruktur ist wegen der Funktionen global definiert
struct satz {
  string dersatz;
  int vokale;
  int konsonanten;
  int ziffern;
  int leerzeichen;
  int sonderzeichen;
};


//Funktion ordnet char anhand ASCII-Tabelle dem entsp. Enum.-Typ zu
zeichenart zeichenart_von_character(char c)
{
  zeichenart temp;

  if (c == ' ') 
    temp = leerzeichen;
  //\366 ö, \374 ü, \311 E a.aigu, \351 e a.aigu
  else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == '\366' || c == '\374' || c == '\311' || c == '\351')
    temp = vokal;
  else if (c > 47 && c < 58)
    temp = ziffer;
  else if (c < 48 || (c > 57 && c <65) || c > 122)
    temp = sonderzeichen;
  else
    temp = konsonant;

  return temp;
}


//Funktion geht das Argument durch und zählt die Zeichenarten
satz satz_aus_string(string einSatz) 
{

  int length = einSatz.length();
  char tempc;
  zeichenart tempz;
  satz tempsatz;
  tempsatz.dersatz = einSatz;
  tempsatz.vokale = 0;
  tempsatz.konsonanten = 0;
  tempsatz.ziffern = 0;
  tempsatz.leerzeichen = 0;
  tempsatz.sonderzeichen = 0;

  for (int i=0; i<length; i++) {
    tempc = einSatz.at(i);
    tempz = zeichenart_von_character(tempc);
    switch (tempz)
      {
      case vokal:
	tempsatz.vokale++;
	break;
      case konsonant:
	tempsatz.konsonanten++;
	break;
      case ziffer:
	tempsatz.ziffern++;
	break;
      case leerzeichen:
	tempsatz.leerzeichen++;
	break;
      case sonderzeichen:
	tempsatz.sonderzeichen++;
	break;
      }
  }

  return tempsatz;

}

//Der text der .txt-Datei wird als string mit dem namen text eingelesen.
int main ()
{
  string text;
  string temptext;
  ifstream infile;
  int input = 23;

  infile.open ("ETH.txt");
  if (infile && !infile.eof()){
    //nach dem Ende der Schleife liest getline am nächsten Punkt weiter
    //der Punkt wird als Delimiter-Option dabei nicht eingelesen
    for (int i=0; i<22; i++) {
      getline(infile, text, '.');
      temptext.append(text);
      temptext.append(".");
    }
    infile.close();
  }
		  
  double size = temptext.length();
  satz sX = satz_aus_string(temptext); //zählt die Zeichenarten

  cout << "Die Datei ETH.txt enthaelt " << endl;
  cout << size << " Zeichen.\n Diese sind zu:\n";
  cout.precision(2);
  cout << sX.vokale * 100 / size << " % Vokale,\n";
  cout << sX.konsonanten * 100 / size << " % Konsonanten,\n";
  cout << sX.ziffern * 100 / size<< " % Ziffern,\n";
  cout << sX.leerzeichen * 100 / size << " % Leerzeichen,\n";
  cout << sX.sonderzeichen * 100 / size << " % Sonderzeichen,\n";

  while (input != 0) {

    cout << "Um die Statistik fuer einen einzelnen Satz zu sehen, geben Sie bitte die Satznummer ein (1-22), ansonsten 0: ";
    cin >> input;
    if (input == 0) break;

    infile.open ("ETH.txt");
    if (infile && !infile.eof()){
      for (int i=0; i<22; i++) {

	getline(infile, text, '.');
	if (i==input-1) { //wählt den gewünschten Satz
	  temptext = text;
	  temptext.append(".");
	}
      }
      infile.close();
    }

    size = temptext.length();
    sX = satz_aus_string(temptext);
    cout << "Der Satz lautet:\n" << sX.dersatz << endl;
    cout << "Er enthaelt:\n";
    cout.precision(5);
    cout << size << " Zeichen.\n Diese sind zu:\n";
    cout.precision(2);
    cout << sX.vokale * 100 / size << " % Vokale,\n";
    cout << sX.konsonanten * 100 / size << " % Konsonanten,\n";
    cout << sX.ziffern * 100 / size<< " % Ziffern,\n";
    cout << sX.leerzeichen * 100 / size << " % Leerzeichen,\n";
    cout << sX.sonderzeichen * 100 / size << " % Sonderzeichen,\n";

  }

  cout << "Ciao!\n";

  return 0;

}
