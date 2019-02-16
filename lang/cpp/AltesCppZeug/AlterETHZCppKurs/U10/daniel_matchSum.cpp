#include <stdlib.h>
#include <iostream>
using namespace std;


/* 
 * A function that solves the puzzle recurisvely (no optimization, no output).
 * The arguments of the function are:
 *   s is the number that needs to be reached
 *   f is the factor that corresponds to the current digit (1, 10, 100, ....)
 *   n is the index of the current digit
 *   c is the array of digits (c[0] is the first digit in the sequence)
 */
bool solve (int s, int f, int n, int* c)
{
  if( n < 0 ) 
    return s==0;   
  else
    return solve (s - f*c[n], 1, n-1, c) || solve (s - f*c[n], 10*f, n-1, c);
}

/*
 * A slightly optimized version that also outputs a solution (if one exists). 
 * The additional argument is the number of digits in c.
 */
bool solve_with_output (int s, int f, int n, int* c, int len)
{
  if( s < 0 ) // Stop when number s cannot be reached anymore.
    return false;
  
  if( n < 0 ) 
    return s==0;   
  else
    if( solve_with_output (s - f*c[n], 1, n-1, c, len) ||
	    solve_with_output (s - f*c[n], 10*f, n-1, c, len) )
    {
	  cout << c[n];
	  if( f == 1 && n < len-1 ) cout << " + ";
	  return true;
    } else return false;
}

int main (int argc, char* argv[]) 
{
  if( argc < 3 )
    {
      cout << "USAGE: puzzle s a_0 ... a_n" << endl;
      return -1;
    }

  // Convert input.
  int * val = new int[argc-2];
  int s = atoi (argv[1]);
  for(int i = 0; i < argc-2; i++ ) 
    {
      val[i] = atoi (argv[i+2]);
      if( !(val[i] >= 0 && val[i] <= 9) )
	{
	  cout << "Fehler: Die Sequenz muss aus Ziffern bestehen."
	       << endl;
	  delete [] val;
	  return -1;
	}
    }

  // Solve puzzle.
  if( solve_with_output (s, 1, argc-3, val, argc-2) )
    cout << endl;
  else
    cout << "Problem instance has no solution." << endl;

  // Free memory and stop program safely.
  delete [] val;
  return 0;
}


/*
 * Example runs:
 *   $ ./puzzle 734546 4 2 5 0 2 5 2 6 4 6 8 3 0 7 2 6 7 3 7 6 9 5
 *   Problem instance has no solution.
 *
 *   $ ./puzzle 134235 4 2 5 0 2 5 2 6 4 6 8 3 0 7 2 6 7 3 7 6 9 5 
 *   42 + 50252 + 6 + 46 + 83072 + 6 + 737 + 69 + 5
 */   
