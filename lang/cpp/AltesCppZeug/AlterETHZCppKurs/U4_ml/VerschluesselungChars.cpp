/***
 * Musterloesung D-ITET Info 1, Uebungsserie 4, Aufgabe 3 (Variante 1)
 *
 * Dieses Programm liest sowohl einen Satz als auch ein Passwort
 * als Character Arrays ein. Der Satz wird dann verschluesselt
 * indem jedes Zeichen mit einem Zeichen des Passwortes addiert wird
 * (modulo 26). Der so verschluesselte String wird dann entsprechend
 * wieder entschluesselt
 *
 * Diese Variante benutzt char-Arrays als Strings.
 */


#include <iostream>
#include <cstring>

using namespace std;

int main ()
{
    //Char arrays mit einer "ausreichenden" Laenge
    const int maxLen = 100;
    char satz[maxLen];
    char pass[maxLen];

    //den Satz und das Passwort vom Benutzer erfragen
    cout << "Geben Sie einen Satz ein:" << endl;
    cin.getline(satz, maxLen);
    //getline liest eine ganze Zeile ein. Wuerde nur cin >> satz;
    //benutzt gibt es Probleme mit Leerzeichen im Satz (ausprobieren!)

    cout << "Geben Sie ein Passwort ein:" << endl;
    cin.getline(pass, maxLen);

    //die wahre Laenge des Satzes und des Passworts holen
    int satz_laenge = strlen(satz);
    int passwort_laenge = strlen(pass);

    //und ein Char Array fuer das Ergebnis reservieren
    char verschluesselt[maxLen];

    //Hinweis: Die folgende Operation waere besser in
    //einer Funktion char* encode_strings(char[] s1, char[] s2)
    //aufgehoben; die benoetigten Pointers als Rueckgabewert
    //sind aber erst Bestandteil der naechsten Uebung

    //Den zu verschluesselten Satz zeichenweise
    //durchlaufen.
    for (int i = 0; i < satz_laenge; i++) {

        //das i-te Zeichen des Passworts. Falls das
        //Passwort nicht genug Zeichen hat, wird
        //wieder "von Vorne" begonnen => modulo
        int pass_char = (i % passwort_laenge);

        //das i-te Zeichen des Ergebnisses ist
        //die Addition des i-ten Satzzeichens und des
        //i-ten Passwort-Zeichens
        //wir stellen sicher, dass alles Grossbuchstaben sind
        //Zeichen die keine Buchstaben sind, geben wir einfach unverschluesselt aus.
        if (isalpha(satz[i])) {
            // das aktuelle Zeichen ist ein Buchstabe
            // ASCII A = 65, d.h. wir subtrahieren von beiden Grossbuchstaben 65 und addieren die Buchstaben.
            // Dann rechnen wir modulo 26 und addieren wieder 65, damit wieder ein Grossbuchstabe resultiert
            verschluesselt[i] = (((toupper(satz[i])-65) + (toupper(pass[pass_char])-65)) % 26) + 65;
        } else {
            // das aktuelle Zeichen ist kein Buchstabe, einfach ausgeben
            verschluesselt[i] = satz[i];
        }
    }
    //den c-String richtig abschliessen
    verschluesselt[satz_laenge] = '\0';
    //das Ergebnis ausgeben
    cout << "Verschluesselt: " << endl << verschluesselt << endl;

    //Nach einem Passwort fragen, mit dem der String wieder
    //entschluesselt werden soll
    cout << "Geben Sie ein Passwort ein:" << endl;
    cin.getline(pass, maxLen);
    passwort_laenge = strlen(pass);

    //die umgekehrte Operation wie oben,
    //diesmal mit dem Verschluesselten String
    //als Eingabe
    char entschluesselt[maxLen];
    for (int i = 0; i < satz_laenge; i++) {
        // wie vorher, das Passwort als Ring
        int pass_char = (i % passwort_laenge);
        if (isalpha(verschluesselt[i])) {
            // Zeichen ist ein Buchstabe
            // Addiere 26 zur Eingabe, damit durch die Subtraktion
            // keine negative Zahl entsteht, die dann Probleme
            // beim Modulo und der Umrechnung ergeben kann
            entschluesselt[i] = (((26 + (toupper(verschluesselt[i])-65)) - (toupper(pass[pass_char])-65)) % 26) + 65;
        } else {
            // Zeichen ist kein Buchstabe, einfach wieder ausgeben
            entschluesselt[i] = verschluesselt[i];
        }
    }
    //den c-String richtig abschliessen
    entschluesselt[satz_laenge] = '\0';

    //das Ergebnis bekannt geben
    cout << "Entschluesselt: " << endl << entschluesselt << endl;

    //Programm beenden
    return 0;
}
