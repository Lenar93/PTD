#pragma once
#include "Sinusoida.h"
#include "Modulation.h"
#include "Save.h"
class Dft :
	public Sinusoida
{
public:
	Dft();
	~Dft();
	void Calculate_dft(Sinusoida sinus);
	void Calculate_dft(vector<double> ox, vector<double> oy);
	void Display(Sinusoida sinus);
	void Display(Modulation mod);
	vector<double> dane_dft;
};

