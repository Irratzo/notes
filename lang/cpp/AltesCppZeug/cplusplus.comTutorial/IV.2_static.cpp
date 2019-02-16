// static members in classes
#include <iostream>
using namespace std;

class CDummy {
  public:
    static int n;
    CDummy () { n++; };
    ~CDummy () { n--; };
};

int CDummy::n=0;

int main () {
  CDummy a;
  CDummy b[5];
  CDummy * c = new CDummy;
  cout << b[2].n  << endl; //b[k].n, CDummy::n, a.n equiv
  delete c;
  cout << b[1].n << endl; //see comment above
  return 0;
}
