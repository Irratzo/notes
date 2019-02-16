/* 
 *	Example program: Evaluation of a polynomial.
 *	This program reads in the value of x and the coefficients as command line arguments.
 *	It then prints out the resulting polynomial and its value.
 *
 *   	Author: Dirk Zimmer
 *	Last modiifed: 08.09.2008
*/

#include <iostream>  //imports cin and cout
#include <stdlib.h>  //imports atof that converts a c-string to a float.
#include <math.h>	 //imports further math utilities (not needed here)	
using namespace std; //makes cin and cout directly accessible.

const int MAX_COEFFS = 100; //maximum number of coefficients

/* 
	Prints the polynomial with coefficients c on cout
	@param x: value of x in the polynomial
	@param c: array of coefficients
	@param n: number of coefficients
	@return: none

*/
void printPolynomial(double x, double c[], int n) 
{
  int degree;	//this local variable stores the current degree
  for(int i=0; i<n; i=i+1) {
	  degree = n-i-1; //high degrees are stored at low index values.
	  if (i>0) cout << " + ";  	  //print "+" if necessary 
	  cout << c[i];				  //print the coefficient
	  if (degree >= 1) {		  //print x if necessary
	    cout << "*" << x; 
		if (degree > 1) cout << "^" << degree;  //print exponent if it is > 1
	  }
  }
  //The return statement is not needed here, since the function is of type void.
}

/* 
	Evaluates the polynomial and returns the result.
    @param x: value of x in the polynomial
	@param c: array of coefficients
	@param n: number of coefficients
	@return:  result of the evaluation
*/
double evalPolynomial(double x, double c[], int n) 
{
  double result=0;	//local variable for the intermediate results
  double p = 1;		//current power of x starting with x^0 = 1.

  //iterate backwards over all coefficients (from low to high)
  for(int i=n-1; i>=0; i=i-1) {

	  //add current term to the intermediate result
      result = result + c[i]*p;

	  //compute new current power
      p = p*x;		//
  }

  //Finally, return the result
  return result;	
}




/*  
  Main routine: 
  - processes the programial arguments
  - prints the polynomial
  - evaluates the polynomial and prints the result
  @param argc:  number of arguments
  @param argv:  array of arguments as c-strings
  @return:  error code (usually 0)
*/
int main(int argc, char* argv[])
{

  double x;						//variable to store the value of x
  int numCoeffs;				//variable to store the number of coefficients
  double coeffs[MAX_COEFFS];	//declare array of coefficients


  //check if the number of arguments is valid.
  if (argc < 3) {
	  //if not, return error message...
	  cout << "Please enter the value and at least 1 coefficent as command line arguments" << endl;
	  //...and quit program.
	  return 0;
  }


  //argv[0] is the program name. We don't care.
  //argv[1] is the value of x. We use atof() to convert
  x = atof(argv[1]);	
  //the number of coefficients results from the remaining arguments
  numCoeffs = argc-2;	
  //we use a for-loop to read in all the coefficients
  int i;
  for(i=0; i<numCoeffs; i=i+1) { 
	  coeffs[i]=atof(argv[i+2]);
  }


  //Now we can print the polynom by calling the function printPolynom
  printPolynomial(x, coeffs,numCoeffs);

  //...and its result
  cout << " = " << evalPolynomial(x,coeffs,numCoeffs) << endl;
  //note, that we call a function anywhere in an expression.

  //Finally, let's quit the programn
  return 0;
}


