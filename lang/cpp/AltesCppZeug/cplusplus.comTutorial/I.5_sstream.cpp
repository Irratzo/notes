//Clonclusion: Both cin and sstream get it right, because cin computes int with float which by default returns float.

//stringstreams
// This program lets the user compare if cin gets it right if the user provides 
// the wrong type for the calculation.

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main () {

  string mystr;      // these variables are used for sstream extraction
  float price = 0;
  int quantity = 0;

  float price_2 = 0;  // these variables are used for cin extraction
  int quantity_2 = 0;

    cout << "Enter total price: ";  //sstream price extraction
    /*getline (cin, mystr);
  stringstream(mystr) >> price;
  */
    cin >> price_2;           // cin price extraction
   
  cout << "Enter quantity: ";  //stream quantity extraction
  /*  getline(cin,mystr);
  stringstream(mystr) >> quantity;
    */
  cin >> quantity_2;         // cin quantity extraction
  /*
  cout << "sstream calculation" << endl;
  cout << "Piece price: " << price/quantity << endl;
  cout << "             " << endl;
  */
   cout << "cin calculation"<< endl;
  cout << "Piece price: " << price_2/quantity_2 << endl;

  return 0;
}
