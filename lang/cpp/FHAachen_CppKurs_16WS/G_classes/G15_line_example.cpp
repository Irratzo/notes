/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	mgl. Klausuraufgabe
 */

#include <iostream>
using namespace std;

// (1)
// class IDrawable

class Line  /* (1) */ { 
    int x1,y1,x2,y2;    // (2)

public:
    Line() {}

    void Draw() { /* cout << *this << endl; */ }    // (3)
    
    // (3)
    // operator<<

    // (4)
    /*
    <rueckgabetyp> set_P1(int x1,int y1) { 
        // member x1 und y1 setzen
    }
    <rueckgabetyp> set_P2(int x2,int y2) { 
        // member x2 und y2 setzen
    }
    */
};


int main()
{
    Line L;
    
    // (4)
    /*
    L.set_P1(2,3)
     .set_P2(5,6);
    */
    
    // IDrawable& D = L;
    // D.Draw();
    
    return EXIT_SUCCESS;
}

