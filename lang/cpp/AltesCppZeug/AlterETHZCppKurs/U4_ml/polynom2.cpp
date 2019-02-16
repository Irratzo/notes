/* 
 *	Example program: Evaluation of a polynomial and its derivatives.
 *	This program reads in the value of x and the coefficients as command line arguments.
 *	It then prints out the resulting polynomial and its value.
 *      This is repeated for all non-zero derivatives of the polynomial
 *
 *   	Author: Dirk Zimmer
 *	Last modiifed: 17.10.2008
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
	int degree;
	for(int i=0; i<n; i=i+1) {
		degree = n-i-1;
		if (i>0) cout << " + ";
		cout << c[i];
		if (degree >= 1) {
			cout << "*" << x; 
			if (degree > 1) cout << "^" << degree;
		}
	}
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
	double result=0;
	double p = 1;
	for(int i=n-1; i>=0; i=i-1) {
		result = result + c[i]*p;
		p = p*x;
	}
	return result;
}

/* 
	Derivates the polynomial
	@param c: array of coefficients
	@param n: number of coefficients (at least 1)
	@return:  new number of coefficients. 
*/
int derivePolynomial(double c[], int n) 
{
	//if the degree is zero, the polynomial gets reduced to a constant of zero.
	if (n==1) {
		c[0] = 0;
	} else {
		//First, the degree is lowerd
		n	= n-1;
		//All coefficients are computed. The array is modified directly
		for(int i=0; i<n; i=i+1) {
			c[i] =  (n-i)*c[i];
		}
	}
	//The new number of coefficients (degree+1) is returned.
	return n;
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
	double x;
	int n;
	double coeffs[MAX_COEFFS];

	if (argc < 3) {
		cout << "Please enter the value and at least 1 coefficent as command line arguments" << endl;
		return 0;
	}

	x = atof(argv[1]);
	n = argc-2;
	int i;
	for(i=0; i<n; i=i+1) coeffs[i]=atof(argv[i+2]);

	int newN = n;  //auxiliary variable
	do {
		n = newN; 	//assign the current number of coefficients
		//print the polynomial
		printPolynomial(x, coeffs,n);
		//ealuate the polynomial and print the result;
		cout << " = " << evalPolynomial(x,coeffs,n) << endl;
		//take the derivative of the polynomial and store the new (degree-1) in newN
		newN = derivePolynomial(coeffs,n); 
	}	while(n>1);  //iterate as long as the degree (=n-1) is greater than zero.
	
	return 0;
}


