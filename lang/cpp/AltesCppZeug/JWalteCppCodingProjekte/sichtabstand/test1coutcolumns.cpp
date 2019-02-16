using namespace std;

#include <iostream>
#include <fstream>
#include <cmath>


int main () {

  int ints[4];
  double doubles[4];

  for (int i=1; i<5; i++) {

    ints[i] = i;
    doubles[i] = sqrt(double(i)); 

    cout << ints[i] << ' ' << doubles[i] << endl;

  }

  return 0;

} 
