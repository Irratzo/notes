/***
 * Musterloesung D-ITET Info 1, Uebungsserie 4, Aufgabe 3 (Variante 1)
 *
 * Dieses Programm liest sowohl einen Satz als auch ein Passwort
 * als Character Arrays ein. Der Satz wird dann verschluesselt
 * indem jedes Zeichen mit einem Zeichen des Passwortes addiert wird
 * (modulo 26). Der so verschluesselte String wird dann entsprechend
 * wieder entschluesselt
 *
 * Diese Variante benutzt die C++ string-Klasse.
 */

#include <iostream>
#include <string>

using namespace std;

//die Funktion nimmt zwei strings und macht eine
//zeichenweise Addition der Buchstaben
//Der Ergebnisstring ist genauso lang wie der
//eingegebene satz.
string verschluessle_strings(string satz, string pass) {

    //der Ergebnisstring
    string res;

    //die Laenge des Satzes und des  Passworts ermitteln
    int satz_laenge = satz.size();
    int passwort_laenge = pass.size();

    //Den Satz zeichenweise durchlaufen
    for (int i = 0; i < satz_laenge; i++) {

        //das i-te Zeichen des Passworts. Falls das
        //Passwort nicht genug Zeichen hat, wird
        //wieder "von Vorne" begonnen => modulo
        char pass_char = i % passwort_laenge;

        //das i-te Zeichen des Ergebnisses ist
        //die Addition des i-ten Satzzeichens und des
        //i-ten Passwort-Zeichens modulo 26
        //wir stellen sicher, dass alles Grossbuchstaben sind
        //Zeichen die keine Buchstaben sind, geben wir einfach unverschluesselt aus.
        if (isalpha(satz[i])) {
            // das aktuelle Zeichen ist ein Buchstabe
            // ASCII A = 65, d.h. wir subtrahieren von beiden Grossbuchstaben 65 und addieren die Buchstaben.
            // Dann rechnen wir modulo 26 und addieren wieder 65, damit wieder ein Grossbuchstabe resultiert
            res += (((toupper(satz[i])-65)+(toupper(pass[pass_char])-65))%26)+65;
        } else {
            res += satz[i];
        }
    }

    return res;

}

string entschluessle_strings(string satz, string pass) {

    //der Ergebnisstring
    string res;

    //die Laenge des Satzes und des  Passworts ermitteln
    int satz_laenge = satz.size();
    int passwort_laenge = pass.size();

    //Den Satz zeichenweise durchlaufen
    for (int i = 0; i < satz_laenge; i++) {

        //das i-te Zeichen des Passworts. Falls das
        //Passwort nicht genug Zeichen hat, wird
        //wieder "von Vorne" begonnen => modulo
        char pass_char = i % passwort_laenge;

        //die umgekehrte Operation wie bei verschluessle_strings
        if (isalpha(satz[i])) {
            // Zeichen ist ein Buchstabe
            // Addiere 26 zur Eingabe, damit durch die Subtraktion
            // keine negative Zahl entsteht, die dann Probleme
            // beim Modulo und der Umrechnung ergeben kann
            res += (((26+toupper(satz[i])-65)-(toupper(pass[pass_char])-65))%26)+65;
        } else {
            // Zeichen ist kein Buchstabe, einfach wieder ausgeben
            res += satz[i];
        }
    }

    return res;

}

int main ()
{
    //zwei String-Objekte fuer den Satz und das Passwort
    string satz;
    string pass;

    //den Satz und das Passwort vom Benutzer erfragen
    cout << "Geben Sie einen Satz ein:" << endl;
    getline(cin, satz);
    //getline liest eine ganze Zeile ein. Wuerde nur cin >> satz;
    //benutzt gibt es Probleme mit Leerzeichen im Satz (ausprobieren!)

    cout << "Geben Sie ein Passwort ein:" << endl;
    getline(cin, pass);

    //den Satz durch Addition mit dem Passwort verschluesseln
    string satz_verschluesselt = verschluessle_strings(satz, pass);

    //ds Ergebnis ausgeben
    cout << "Verschluesselt: " << endl << satz_verschluesselt << endl;

    //ein erneutes Passwort erfragen, um den verschluesselten String
    //zu entschluesseln
    cout << "Geben Sie ein Passwort ein:" << endl;
    getline(cin, pass);

    //entschluesseln durch x-or und das Ergebnis gleich ausgeben
    cout << "Entschluesselt: " << endl;
    cout << entschluessle_strings(satz_verschluesselt, pass) << endl;

    //programm beenden
    return 0;
}
