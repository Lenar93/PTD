#include "Dft.h"
#include "Gnuplot.h"
#include <complex>


Dft::Dft()
{
	
}


Dft::~Dft()
{
}
void Dft::Calculate_dft(Sinusoida sinus) {
	int size = sinus.ox.size();
	for (int i = 0; i < size; i++)
	{
		for (int n = 0; n < size; n++)
		{
			dane_dft.push_back(sinus.oy[n] * (cos(2 * M_PI * n*i / size) - sqrt(-1)*sin(2 * M_PI*n*i / size)));
		}
	}
}
void Dft::Calculate_dft(vector<double> ox, vector<double> oy) {
	int size = ox.size();

	for (int i = 0; i < size; i++)
	{
		complex<double> y(0.0, 0.0);
		for (int n = 0; n <size; n++)
		{
			double wykladnikE = (2 * M_PI * n * i);
			y += (oy[n] * std::exp(std::complex<double>(0.0, wykladnikE / size)));
		}
		dane_dft.push_back(abs(y)/size);
	}
}
void Dft::Display(Sinusoida sinus) {
	Gnuplot plot;
	this->Calculate_dft(sinus);
	Save::dft(sinus,dane_dft);
	plot("plot 'dft.csv' with points");
	system("Pause");
}
void Dft::Display(Modulation mod) {
	Gnuplot plot;
	this->Calculate_dft(mod.out_x,mod.out_y);
	Save::save_vec(mod.out_x, dane_dft, "dft.csv");
	plot("plot 'dft.csv' with lines");
	system("Pause");
}
