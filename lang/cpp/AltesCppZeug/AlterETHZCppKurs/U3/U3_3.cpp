//This program prints a christmas tree with height h in the console.


# include <iostream>

using namespace std;



int main () {

  int h = 0;
  int i = 0;
  int j = 0;

  cout << "Bitte geben Sie die Hoehe des Christbaums ein: " << endl;
  cin >> h;
  cout << endl;

  for (; h>0 ; h--) {
    for (i=h;i>0; i--) {
      cout << " " ; }
    for (i=0; i<j; i++) {
      cout << "*" ; }
    cout << "I" ;
    for (i=0; i<j; i++) {
      cout << "*" ; }
    cout << endl;
    j++;
    
  }

  return 0;

}
