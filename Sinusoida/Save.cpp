#include "save.h"
#include "Dft.h"



int Save::dft(Sinusoida sinus, vector<double> dft) {
	ofstream myfile;
	myfile.open("dft.csv");
	for (unsigned int i = 0; i < sinus.ox.size(); i++)
	{
		myfile << sinus.ox[i]; myfile << "\t";
		myfile << dft[i]; myfile << "\n";
	}
	myfile.close();
	return 0;
}
int Save::sinus(Sinusoida sinus, string filename) {
	ofstream myfile;
	if (!sinus.oy.empty() && !sinus.ox.empty())
	{
		myfile.open(filename + ".csv");
		for (unsigned int i = 0; i < sinus.ox.size(); i++)
		{
			myfile << sinus.ox[i]; myfile << "\t";
			myfile << sinus.oy[i]; myfile << "\n";
		}
	}
	myfile.close();
	return 0;
}
int Save::save_vec(vector<double> ox, vector<double> oy, string filename) {
	ofstream myfile;
	myfile.open(filename);
	for (unsigned int i = 0; i < ox.size(); i++)
	{
		myfile << ox[i]; myfile << "\t";
		myfile << oy[i]; myfile << "\n";
	}
	myfile.close();
	return 0;
}
