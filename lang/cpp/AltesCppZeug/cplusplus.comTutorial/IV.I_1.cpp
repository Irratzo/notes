//classes example
#include <iostream>
using namespace std;

class crect {
  int *width, *height;
public:
  crect (int ,int );
  ~crect ();
  int area () {return(*width * *height);}
};

crect::crect (int a, int b) {  
  width = new int;
  height = new int;
  *width = a;
  *height = b;
}

crect::~crect () {
  delete width;
  delete height;
}

int main () {
  crect recta (3,4);
  crect rectb (5,6);

  cout << "area a is " << recta.area() << endl;
  cout << "area b is " << rectb.area() << endl;
  return 0;
}
