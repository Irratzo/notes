// for - Ubung

#include <iostream>
#include <string>

using namespace std;


int main () 
{
  int x;
  int y; 
  for (y=1; y<=120; y=y+1) {
    for (x=1; x<=y; x=x+1) {
      if ((x+y)%2 != 0) {
	cout << "/";
      } else {
	cout << "\\";
      }
    }
    cout << endl;
  }

  return 0;
  }
