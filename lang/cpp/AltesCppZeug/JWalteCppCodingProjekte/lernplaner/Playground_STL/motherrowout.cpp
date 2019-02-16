#include <iostream>
#include <vector>
#include <iomanip>
#include <iterator>
#include <algorithm>

using namespace std;

  typedef pair<string,int> intmp;
  typedef vector< intmp > eingabe;
  typedef vector <string> motherrow;

  bool sort_pred(const intmp& elementlinks, const intmp& elementrechts) {
    return elementlinks.second < elementrechts.second;
  }


int main () {

  int t;

  cin >> t;

  eingabe ein1;
  pair<string,int> intmp1;

  for (int i=0; i<t; i++) {

    cin >> intmp1.first;
    cin >> intmp1.second;

    ein1.push_back(intmp1);
    
  }

  //Sorting mit predicate wie von bit.ly/OTF8p1


  sort(ein1.begin(), ein1.end(), sort_pred);

  //  copy(ein1.begin(), ein1.end(), ostream_iterator<>(cout, " "));
  //funktioniert perdef nich wegen pair: bit.ly/OKrJgY, Koenig lookup

  //  cout << "Größe des Feldes: " << ein1.size() << endl;
  //  cout << "Maximalgröße: " << ein1.capacity() << endl;


  //  for (unsigned int j=0; j < ein1.size(); j++)
  //      cout << ein1[j].first << " " << ein1[j].second << endl;

  motherrow motherrow1;

  for (unsigned int j=0; j < ein1.size(); j++)
    motherrow1.push_back(ein1[j].first);

  copy(motherrow1.begin(), motherrow1.end(), ostream_iterator<string>(cout,"\n"));

       //Funzt.

}
