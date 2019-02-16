#include <iostream>
#include <vector>
#include <iomanip>
#include <iterator>

using namespace std;


int main () {

  typedef pair<string,int> eingabe;

  eingabe ein1;

  cin >> ein1.first;
  cin >> ein1.second;

  //  copy(ein1, ostream_iterator<eingabe>(cout, " "));
  //funktioniert wahrscheinlich nicht, weil pair kein STL-Container

  cout << ein1.first << " " << ein1.second << endl;

  //Funzt.


}
