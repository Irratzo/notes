using namespace std;

#include <iostream>

int main() {

  int dim;

  cout << "Vektor Dimension = ";
  cin >> dim;

  dim--;

  double a[dim];
  double b[dim];

  for (int i=0; i<=dim; i++) {
    cout << "a_" << i << " =";
    cin >> a[i];
  }

  for (int i=0; i<=dim; i++) {
    cout << "b_" << i << " =";
    cin >> b[i];
  }

  cout << "a = (";
  for (int i=0; i<=dim; i++) {
    cout << a[i];
    if (i == dim)
      break;
    cout << ", ";
  }
  cout << ")" << endl;

  cout << "b = (";
  for (int i=0; i<=dim; i++) {
    a[i] += b[i];

    cout << b[i];
    if (i == dim)
      break;
    cout << ", ";
  }
  cout << ")" << endl;

  cout << "c = a+b = (";
  for (int i=0; i<=dim; i++) {
    cout << a[i];
    if (i == dim)
      break;
    cout << ", ";
  }
  cout << ")" << endl;


  return 0;

}
