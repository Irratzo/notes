#include <iostream>
#include <vector>

using namespace std;

int main () {

  vector<int> test;

  test.push_back(4);
  test.push_back(2);
  //  test.insert(test.begin()+5,3);
  //produziert segfault (core dump)

  cout << test.size() << endl;
  //Ausgage: 2

  for (unsigned int i=0; i< test.size(); i++)
    cout << test[i] << " ";
    cout << endl;
    //Ausgabe: 4 2

  return 0;

} 
