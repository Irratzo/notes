//The function foo2 takes an integer and returns true if it is prime

using namespace std;

#include <iostream>
#include <cmath>


  bool foo2(unsigned int n)
  {
    int i = 2;
    bool ip = true;

    for (i;i<=n/2;i++) {
      //    while (true){
      //      if ( i > n/2 ) {
      //	cout << i << " > " << n/2 << endl;
      //	break;
      //}
      if ( n%i == 0 ){
	cout << n << " mod " << i << " = 0" << endl;
	ip = false;
	break;
      }
      //      i++;
    }
    return ip;
  }

int main() {

  int entry = 0;

  do{
  cout << "Type number, exit with 47" << endl;
  cin >> entry;
  cout << foo2(entry) << endl;
  }while(entry != 47);



  return 0;

}
