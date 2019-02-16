/*	Author: A.Voss@FH-Aachen.de
 */

#include <iostream>
#include <string>
using namespace std;

/*  Legen Sie eine Struktur 'Node' an, die einen Zeiger 'next' auf Node
 *  enthaelt, sowie einen string 'content'.
 *  Ziel ist eine einfach verkettet Liste.
 */

// struct Node ...



/*  Legen Sie einen Node-Zeiger 'root' an und initialisieren ihn mit dem
 *  Nullzeiger.
 */

// ...root = ...



/*  Implementieren Sie die Funktion 'appendNode', die eine dynamisch
 *  allokierte Node (via new) an die letzte Node anhaengt (next zeigt
 *  auf die neue Node) oder, bei der ersten, 'root' darauf zeigen laesst.
 *  Der uebergebene 'content' wird in die neue Node kopiert.
 */
void appendNode(string content) {
    // ...
}



/*  Implementieren Sie die Funktion 'printNodes', die einfach alle
 *  Nodes nacheinander ausgibt.
 */
void printNodes() {
    cout << "Nodes:";
    // ...
    cout << endl;
}

int main()
{
    cout << endl << "---" << endl << endl;
    
    appendNode("1");
    appendNode("2");
    appendNode("3");
    printNodes();       // Erwartet: "Nodes: '1' '2' '3'"
    
    cout << endl << "---" << endl << endl;
   
    return EXIT_SUCCESS;
}

