//Q: ist (-1)%5 = 4? Auch wenn x=(j-u)%n mit x,j,u,n unsigned int?

 
#include<iostream>

using namespace std;


int main() {

  unsigned int j= 1;
  unsigned int u = 2; 
  unsigned int n = 5;

  cout << "A) -1 % 5 = " << -1 % 5 << endl;
  cout << "B) unsigned int test: j=1, u=2, n=5." << endl;
  cout << "(j-u)%n =" << (j-u)%n << endl;
  cout << "C) alle var zu int umgewandelt:";
    cout << "(j-u)%n = " << (static_cast<int>(j)-static_cast<int>(u))%static_cast<int>(n) << endl;

  return 0;

  //Output A): -1%5 == -1
  //Output B): (j-u)%n == 0
  //Output C): (j-u)%n == -1

}
