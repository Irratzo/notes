/***
 * Musterlösung D-ITET Info 1, Uebungsserie 2, Aufgabe 4
 *
 * Author: C. Niederberger <niederberger@inf.ethz.ch>
 *         Mathias Payer <mathias.payer@inf.ethz.ch>
 * Last change: 2006/10/13
 *
 * Dieses Programm zeigt die Speicherbelegung und den
 * Wertebereich der einzelnen Datentypen von C++ an.
 */

// Für die Verwendung von cin und cout
#include <iostream>
using namespace std;

// die Wertebereiche der Datentypen sind in climits definiert
#include <climits>
#include <cfloat>

/**
 * Erzeugt eine Tabelle mit den einzelnen Limits und Grössen der Datentypen
 * @return void-Methode, deshalb keinen Rückgabewert
 */
void limits()
{
	// output
	cout << "Type\t\tSize\t\tMin\t\tMax" << endl;
	cout << "---------------------------------------------------------------" << endl;
	cout << "char\t\t"    << sizeof(char)      << "\t\t" << CHAR_MIN << "\t\t" << CHAR_MAX << endl;
	cout << "short int\t" << sizeof(short int) << "\t\t" << SHRT_MIN << "\t\t" << SHRT_MAX << endl;
	cout << "int\t\t"     << sizeof(int)       << "\t\t" << INT_MIN  << "\t"   << INT_MAX  << endl;
	cout << "long int\t"  << sizeof(long int)  << "\t\t" << LONG_MIN << "\t"   << LONG_MAX << endl;
	cout << "float\t\t"   << sizeof(float)     << "\t\t" << FLT_MIN  << "\t"   << FLT_MAX  << endl;
	cout << "double\t\t"  << sizeof(double)    << "\t\t" << DBL_MIN  << "\t"   << DBL_MAX  << endl;			
	cout << "bool\t\t"    << sizeof(bool)      << "\t\t" << "false"  << "\t\t" << "true"   << endl;				

	// return ist nicht zwingend notwendig, wenn die Funktion als void definiert ist
	// Damit ist dem Leser aber klar, dass hier das Ende der Funktion erreicht ist
	return;
}


/**
 * Hauptprogramm, welches dieses Mal nur unsere Methode aufruft.
 * @return Rückgabewert des Programms
 */
int main()
{
	limits();

	/* Erfolgreiches Programmende */
	return 0;
}

