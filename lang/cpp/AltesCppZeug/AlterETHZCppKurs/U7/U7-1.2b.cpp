/***
 * D-ITET Informatik 1, Uebungsserie 7, Aufgabe 1.2a
 *
 * Autor: Johannes Wasmer
 * Datum: 16.11.2011
 *
 * 
 * Save the number 2.125 in binary format, output zahl.dat
 */

#include <iostream>
#include <fstream>
using namespace std;


int main (int argc, char **argv) {

  float a = 2.125;
  float read = 0.0;

  //file objects, open. switch to binary mode (>> force converts to char*))
  fstream fout ("zahl.dat", ios::out | ios::binary);
  //write takes pointer; and integer of type streamsize (size of chars of block of data to write))
  fout.write( (const char*) &a, sizeof(a) );
  fout.close();

  cout << "File written. Now printing saved value." << endl;

  //read, switch to binary read. (ios is base class for all stream classes)
  fstream fin("zahl.dat", ios::in | ios::binary);
  fin.read( (char*) &read, sizeof(read) );
  fin.close();

  cout << read << endl;

  return 0;
}
