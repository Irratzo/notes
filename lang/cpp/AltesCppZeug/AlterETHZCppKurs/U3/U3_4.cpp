//This program calculates Euler's number.

#include <iostream>

using namespace std;


int main () {

  double e = 1;
  int i = 0;
  double k = 1;

  for (i;i<14;i++) {  //14 iterations found for 10 decimals precision by trial&error.
    k*= i+1;
    e+=1/k; 
  }

  cout.precision(11);
  cout << "This program calculates Euler's number as a series expansion." << endl;
  cout << "The precision is set to 10 decimal digits." << endl;
  cout << "e = " << e << endl;

  return 0;
}
