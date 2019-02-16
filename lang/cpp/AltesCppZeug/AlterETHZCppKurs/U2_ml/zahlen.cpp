/***
 * Musterloesung D-ITET Info 1, Uebungsserie 2, Aufgabe 4
 *
 * Author: Dirk Zimmer <dzimmer@inf.ethz.ch>
 * Last change: 2010/10/12 by Daniel Dalquen <ddalquen@inf.ethz.ch>
 *
 * Ein einfaches Beispielprogramm, das nach der Eingabe einer
 * zweistelligen Dezimalzahl diese ausgeschrieben wieder ausgibt.
 */

#include <iostream>
#include <math.h>
using namespace std;

int ausnahmen(int z);
int einer(int e);

int main() {
	// Zahl einlesen
	double n;
	double n1;
	cout << "Bitte geben Sie eine zweistellige positive Dezimalzahl ein: ";
	cin >> n;

	//Zahl pruefen
	if (n<0 || n>=100) {
     	cout<< "Dies war keine gueltige Zahl" << endl;
     	return 0;
	}

	//To overcome precision issues
	n1 = floor(n*10+0.5);

	int ganzzahl = floor(n1/10);

	//Ausnahmefaelle abfangen 1,11,12,16,17
	if (ausnahmen(ganzzahl)) {

		//Zahl in einzelne Ziffern trennen
		int e = ganzzahl%10;
		int z = ganzzahl/10;

		//Einer-Ziffer ausgeben
		einer(e);

		//Bindungs-und
		if (z > 1 && einer > 0) cout << "und";

		//Zehner-Ziffer ausgeben
		switch (z) {
			case 1 :	cout << "zehn";
				break;
			case 2:		cout << "zwanzig";
				break;
			case 3:		cout << "dreissig";
				break;
			case 4:		cout << "vierzig";
				break;
			case 5:		cout << "fuenfzig";
				break;
			case 6:		cout << "sechzig";
				break;
			case 7:		cout << "siebzig";
				break;
			case 8:		cout << "achtzig";
				break;
			case 9:		cout << "neunzig";
		}
	}

	cout << "komma";

	int k = (int) n1 % 10;
	if (ausnahmen(k)) {
		einer(k);
	}

	cout << endl;
	return 0;

}

int ausnahmen(int z) {
	switch (z) {
		case 0 :    cout << "null";
			return 0;
     	case 1 :	cout << "eins";
			return 0;
     	case 11:	cout << "elf";
			return 0;
     	case 12:	cout << "zwoelf";
			return 0;
     	case 16:	cout << "sechzehn";
			return 0;
     	case 17:	cout << "siebzehn";
			return 0;
	}
	return 1;
}

int einer(int e) {
	switch (e) {
     	case 1 :	cout << "ein";
			return 0;
     	case 2:		cout << "zwei";
			return 0;
     	case 3:		cout << "drei";
			return 0;
     	case 4:		cout << "vier";
			return 0;
     	case 5:		cout << "fuenf";
			return 0;
     	case 6:		cout << "sechs";
			return 0;
     	case 7:		cout << "sieben";
			return 0;
     	case 8:		cout << "acht";
			return 0;
     	case 9:		cout << "neun";
			return 0;
	}
	return 1;
}
