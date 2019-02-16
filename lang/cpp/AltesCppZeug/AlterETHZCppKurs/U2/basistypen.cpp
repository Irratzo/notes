/***
 * Programm Uebung 2, Aufgabe 1
 *
 * Author: Johannes Wasmer <wasmerj@student.ethz.ch>
 * Last change: 2011/10/16
 *
 * This program prints a table in the console.
 * It contains bit size and number regions of the C++ base types.
 *
 *
 */


using namespace std;

#include <iostream> 
#include <climits>
#include <cfloat>

int main () {

  cout << "Typ\tBits\tWert_min\t\tWert_max" << endl;
  cout << "char\t" << sizeof(char) << '\t' << CHAR_MIN << "\t\t\t" << CHAR_MAX << endl;
  cout << "short\t" << sizeof(short) << '\t' << SHRT_MIN << "\t\t\t" << SHRT_MAX << endl;
  cout << "int\t" << sizeof(int) << '\t' << INT_MIN << "\t\t" << INT_MAX << endl;
  cout << "long\t" << sizeof(long) << '\t' << LONG_MIN << "\t" << LONG_MAX << endl;
  cout << "float\t" << sizeof(float) << '\t' << FLT_MIN << "\t\t" << FLT_MAX << endl;
  cout << "double\t" << sizeof(double) << '\t' << DBL_MIN << "\t\t" << DBL_MAX << endl;


  return 0;

}
