using namespace std;

#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdlib>


int main (int argc, char** argv) {

  //declare variables
  int Eint = atoi(argv[1]); //atoi() (cstdlib) converts string to int
  double E = 0;
  double O1 = atof(argv[2]); //atof() (") converts string to double
  double O2 = atof(argv[3]);
  double MP = (O1 + O2)/2.0;
  double xB1 = 0.0;
  double xB2 = 0.0;
  double yB1 = 0.0;
  double yB2 = 0.0;
  double distance = 0.0;

  //file objects
  ofstream fout;
  //  ifstream fin;

  //file opening
  fout.open("columns.dat");

  if (!fout.is_open()) {
    cout << "File open error \n";
    return 1;
  }

  //  cout << "O1 = " << O1 << ", O2 = " << O2 << ", MP = " << MP << endl;

  //compute
  for (int i=0; i < Eint; i++) {

    E = double(i);

    if (E == 0.0) {
      xB1 = 0.0; yB1 = 0.0; xB2 = 0.0; yB2 = 0.0; }
    else {
    xB1 = (E + MP * MP / E) / (MP / E + E / O1);
    yB1 = (-1.0 * E / O1 * xB1 + E);
    
    xB2 = (E + MP * MP / E) / (MP / E + E / O2);
    yB2 = (-1.0 * E / O2 * xB2 + E);
    }

    distance = sqrt((xB1 - xB2) * (xB1 - xB2) + (yB1 - yB2) * (yB1 - yB2));
    //  cout << "E = " << E << ", xB1 = " << xB1 << ", yB1 = " << yB1 <<  ", xB2 = " << xB2 << ", yB2 = " << yB2 << ", distance = " << distance << endl;

    //write file
 fout << E << ' ' << distance << endl;
   
  }

  //close file
  fout.close();

  return 0;

} 


//OLD: f(0) != 0, f'(x) negative: WRONG
// int main (int argc, char** argv) {

//   //declare variables
//   int y_B = atoi(argv[1]); //atoi() (cstdlib) converts string to int
//   double y_Bd = 0;
//   double x_O1 = atof(argv[2]); //atof() (") converts string to double
//   double x_O2 = atof(argv[3]);
//   double x_MP = (x_O1 + x_O2)/2.0;
//   double x_O1i = 0.0;
//   double x_O2i = 0.0;
//   double y_O1i = 0.0;
//   double y_O2i = 0.0;
//   double dist_i = 0.0;

//   //file objects
//   ofstream fout;
//   //  ifstream fin;

//   //file opening
//   fout.open("columns.dat");

//   if (!fout.is_open()) {
//     cout << "File open error \n";
//     return 1;
//   }

//   //compute
//   for (int i=0; i<y_B; i++) {

//     y_Bd = double(i);

//     x_O1i = (x_O1 * (y_Bd*y_Bd + x_MP*x_MP)) / (x_MP * x_O1 + y_Bd*y_Bd);
//     x_O2i = (x_O1 * (y_Bd*y_Bd + x_MP*x_MP)) / (x_MP * x_O2 + y_Bd*y_Bd);

//     y_O1i = (-1.0 * y_Bd * (y_Bd*y_Bd + x_MP*x_MP) + y_Bd * (y_Bd*y_Bd + x_MP * x_O1)) / (x_MP * x_O1 + y_B*y_B);
//     y_O2i = (-1.0 * y_Bd * (y_Bd*y_Bd + x_MP*x_MP) + y_Bd * (y_Bd*y_Bd + x_MP * x_O2)) / (x_MP * x_O2 + y_B*y_B);

//     dist_i = sqrt((x_O1i - x_O2i)*(x_O1i - x_O2i) + (y_O1i - y_O2i)*(y_O1i - y_O2i));


//     // cout << ints[i] << ' ' << doubles[i] << endl;
//     //write file
//  fout << i << ' ' << dist_i << endl;
   
//   }

//   //close file
//   fout.close();

//   return 0;

// } 
