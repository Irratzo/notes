/***
 * Programm Uebung 2, Aufgabe 4
 *
 * Author: Johannes Wasmer <wasmerj@student.ethz.ch>
 * Last change: 2011/10/16
 *
 * This program takes as an argument in the console
 * a number between 0 and 99.9 (with one decimal number)
 * and prints out its German verbal equivalent.
 * Example: ./U2A4.out 42.5 -> zweiundvierzig komma 5
 *
 *
 */

using namespace std;

#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>


int main (int argc, char** argv) {

  double input = atof(argv[1]);

  //ensure that 0 <= input <= 99.9 and that it only has one decimal number
  if ((0 > input) || (100 < input) || ((10*input) != (int(10*input)))) {
    cout << "Bitte um Eingabe einer Zahl zwischen 0 und 100 mit maximal einer Nachkommastelle." << endl;
    return 0;
  }

  //separate the number into magnitudes 1e1, 1e0 and 1e-1 and store them
  input *= 10; //example 98.7 -> 987.0; example 1.0 -> 10.0
  int input2 = input; //987; 10
  int tenner = input2 / 100; //9; 0
  int ones = (input2 - tenner*100) / 10; //(987 - 9*100) % 10 = 8; 1
  int decimal = (input2 - tenner*100 - ones*10); //7; 0
  int exceptions = 10*tenner+ones;

  //specify words for conversion
  string wones[] = {"null","ein","zwei","drei","vier","fünf","sechs","sieben","acht","neun"};
  string wtenners[] = {"","zehn","zwanzig","dreissig","vierzig","fünfzig","sechzig","siebzig","achtzig","neunzig"};
  string eins = "eins";
  string wexceptions[] = {"","elf","zwölf"};
  bool bexception = 0;

  string und = "und";
  string komma = " komma ";

  //place to store output after conversion for conole output
  string oones = "";
  string otenners = "";
  string odecimal = "";
  string oexceptions = "";

  //convert decimal number first because of eins exception
  if (decimal == 1) 
    odecimal = eins;
  else if (decimal == 0) 
    odecimal = wones[0];
  else {
    for (int i=2; i<10;i++) {
      if (decimal == i) {
	odecimal = wones[i];
      }
    }
  }

  //handle exceptions 11, 12 and [13,19]
  if (exceptions < 13) {
    switch (exceptions) {
    case 1:
      oexceptions = eins;
      bexception = 1;
    case 11:
      if (exceptions == 11) { //without if (if 1), it prints elf
	oexceptions = wexceptions[1]; // for unknown reasons...
	bexception = 1;}
    case 12:
      if (exceptions == 12) { //without if (if 11), it prints zwölf
	oexceptions = wexceptions[2]; // for unknown reasons...
	bexception = 1;}
    }}
  else{
    for (int i=3;i<10;i++) {
      if (exceptions == 10+i) {
	bexception = 1;
	oexceptions.append(wones[i]);
	oexceptions.append(wtenners[1]);
      }
    }
  }

  //convert all other cases and finally print on console
  if (bexception == 0) {
    for (int i=0; i<10;i++) {
      if (ones == i) 
	oones = wones[i];
      if (tenner == i)
	otenners = wtenners[i];
    }
    if (tenner == 0)
      cout << oones << otenners << komma << odecimal << endl;
    else 
      cout << oones << und << otenners << komma << odecimal << endl;
  }
  else {
    cout << oexceptions << komma << odecimal << endl;;
  }

  return 0;

}
