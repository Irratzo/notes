using namespace std;

#include <iostream>
#include <climits>

int main () {

  cout << "Teste short1+short2 Overflow" << endl;

  short s1;
  short s2;
  double d;

  s1 = SHRT_MAX;
  s2 = SHRT_MAX/2;

  d = (double)s1+(double)s2;
  cout << s1 << '+' << s2 << endl;
  cout << "Mathematisches Ergebnis: " << d << endl;

  s1 += s2;

  cout << "Reales Ergebnis: " << s1 << endl;

  cout << "Teste Overflow bei Konvertierung short-double-short" << endl;

  s1 = SHRT_MAX;
  s2 = SHRT_MAX/2;
  d = (double)SHRT_MAX + (double)SHRT_MAX/2;

  cout << s1 << '+' << s2 << endl;
  cout << "Mathematisches Ergebnis: " << d << endl;

  s1 = (short)d;

  cout << "Reales Ergebnis: " << s1 << endl;

  return 0;
}

// kein Overflow:
// short s;
// double d;
// d = -5*SHRT_MAX;
// s = (short)d;
// cout << s << endl;
