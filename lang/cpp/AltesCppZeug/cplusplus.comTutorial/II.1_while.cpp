// Ubung: While-Schleife benutzen

#include <iostream>

using namespace std;


int main ()
{
  int n;

  cout << "Enter a number: " << endl;
  cin >> n;

  while (n>0) {
    cout << n << endl;
    n--;
  }
  cout << "FIRE!"<< endl;

    return 0;
}
