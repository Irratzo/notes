/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Zeigerkonvertierung und gezielte Modifikation einzelner Bytes.
 * 
 *  Stichworte:
 *      - pointer, cast
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

void f1(int n);
void f2(int n);
int g(int n);

typedef void (*caller_t)(int);

int main()
{
    /*
	int32_t n = 0x12345678;
	
	// n hexadezimal 
    tools_log(); cout << "n=0x" << hex << n << endl;
    
    // ein einzelnes Byte veraendern, warum dieses? 
    int8_t* pn = reinterpret_cast<int8_t*>(&n); // (int8_t*)(&n);
	*(pn+2) = (char)0xab;
    tools_log(); cout << "n=0x" << hex << n << endl << endl;

    // vier ints auf dem Stack
	int a=0x12, b=0x34, c=0x56, d=0x78;
	int* pi;
	
	// Variablen auf dem Stack manipulieren; Art und Weise haengen am Compiler, alignment, ... 
    tools_log(); cout << "a=0x" << a << ", b=0x" << b << ", c=0x" 
                      << c << ", d=0x" << d << endl;
	pi = &a + 2;
	*pi = 0xff;
    tools_log(); cout << "a=0x" << a << ", b=0x" << b << ", c=0x" 
                      << c << ", d=0x" << d << dec << endl << endl;
    */
    // man kann so grundsaetzlich auch die Rücksprungadresse auf dem Stack manipulieren ...
    tools_log(); cout << "&f1=" << (caller_t*)&f1 << endl;
    tools_log(); cout << "&f2=" << (caller_t*)&f2 << endl << endl;
    f1(5);
    
    /*
    // void* haben keine Typinformation, die Zuweisung funktioniert immer
    void* p;
    p = pn;
	p = pi;
	tools_log(); cout << "p=" << p << ", pi=" << pi << endl;
    */

    return EXIT_SUCCESS;
}

void f1(int n)
{
    tools_log(); cout << "f1: n=" << n << ", rufe g auf" << endl;
    int m = g(n);
    tools_log(); cout << "f1: m=g(" << n << ")=" << m << endl << endl;
}

void f2(int n)
{
    tools_log(); cout << "f2: n=" << n << ", rufe g auf" << endl;
    int m = g(n);
    tools_log(); cout << "f2: m=g(" << n << ")=" << m << endl << endl;
}

int g(int n)
{
    int m = 3*n;
    tools_log(); cout << "n=" << n << ", m=" << m << ", &m=" << &m << endl;

    // m liegt auf dem Stack, in der Naehe liegt auch die Ruecksprungadr.
    long* lp = reinterpret_cast<long*>( (long*)(&m)+0x0); // 2c

    // die suchen wir
    tools_log(); cout << "stackframe:" << endl;
    for (int i=5; i<9; ++i)
        cout << "i=" << hex << i << " " << *(lp+i) << endl;

    // in diesem Fall, auch abhaengig davon, wieviele lokale Vars. wir haben
    long* retp = reinterpret_cast<long*>( (long*)(&m)+7);
    tools_log(); cout << "retp=" << retp << ", *retp=" << *retp << endl;
    
    // rechne so, als wenn die Zeiger in long passen; das muss nicht immer so funkt.!
    // ebenfalls nehmen wir an, dass die lokale Adr. relativ zu &f1 auch in f2 passt,
    // bei verschiedenen Fkt. ist das nicht so!
    long newp = (*retp) - (long)(&f1) + (long)(&f2);
    tools_log(); cout << "newp=" << (void*)newp << endl; 
    
    *retp = (long)(newp);
        
    return m;
}
