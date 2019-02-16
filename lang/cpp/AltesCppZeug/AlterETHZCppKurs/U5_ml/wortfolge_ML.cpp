/***
 * D-ITET Informatik 1, Uebungsserie 5, Aufgabe 3
 *
 * Dieses Programm liest vom Benutzer einen Satz ein und
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

//Ein struct fuer den Satz mit der Wortfolge als String,
//und jeweils integer welche die Anzahl Vokale, Konsonanten,
//Ziffern, Leerzeichen und Sonderzeichen enthalten.
struct satz
{
	string wortfolge;
	int vokale;
	int konsonanten;
	int ziffern;
	int leerzeichen;
	int sonderzeichen;
};

//Funktion, die zu implementieren ist
zeichenart zeichenart_von_character(char c)
{
	zeichenart resultat;
	string vokale = "aeiouAEIOU";
	string konsonanten = "bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ";
	string zahlen = "1234567890";
	if (vokale.find(c) != string::npos){
		resultat = vokal;
	}
	else if (konsonanten.find(c) != string::npos){
		 resultat = konsonant;
	}
	else if (zahlen.find(c) != string::npos){
		 resultat = ziffer;
	}
	else if (c == ' '){
		resultat = leerzeichen;
	}
	else{
		resultat = sonderzeichen;
	}
	
	return resultat;
}

//Funktion, die zu implementieren ist
satz satz_aus_string(string einSatz) 
{
	satz resultat = {einSatz, 0, 0, 0, 0, 0};
	
	for (unsigned int i = 0; i < einSatz.length(); ++i){
		char aktuellerChar = einSatz[i];
		zeichenart aktuellesZeichen = zeichenart_von_character(aktuellerChar);
		switch(aktuellesZeichen){
			case vokal: {
				resultat.vokale += 1;
				break;
			}
			case konsonant: {
				resultat.konsonanten += 1;
				break;
			}
			case ziffer: {
				resultat.ziffern += 1;
				break;
			}
			case leerzeichen: {
				resultat.leerzeichen += 1;
				break;
			}
			case sonderzeichen: {
				resultat.sonderzeichen += 1;
				break;
			}
			default: break;
		}
	}
	
	return resultat;
}

//Der text der .txt-Datei wird als string mit dem namen text eingelesen.
int main ()
{
	string text;
	ifstream infile;
	infile.open ("ETH.txt");
	if (infile && !infile.eof()){
		getline(infile, text);
		infile.close();
	}
    
    int anzahlSaetze = 0;
	satz saetze[22];
    
	string aktuellerSatz = "";
	for (unsigned int i = 0; i < text.size(); ++i){
		if (text[i] != '.' && text[i] != '?' && text[i] != '!')
			aktuellerSatz += text[i];
		else{
			//Ein satz-Strukt erzeugen
			//mit Hilfe der Funktion satz_aus_string
			aktuellerSatz += text[i];
			satz meinSatz = satz_aus_string(aktuellerSatz);
			saetze[anzahlSaetze++] = meinSatz;
			aktuellerSatz = "";
		}
	}

	double anzahlZeichen = 0.0;
	double anzahlVokale = 0.0;
	double anzahlKonsonanten = 0.0;
	double anzahlZiffern = 0.0;
	double anzahlLeerzeichen = 0.0;
	double anzahlSonderzeichen = 0.0;
	for (unsigned int i = 0; i < 22; ++i){
		satz s = saetze[i];
		anzahlZeichen += s.vokale + s.konsonanten + s.ziffern + s.leerzeichen + s.sonderzeichen;
		anzahlVokale += s.vokale;
		anzahlKonsonanten += s.konsonanten;
		anzahlZiffern += s.ziffern;
		anzahlLeerzeichen += s.leerzeichen;
		anzahlSonderzeichen += s.sonderzeichen;
	}
    
	// Fuer den Text die Anzahl Zeichen und die Prozentzahl Vokale, Konsonanten, 
	// Ziffern, Leerzeichen und Sonderzeichen ausgeben.

	cout << "Die Datei ETH.txt enthaelt\n";
	cout << anzahlZeichen;
	cout << " Zeichen.\nDiese sind zu:\n";
	printf("%.1f", anzahlVokale / anzahlZeichen * 100.0);
	cout << "% Vokale,\n";
	printf("%.1f", anzahlKonsonanten / anzahlZeichen * 100.0);
	cout << "% Konsonanten,\n";
	printf("%.1f", anzahlZiffern / anzahlZeichen * 100.0);
	cout << "% Ziffern,\n";
	printf("%.1f", anzahlLeerzeichen / anzahlZeichen * 100.0);
	cout << "% Leerzeichen,\n";
	printf("%.1f", anzahlSonderzeichen / anzahlZeichen * 100.0);
	cout << "% Sonderzeichen.\n";
	
	int satzNummer = 0;
	cout << "\nUm die Statistik fuer einen einzelnen Satz zu sehen, geben Sie bitte die Satznummer ein (1-22): ";
	cin >> satzNummer;

	if (satzNummer < 23 && satzNummer > 0){
		satz s = saetze[satzNummer-1];
		anzahlZeichen = s.vokale + s.konsonanten + s.ziffern + s.leerzeichen + s.sonderzeichen;
		cout << "\n\n" << s.wortfolge << "\n";
		cout << "enthaelt:\n";
		cout << anzahlZeichen;
		cout << " Zeichen.\nDiese sind zu:\n";
		printf("%.1f", s.vokale / anzahlZeichen * 100.0);
		cout << "% Vokale,\n";
		printf("%.1f", s.konsonanten / anzahlZeichen * 100.0);
		cout << "% Konsonanten,\n";
		printf("%.1f", s.ziffern / anzahlZeichen * 100.0);
		cout << "% Ziffern,\n";
		printf("%.1f", s.leerzeichen / anzahlZeichen * 100.0);
		cout << "% Leerzeichen,\n";
		printf("%.1f", s.sonderzeichen / anzahlZeichen * 100.0);
		cout << "% Sonderzeichen.\n";
	} 
    
    //Programm beenden
    return 0;
}
