#include "sinusoida.h"
#include <complex>

Sinusoida::Sinusoida() {  };
Sinusoida::Sinusoida(double fs, double t) : Fs(fs), T(t)
{
}


void Sinusoida::probkowanie(double a, double f, double ph) 
{
	A = a; F = f; Angle = ph;
	N = Fs*T;
	for (int i = 0; i < N; i++)
	{
		oy.push_back(A*sin((2 * M_PI*F*i) / Fs + Angle));
		ox.push_back(i);
	}
}

