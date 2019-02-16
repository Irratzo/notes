//operator overloading
#include <iostream>
using namespace std;

class vector {                   // vector addition
public:                         // public MEMBERS
  int x, y;                      //2 int arguments
  vector () {};                  //empty constructor
  vector (int, int);            //constructor of class vector L13
  vector operator + (vector);   //type operkeyword sign (parameter type)
};

vector::vector (int a, int b) {  //L9 class constructor declaration
  x = a; 
  y = b;
}

vector vector::operator+ (vector param) { //operator overload FUNCTION
  vector temp;                           //typevectorclass name
  temp.x = x+param.x;                    //von x, 
  temp.y = y+param.y;
  return (temp); 
}

int main () {
  vector a (3,1);
  vector b (1,2);
  vector c;
  c = a + b;
  cout << c.x << "," << c.y << endl;
  return 0;
}
