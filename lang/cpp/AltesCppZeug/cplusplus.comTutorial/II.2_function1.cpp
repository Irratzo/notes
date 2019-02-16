// function example: kleine Kreisflaeche auf Kugel

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>


using namespace std;

#define PI 3.14159265358979



double angle (double R, double r)
{
  // if (r > 8*R) return 0; else {
  double phi;
  phi = (r*PI)/(4*R);
  return (phi); 
  // }
}

int main ()
{
  string mystR;
  string mystr;
  double bla = 0;
  double blub = 0;
  double phinow;
  double ratio;
  

  cout << "Imagine a sphere with surface S and radius R." << endl;
  cout << "Also imagine a circle with area a and radius r." << endl;
  cout << "Let r be smaller than R." << endl;
  cout << "Now imagine that you lay two such circles centered on both poles of the sphere" << endl;
  cout << "The question now is: how big is the area not covered by the two circle areas?" << endl;
  cout << "More specifically, what is the ratio of the free sphere area to the total sphere area?" << endl;
  cout << "  " << endl;
  cout << "Please enter a positive value for R." << endl;
  getline (cin, mystR);
  cout << "Now enter a positive value for r.)" << endl;
  getline (cin, mystr);

  stringstream(mystR) >> bla;
  stringstream(mystr) >> blub;
  
  phinow = angle(bla,blub);

    ratio = (8*((PI/2) * (bla * bla )-phinow*(bla * bla)))/(4*PI*(bla * bla));
  // ratio = 1-(phinow/(2*PI))*(bla*bla); //simplified, doesnt work?
  ratio = 100*ratio;
  
  if (blub<=2*bla) {
    cout << "The result: " << ratio << " \% of the sphere surface is not covered."<< endl; } else {
    cout << "The result: 100 % of the sphere surface is covered and " << (-1)*ratio << " \% of the circle area overlaps."<< endl; }


  return 0; 

}
  
