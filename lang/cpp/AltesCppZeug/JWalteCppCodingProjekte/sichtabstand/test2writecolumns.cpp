using namespace std;

#include <iostream>
#include <fstream>
#include <cmath>


int main () {
  //file objects
  ofstream fout;
  //  ifstream fin;

  //file opening
  fout.open("columns.txt");

  if (!fout.is_open()) {
    cout << "File open error \n";
    return 1;
  }

  int ints[4];
  double doubles[4];

  for (int i=1; i<5; i++) {

    ints[i] = i;
    doubles[i] = sqrt(double(i)); 

    // cout << ints[i] << ' ' << doubles[i] << endl;
    //write file
 fout << ints[i] << ' ' << doubles[i] << endl;
   
  }

  //close file
  fout.close();

  return 0;

} 
