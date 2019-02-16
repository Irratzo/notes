#include <iostream>

using namespace std;

int main() {

  char s1[] = "Hello";
  char s2[10] = {0};
  char* s3;
  cout << s1 << endl;
  s3 = &s1[2];
  cout << s3 << endl;
  for (char c=0; c<9; c++) {
    s2[c] = '1'+c;
  }
  cout << s2 << endl;

  int i=0;
  while(s1[i] !=0) {
    s2[i] = s1[i];
    i=i+1;
  }
  cout << s2 << endl;

  *s3 = 0;
  cout << s1 << endl;

  return 0;

}
