/***
 * D-ITET Informatik 1, Uebungsserie 7, Aufgabe 1.2a
 *
 * Autor: Johannes Wasmer
 * Datum: 16.11.2011
 *
 * 
 * Save the number 2.125 in ASCII format, output zahl.txt
 */

#include <iostream>
#include <fstream>
using namespace std;


int main (int argc, char **argv) {
  //file objects
  ofstream fout;
  ifstream fin;

  //file opening
  fout.open("zahl.txt");

  if (!fout.is_open()) {
    cout << "File open error \n";
    return 1;
  }

  float a = 2.125;

  //write file
  fout << a;

  //close file
  fout.close();

  cout << "File written. Now printing saved value." << endl;

  //read file
  fin.open("zahl.txt");
  fin >> a;
  fin.close();

  cout << a << endl;

  return 0;

}
