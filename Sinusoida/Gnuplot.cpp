#include "gnuplot.h"
using namespace std;
Gnuplot::Gnuplot() {
	gnuplotpipe = _popen("gnuplot", "w");

	if (!gnuplotpipe) {
		cerr << ("Gnuplot not found !");
	}
}
Gnuplot::~Gnuplot() {
	fprintf(gnuplotpipe, "exit\n");
	_pclose(gnuplotpipe);
}
void Gnuplot::operator()(const string & command) {
	fprintf(gnuplotpipe, "%s\n", command.c_str());
	fflush(gnuplotpipe);
};