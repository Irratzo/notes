/*
PLEASE READ:
Description: This program computes a circular Moire pattern. It does this by writing a list of four coordinates into a file called moire.dat. The output is a list of (x1,y1,x2,y2) coordinates. So each line corresponds to the start and end point of a line in a coordinate system. The total number of lines, ie the resolution of the pattern, more precisely its size in the coordinate system is specified by the user's input when calling the program: ./moire n. Due to the four-fold symmetry of the circular Moire pattern, the total number of lines then is 4(n-1). In x,y-coordinates, the pattern lies in a range [1,n][1,n]. The output can for example be used for plotting in gnuplot or other visualization programs.
Author: Johannes Wasmer
Date: 2014-01

//Possible improvements
 */

using namespace std;

#include <iostream>
#include <fstream>
//#include <cmath>
#include <cstdlib>
#include <vector>

//function line: input coordinates x1,y1,x2,y2. Output: writes input into line of moire.dat
void line(ofstream& file, int x1, int y1, int x2, int y2) {
  //NOTE: pass ofstream object as a reference. Otherwise, copy constructor would be invoked but there is no such defined for class ofstream which would prevent compilation.

    //write file
    file << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;

}



int main (int argc, char** argv) {

  //Section1 START:
  //declare variables
  //prepare input
  int x1y2row = 1;
  int x2row = 0;
  int y1row = 2;

  int n = atoi(argv[1]); //atoi() (cstdlib) converts string to int

  //populate input
    vector< vector<int> > input(4);
    for (int i=0; i < n-1; i++){
        input[0].push_back(1);
	input[1].push_back(i+1);
	input[2].push_back(n);
	input[3].push_back(n-i);
    }
    /* Example input after population for n=9:
       1 1 1 1 1 1 1 1 1 
       1 2 3 4 5 6 7 8 9 
       9 9 9 9 9 9 9 9 9 
       9 8 7 6 5 4 3 2 1
    */

  //file object
  ofstream fout;

  //open file
  fout.open ("moire.dat");

    if(!fout.is_open()) {
      cout << "File open error \n";
      //return 1;
    }

    //SECTION1 END


    //SECTION2 START
    //Compute

    for (int j=0; j<4; j++) {
      for (int i=0; i<n-1; i++) {

      	line(fout, input[x1y2row][i], input[x2row][i], input[y1row][i], input[x1y2row][i]);
      }

      //Permute the coordinates on the input rows (see example in SECTION1). This works because of the symmetry of the circular Moire pattern.
      x1y2row = (x1y2row +1)% 4;
      x2row = (x2row +1)% 4;
      y1row = (y1row +1)% 4;
    }


    //close file
    fout.close();

  return 0;

}
