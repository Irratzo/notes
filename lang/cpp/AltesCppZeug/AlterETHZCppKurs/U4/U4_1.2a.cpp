using namespace std;

#include <iostream>

int main() {

  double a[3];
  double b[3];

  cout << "a_1 =";
  cin >> a[0];
  cout << "a_2 =";
  cin >> a[1];
  cout << "a_3 =";
  cin >> a[2];

  cout << "b_1 =";
  cin >> b[0];
  cout << "b_2 =";
  cin >> b[1];
  cout << "b_3 =";
  cin >> b[2];

  cout << "a = (" << a[0] << ", " << a[1] << ", " << a[2] << "), b = (" << b[0] << ", " << b[1] << ", " << b[2] << ")" << endl;

  a[0] += b [0];
  a[1] += b [1];
  a[2] += b [2];

  cout << "c = a+b = (" << a[0] << ", " << a[1] << ", " << a[2] << ")" << endl;

  return 0;

}
