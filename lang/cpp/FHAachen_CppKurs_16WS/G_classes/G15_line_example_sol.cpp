/*	Author: A.Voss@FH-Aachen.de
 * 
 * 	mgl. Klausuraufgabe
 */

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

#include "../tools/tools.h"

class IDrawable {
public:
    virtual void Draw() = 0;
};

class Line : public IDrawable { 
    int x1{},y1{},x2{},y2{};

public:
    Line() {}

    Line& set_P1(int x1,int y1) { 
        this->x1=x1; this->y1=y1;
        return *this;
    }
    Line& set_P2(int x2,int y2) { 
        this->x2=x2; this->y2=y2;
        return *this;
    }

    void Draw() { cout << *this << endl;}
    
    friend std::ostream & operator<<(std::ostream & os, const Line& l ) {
        os << "(" << l.x1 << "," << l.y1 << ";" << l.x2 << "," << l.y2 << ")";
        return os;
    }
};


int main()
{
    Line L;
    
    L.set_P1(2,3)
     .set_P2(5,6);
    
    IDrawable& D = L;
    D.Draw();
    
    return EXIT_SUCCESS;
}

