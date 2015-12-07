#pragma once
#include "Sinusoida.h"
#include "Gnuplot.h"
class Modulation
{
public:
	vector<double> out_x;
	vector<double> out_y;
	Modulation();
	void DisplayAM(Sinusoida syg_nos, Sinusoida syg_inf, double kam);
	void DisplayPM(Sinusoida syg_nos, Sinusoida syg_inf, double kpm);
protected:
	void AM(Sinusoida syg_nos, Sinusoida syg_inf, double kam);
	void PM(Sinusoida syg_nos, Sinusoida syg_inf, double kpm);
};
