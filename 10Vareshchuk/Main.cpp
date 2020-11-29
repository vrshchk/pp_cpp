#include <iostream>
#include "Simpson.h"
using namespace std;

int main()
{

	double i = 1;
	double j = 2;
	cout << "simpson integral for a = " << i << "; b = " << j << ": " << simpsonTest(i, j) << endl;
	
	i = 0.1;
	j = 0.5;
	cout << "		     a = " << i << "; b = " << j << ": " << simpsonTest(i, j) << endl;

	i = 0.6;
	j = 0.8;
	cout << "		     a = " << i << "; b = " << j << ": " << simpsonTest(i, j) << endl;

	return 0;
}