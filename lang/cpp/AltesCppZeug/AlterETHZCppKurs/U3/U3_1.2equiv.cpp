using namespace std;

#include <iostream>
#include <cmath>


  bool foo(unsigned int n)
  {
    int i = 2;
    bool ip = true;

    while (true){
      if ( i > n/2 ) {
	cout << i << " > " << n/2 << endl;
	break;
      }
      if ( n%i == 0 ){
	cout << n << " mod " << i << " = 0" << endl;
	ip = false;
	break;
      }
      i++;
    }
    return ip;
  }

int main() {

  int entry = 0;

  do{
  cout << "Type number, exit with 47" << endl;
  cin >> entry;
  cout << foo(entry) << endl;
  }while(entry != 47);



  return 0;

}
