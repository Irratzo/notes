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

double T = 5;				// total runtime
const int TSTEPS = 1000;			// time steps (resolution)
double L = 1;				// box length
const int XSTEPS = 200;			// length steps (resolution)
int MINEIGF = 10;			// lowest eigen function
int MAXEIGF = 15;			// highest eigen function
// Interesting Intervals: [10,15] [100,105] [1000,1005] [1000,1300]

double REFRESHTIME = 0.02;	// gnuplot refresh time

//////////////////////////////////////////////////
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

	double maxprob = 1e-30, integ = 0;
	double frame[TSTEPS][XSTEPS];
	for(int t = 0; t < TSTEPS; ++t) {
		for(int x = 0; x < XSTEPS; ++x) {

			complex<double> Psi(0., 0.);
			for(int k = MINEIGF; k <= MAXEIGF; ++k)
				Psi += PsiK(k, x*(L/XSTEPS), t*(T/TSTEPS) * (8*m*L*L)/(h*(MINEIGF+((MAXEIGF-MINEIGF))/2)) );
			Psi *= conj(Psi);
			frame[t][x] = real(Psi);

			if(frame[t][x] > maxprob) maxprob = frame[t][x];

		}

		// "correct" scaling
		integ = 0;
		for(int x = 0 ; x < XSTEPS; ++x)
			integ += frame[t][x];
		integ *= L/XSTEPS;

		for(int x = 0; x < XSTEPS; ++x)
			frame[t][x] /= integ;

	}
    maxprob /= integ;  // all integs should be the same anyway

	// fake scaling
	//~ for(int t=0; t<TSTEPS; ++t)
		//~ for(int x=0; x<XSTEPS; ++x)
			//~ frame[t][x] /= maxprob;
/*
	for(int t=0; t<TSTEPS; ++t) {
		double integ = 0;
		for(int x = 0 ; x < XSTEPS; ++x)
			integ += frame[t][x];
		cout << integ << "   ";
	}
*/

    for(int t=0; t<TSTEPS; ++t)
        frame[t][XSTEPS-1] = 0;   // cheating for nicer filled plots
	ofstream data("DATA");
	for(int x=0; x<XSTEPS; ++x) {
		data << x * (L/XSTEPS);
		for(int t=0; t<TSTEPS; ++t)
			data << "\t" << frame[t][x];
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
set yr [0.0:"<< 1. * maxprob <<"]\n\
set title 'Particle in a box'\n\
set xlabel 'position in [0,L]'\n\
set ylabel 'probability'\n\
load 'gnuplot.frames'\n\
";
	gnuplotf.close();

	ofstream framef("gnuplot.frames");
	for(int t=2; t<=TSTEPS+1; ++t)
		framef << "plot 'DATA' using 1:"<< t
			   //~ << "title 'sum of probabilities'"
			   //~ << " with lines; pause "<< REFRESHTIME <<";\n";
			   << " w filledcurve below lt 1 lc rgb \"#802020\" title 'sum of probabilities';"
			   << "pause "<< REFRESHTIME <<";\n";
	framef.close();

	int foo = system("gnuplot gnuplot.conf");
  foo = 0;

	return 0;
}
