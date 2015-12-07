#include "Modulation.h"
#include "Save.h"

Modulation::Modulation(){}
void Modulation::AM(Sinusoida syg_nos, Sinusoida syg_inf, double kam) {
	out_x.clear(); out_y.clear();
	for (unsigned int i = 0; i < syg_nos.ox.size(); i++) {
		out_x.push_back(syg_nos.ox[i]);
		out_y.push_back((1 + syg_inf.oy[i] * kam)*sin((2 * M_PI*syg_nos.F*i) / syg_nos.Fs + syg_nos.Angle));
	}
}

void Modulation::PM(Sinusoida syg_nos, Sinusoida syg_inf, double kpm) {
	out_x.clear(); out_y.clear();
	for (unsigned int i = 0; i < syg_nos.ox.size(); i++) {
		out_x.push_back(syg_nos.ox[i]);
		out_y.push_back(sin(((2 * M_PI*syg_nos.F*i) / syg_nos.Fs + syg_nos.Angle))+syg_inf.oy[i]*kpm);
	}
}
void Modulation::DisplayAM(Sinusoida syg_nos, Sinusoida syg_inf, double kam) {
	Gnuplot plot;
	AM(syg_nos, syg_inf, kam);
	Save::save_vec(out_x, out_y, "am.csv");
	plot("plot 'am.csv' with lines");
	system("pause");
}
void Modulation::DisplayPM(Sinusoida syg_nos, Sinusoida syg_inf, double kpm) {
	Gnuplot plot;
	PM(syg_nos, syg_inf, kpm);
	Save::save_vec(out_x, out_y, "pm.csv");
	plot("plot 'pm.csv' with lines");
	system("pause");
}

