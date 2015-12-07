#pragma once
#define _USE_MATH_DEFINES
#include <string>
#include <cmath>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

class Sinusoida
{
public:
	Sinusoida();
	Sinusoida(double fs, double t);
	
	void probkowanie(double amplitude, double freq, double ph);
	vector<double> ox;
	vector<double> oy;

	double T;
	double Fs;
	double F;
	double A;
	double Angle;
	double N;
	
};

