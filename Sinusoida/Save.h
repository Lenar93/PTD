#pragma once
#include "Sinusoida.h"
class Save
{
public:
	static int dft(Sinusoida sinus, vector<double>);
	static int sinus(Sinusoida sinus, string filename);
	static int save_vec(vector<double> ox, vector<double> oy, string filename);
};

