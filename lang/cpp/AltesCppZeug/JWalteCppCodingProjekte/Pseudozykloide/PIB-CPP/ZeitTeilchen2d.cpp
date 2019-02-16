#include <iostream>  // cout
#include <fstream>   // ofstream
#include <cmath>     // exp()
#include <complex>   // complex()
#include <stdlib.h>  // system()

//////////////////////////////////////////////////
// GENERIC CONFIG

using namespace std;
complex<double> i(0., 1.);
double PI = 3.1415926535897932384626433832795;
double h = 6.62606896e-34; 
double hbar = h/(2*PI);
double m = 9.10938188*1e-31;

//////////////////////////////////////////////////
// USER CONFIG

double T = 1;				// total runtime
const int TSTEPS = 200;			// time steps (resolution)
double L = 1;				// box length
const int XSTEPS = 25;			// x length steps (resolution)
const int YSTEPS = 25;			// y length steps (resolution)
const int MINEIGF = 1000;			// lowest eigen function
int MAXEIGF = 1005;			// highest eigen function

double REFRESHTIME = 0.02;	// gnuplot refresh h//////////////////////////////////////////////////
// HELPERS

inline double E(int k) { return h*h * k*k / (8*L*L*m); }
inline double c(int k) { k = 1; return 1; }
inline double phi(int k, double x) { return sqrt(2/L) * sin(PI*k/L * x); }
inline complex<double> theta(int k, double t) { return exp(-i*E(k)/hbar * t); }

inline complex<double> PsiK(int k, double x, double t) {
	return c(k) * (phi(k, x)*complex<double>(1.,0)) * theta(k, t);
}

//////////////////////////////////////////////////
// MAIN

int main() {

	double maxprob = 1e-30;
	double frame[TSTEPS][XSTEPS][YSTEPS];
	for(int t = 0; t < TSTEPS; ++t) {
		for(int x = 0; x < XSTEPS; ++x) {
		for(int y = 0; y < YSTEPS; ++y) {

			complex<double> Psi(0., 0.);
			for(int k = MINEIGF; k <= MAXEIGF; ++k)
				Psi += PsiK(k, x*(L/XSTEPS), t*(T/TSTEPS) * (8*m*L*L)/(h*(MINEIGF+((MAXEIGF-MINEIGF))/2)) )
				    +  PsiK(k, y*(L/YSTEPS), t*(T/TSTEPS) * (8*m*L*L)/(h*(MINEIGF+((MAXEIGF-MINEIGF))/2)) ); 
			Psi *= conj(Psi);
			frame[t][x][y] = real(Psi);

			if(frame[t][x][y] > maxprob) maxprob = frame[t][x][y];

		}
		}

		// "correct" scaling doesn't work
/*		double integ = 0;
		for(int x = 0 ; x < XSTEPS; ++x)
			integ += frame[t][x];
		integ *= L/XSTEPS;

		for(int x = 0; x < XSTEPS; ++x)
			frame[t][x] /= integ;
*/
	}

	// fake scaling
	for(int t=0; t<TSTEPS; ++t)
		for(int x=0; x<XSTEPS; ++x)
		for(int y=0; y<YSTEPS; ++y)
			frame[t][x][y] /= maxprob * 1;  // dirty stretching :o

/*	for(int t=0; t<TSTEPS; ++t) {
		double integ = 0;
		for(int x = 0 ; x < XSTEPS; ++x)
		for(int y=0; y<YSTEPS; ++y)
			integ += frame[t][x][y];
		cout << integ << "   ";
	}
*/

	ofstream data("DATA");
	for(int x=0; x<XSTEPS; ++x) {
	for(int y=0; y<YSTEPS; ++y) {
		data << x * (L/XSTEPS) << "\t" << y * (L/YSTEPS);
		for(int t=0; t<TSTEPS; ++t)
			data << "\t" << frame[t][x][y];
		data << "\n";
	}
	data << "\n";
	}
	data.close();

//////////////////////////////////////////////////
// GNUPLOT CONFIGURATION

	ofstream gnuplotf("gnuplot.conf");
	gnuplotf << "\
# Plotting data in file 'DATA' using commands from 'gnuplot.frames'\n\
set   autoscale                        # scale axes automatically\n\
unset log                              # remove any log-scaling\n\
unset label                            # remove any previous labels\n\
set xtic auto                          # set xtics automatically\n\
set ytic auto                          # set ytics automatically\n\
set zrange [0.0:1.0]\n\
set title 'Particle in a box'\n\
set xlabel 'position in [0,L]'\n\
set ylabel 'position in [0,L]'\n\
set zlabel 'probability'\n\
set hidden3d\n\
set dgrid3d 25,25,2\n\
load 'gnuplot.frames'\n\
";
	gnuplotf.close();

	ofstream framef("gnuplot.frames");
	for(int t=3; t<=TSTEPS+2; ++t)
		framef << "splot 'DATA' using 1:2:"<< t << " "
			   << "title 'sum of probabilities' "
			   << "ps 0.3 lw 2 with lines; pause "<< REFRESHTIME <<";\n";
	framef.close();

	int foo = system("gnuplot gnuplot.conf");
  foo = 0;

	return 0;
}
