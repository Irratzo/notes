/***
 * Programm Uebung 1, Aufgabe 8
 *
 * Author: Johannes Wasmer <wasmerj@student.ethz.ch>
 * Last change: 2011/10/10
 *
 * Problem description: Given is a circuit with resistances
 * R1 and R2, R3 and R4 respectively connected in series, 
 * and R1+R2, R3+R4 connected in parallel. The ersatz resistances
 * R12 and R34 are connected in parallel to R1234. The program 
 * takes values for R1,R2,R3,R4 and returns the values of R12, R34, R_tot.
 * 
 */

#include <iostream>
/* verwende die Bibliothek iostream, welche die zwei Stream cin und count enthält, die im Programm verwendet werden */

using namespace std;
/* gliedere das Programm in den namespace "std" ein. */



/**
 * Main program which takes R values from the user
 * and returns other R values.
 * 
 */
int main()

{
  double R1 = 0;  //declare variables R1-4 for input.
  double R2 = 0;
  double R3 = 0;
  double R4 = 0;
  double R12 = 0;  //declare variables for output.
  double R34 = 0; 
  double R_tot = 0;

  cout << "This program computes resistances for the pictured circuit." << endl;
  cout << "-----------------------------------------------" << endl;
  cout << "--                                           --" << endl;
  cout << "--     ----R1----R2----        R12 = R1+R2   --" << endl;
  cout << "--     |              |        R34 = R3+R4   --" << endl;
  cout << "--------              ---------              --" << endl;
  cout << "--     |              |             R12R34   --" << endl;
  cout << "--     ----R3----R4----    R_tot = --------  --" << endl;
  cout << "--                                  R12+R34  --" << endl;
  cout << "--                                           --" << endl;
  cout << "-----------------------------------------------" << endl;
  cout << "                                                           " << endl;


  cout << "Please enter value for R1 (in Ohm): " << endl;
  cin >> R1;
  cout << "Please enter value for R2 (in Ohm): " << endl;
  cin >> R2;
  cout << "Please enter value for R3 (in Ohm): " << endl;
  cin >> R3;
  cout << "Please enter value for R4 (in Ohm): " << endl;
  cin >> R4;

  R12 = R1 + R2;
  R34 = R3 + R4;
  R_tot = (R12 * R34) / (R12 + R34);

  cout << "The value of R12 is: " << R12 << " Ohm." << endl;
  cout << "The value of R34 is: " << R34 << " Ohm."<<  endl;
  cout << "The value of R_tot is: " << R_tot << " Ohm." << endl;



	return 0;
	/* Beende ds Programm ohne Fehler (mit Rückgabewert 0) */
}
