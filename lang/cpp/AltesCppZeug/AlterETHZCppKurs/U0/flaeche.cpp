/***
 * Beispielprogramm Informatik 1 D-ITET, Uebung 0
 *
 * Author: Mathias Payer <mathias.payer@inf.ethz.ch>
 * Last change: 2007/09/25
 *
 * Ein einfaches Beispielprogramm, das nach der Eingabe eines
 * double Kreisradius die Kreisfläche berechnet und ausgibt.
 */

#include <iostream>
/* verwende die Bibliothek iostream, welche die zwei Stream cin und count enthält, die im Programm verwendet werden */

using namespace std;
/* gliedere das Programm in den namespace "std" ein. */

/**
 * Diese Funktion berechnet die Kreisfläche und gibt das Resultat zurück
 * @param radius Radius des Kreises
 * @return Kreisfläche mit Radius radius
 */
double berechne_kreisflaeche(double radius)
/* deklariere eine Funktion berechne_kreisflaeche, welche einen double-Parameter radius verwendet und eine double-Zahl als Resultat zurückgiebt */
{
	double temp = 0; // deklariere und initialisiere eine Variabel "temp" mit 0
	double pi = 3.1415; // siehe oben
	temp = radius * radius * pi; // speichere die Kreisflaeche in temp
	return temp; // retourniere das Resultat an die aufrufende Funktion
}

/**
 * Hauptprogramm, welches etwas Info-Text ausgibt, den
 * Radius einliest und die Funktion aufruft.
 * @return Rückgabewert des Programms
 */
int main()
/* deklariere eine Funktion main welche eine Integer-Zahl als Resultat zurückgibt */
{
	double r1, kA; // Zwei uninitialisierte double Variabeln r1 und kA
	cout << "Ein nettes Biespielprogramm fuer die erste Uebung" << endl;
	/* sende den obigen Text und ein endl an den Stream cout */
	cout << "Bitte geben Sie einen gueltigen Radius fuer r1 ein: ";
	/* siehe oben */
	cin >> r1;
	/* lies Daten vom cin-Stream in die double-Variabel r1 */
	kA = berechne_kreisflaeche(r1);
	/* rufe die Funktion berechne_kreisflaeche mit Parameter r1 auf und
	   speichere das Resultat in kA */
	cout << "Die Kreisflaeche ist: " << kA << endl;
	/* gib das Resultat auf dem Bildschirm aus */
	return 0;
	/* Beende ds Programm ohne Fehler (mit Rückgabewert 0) */
}
