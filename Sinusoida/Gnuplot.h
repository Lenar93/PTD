#pragma once
#include <string>
#include <iostream>
using namespace std;
class Gnuplot {
public:
	Gnuplot();
	~Gnuplot();
	void operator ()(const string & command);
	// send any command to gnuplot
protected:
	FILE *gnuplotpipe;
};

