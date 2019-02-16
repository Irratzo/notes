/***
 * D-ITET Informatik 1, Uebungsserie 8, Aufgabe 1
 *
 * Autor: Johannes Wasmer
 * Datum: 23.11.2011
 *
 * 
 * Performs foo(a,b) = a^b, b a natural number
 */

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


double foo(double a, int b)
{
  unsigned int abs_b;
  abs_b = abs(b);
  if (abs_b == 0) return 1.0;
  double c = foo(a,abs_b/2);
  c = c*c;
  if (abs_b % 2 != 0) c = a*c;
  if (b >= 0) 
    return c;
  else 
    return 1/c;
}


void countdown (double bc);


int main () {
  double am = 0;
  unsigned int bm = 0;
  char repeat = 'y';
  double result = 0;

  int test = 3;
  int test2 = 0;
  cout << "First: Divide int " << test << " four times by 2 (which is also int!!)." << endl;

  for (int i = 0; i<4; i++) {
    
    test /= 2;
    cout << test << endl;
  }


  while (repeat == 'y') { 

  cout<< "Enter double: ";
  cin >> am;
  cout << "Enter unsigned int: ";
  cin >> bm;
  result = foo(am,bm);

  cout << "Result: " << result << endl;
  cout << "If you want to continue, type y, else the any key.";
  cin >> repeat;
  }

  countdown(result);
  return 0;
}


void countdown (double bc) 
{
  int n;
  n = int (bc);
  cout << "Counting down ... " << n << "\n";
  if (n > 0)
    countdown(n-1);
  if (n == 0) cout << "Katboom! \n";
}
