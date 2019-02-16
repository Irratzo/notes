/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	C-string Funktionen
 * 
 *  Stichworte:
 *      - C-string, strlen, strcpy, strcat, strchr, strstr
 *      - malloc, free
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

size_t myLen(const char* msg);
void myCopy(const char* m, char** pp);

int main()
{
    const char *msg1 = "Dies ist ein Satz.";	// 18 chars, ohne \0

    tools_log(); cout << "msg1=\"" << msg1 << "\"" << endl;
    tools_log(); cout << "myLen=" << myLen(msg1) << ", strlen=" << strlen(msg1) << endl;

    // reserviere ein Speicherbereich und kopiere
    char* msg2;
    myCopy(msg1,&msg2);
    tools_log(); cout << "msg2=\"" << msg2 << "\"" << endl;
    // nicht vergessen!
    free(msg2);
    
	// jetzt analoge C-string Funktionen

    // Platz reservieren fuer 2* den Text + 0-char 
	char* p = (char*)malloc( strlen(msg1)*2*sizeof(char)+1 );
	
    // aneinanderhaengen; Vorsicht, Quelle und Ziel duerfen sich nicht ueberlappen
	strcat(strcpy(p,msg1),msg2);
    tools_log(); cout << "p=\"" << p << "\"" << endl;	
	
	// Zeichen suchen, alternativ mit strstr fuer C-strings
	const char *pos = strchr(msg1,'S');
    tools_log(); cout << "pos. of 'S'=" << (pos-msg1) << endl;	
    
    free(p);
    
    return EXIT_SUCCESS;
}

// wie strlen
size_t myLen(const char* m)
{
    const char* p  = m;
	while (*(p++)) ;    // suche 0-char
	return (p-m-1);     // pointer Arithmetik
}

// strcpy mit malloc
void myCopy(const char* m, char** pp)
{
    size_t len = myLen(m);
	*pp = (char*)malloc( (len+1)*sizeof(char) );    // +1 fuer abschl. 0-char
    const char* pcSrc = m;
    char* pcDst = *pp;

    // kopieren
	while ( (*(pcDst++)=*(pcSrc++)) )
        ;
}

