#include <iostream>
#include <math.h>
#include <Windows.h>
#include "Gnuplot.h"
#include "Sinusoida.h"
#include "Save.h"
#include "Source.h"
#include "Dft.h"
//#include "gnuplot_i.hpp"

using namespace std;

void main() {
	Gnuplot plot;
	Sinusoida sinus(1,500);
	Sinusoida my_inf(1, 500);
	Dft dft;
	Modulation mod;

	
	my_inf.probkowanie(20,0.1 , 10);
	Save::sinus(my_inf, "sin");
	plot("plot 'sin.csv' with lines");
	system("pause");
	sinus.probkowanie(1, 0.01 , 50);
	Save::sinus(sinus, "sin");
	plot("plot 'sin.csv' with lines");
	system("pause");
	mod.DisplayAM(sinus, my_inf, 0.1);
	dft.Display(mod);
	mod.DisplayPM(sinus, my_inf, 0.1);
	dft.Display(mod);
	exit(0);
}