using namespace std;

#include <iostream>
#include <cmath>


int main () {

  cout << 1+3*2 << endl;
  cout << 13/7  << endl;
  cout << 9*3/2.0 << endl;
  cout << 30%7 << endl;
  cout << 15.0/5 << endl;
  cout << 9/5*5 << endl;
  cout << 2.0*5/2 << endl;
  cout << 11.0/4.0 << endl;

  cout << "3." << endl;
  cout << (double)(9/5) << endl;
  cout << (int)14.0/4 << endl;
  cout << 7/(double)2 << endl;
  cout << (int)(15.0/6) << endl;

  char a = '5';
  char atest = '&';
  double b = 0.0;
  double c = 0.0;
  int d = 3;
  int e = 0;

  b = d = 81.0 / a+1;
  c = 12.3 <= 3-2 || (e = 7);
  a = (char)((int)'M'/2);

  cout << endl << "Aufgabe 6" << endl; // Output
  cout << "int(a) =" << int(a) << endl; // 38
  cout << "int(atest) =" << int(atest) << endl; // 38
  cout << "a+1 =" << a+1 << endl; // 39
  cout << "int('M') =" << int('M') << endl; // 77

  cout << a << endl; // &
  cout << b << endl; // 2
  cout << c << endl; // 1
  cout << d << endl; // 2
  cout << e << endl; // 7

  cout << endl << "Aufgabe 7" << endl; // Output
  double d2 = 5;
  cout << 7 / d2 << endl;
  cout << 7.0 / d2 << endl;

  return 0;

}
