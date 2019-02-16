/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	Zeiger auf Zeiger auf Zeiger ...
 * 
 *  Stichworte:
 *      - op *, op &
 */

#include <iostream>
using namespace std;

#include "../tools/tools.h"

bool reserve_buffer(size_t n,double** ppd1, double** ppd2);

int main()
{
	int n=1, m=2;
	
    tools_log(); cout << "n=" << n << ", m=" << m << endl;
	
    // zwei Pointer, die auf zwei verschiedene ints zeigen
	int *pn=&n, *pm=&m;	

    tools_log(); cout << "pn=" << pn << ", *pn=" << *pn
                      << ", pm=" << pm << ", *pm=" << *pm << endl;

    // genau wie n und m eine Adr. haben, haben auch pn und pm jeweils eine
    tools_log(); cout << "&pn=" << &pn << ", &pm=" << &pm << endl;
    
    // was ist die Adr. von pn bzw. pm nun fuer ein Typ?
	int **ppn = &pn, **ppm=&pm;   
    tools_log(); cout << "ppn=" << ppn << ", ppm=" << ppm << endl;
    
    // nochmal? auch ppn und ppm sind an einem Speicherort
    int ***pppn = &ppn;
    tools_log(); cout << "&ppn=" << &ppn << ", pppn=" << pppn << endl;

    // kommt man wieder auf n?
    ***pppn = 3;
    tools_log(); cout << "n=" << n << ", m=" << m << endl << endl;
    
    // braucht man int** oder int*** ... ? ja, z.B. so
    
    double *pd1 = nullptr, *pd2 = nullptr;
    
    bool rc = reserve_buffer(100,&pd1,&pd2);
    tools_log(); cout << "Alloc. OK? " << (rc ? "J" : "N") << endl;
    delete pd1; // fehler? -> valgrind
    delete pd2;

    return EXIT_SUCCESS;
}

// Speicher reservieren und Ptr. darauf zurueckgeben
bool reserve_buffer(size_t n,double** ppd1, double** ppd2)
{
    *ppd1 = new double[n];
    *ppd2 = new double[n];
    
    return (nullptr!=*ppd1 && nullptr!=*ppd2);
}
