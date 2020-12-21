#include <iostream>
#include "Header.h"
using namespace std;
#include <cmath>


int main()
{
    double eps = 1e-15;
    cout.precision(15);

	//I`ve checked truthful results of gaussian integral using https://planetcalc.ru website
	double check[10] = { 0.746824132641236 , 0.882081477464788 , 0.886262080651933 , 0.885659781906668 , 0.882961063100766 ,
		0.888171709641958 ,	0.906806143187301 , 0.924804634044910 , 0.926530758686409 , 0.907177023792441 };

	//if we have x > 6 fuction calculates very wrong values
	for (double i = 1; i <= 10; i++)
	{
		cout << "Gaussian integral for x = "<< i << ": " << gauss(i, eps) << "\n";
		cout << "Expexted: " << check[(int)i-1] << "\n\n";
	}

	cout << "Testing exp functions:\n";

	//exp function using taylor series works correctly only for positive numbers
	for (double i = -2; i < 5; i += 0.5)
	{
		cout << "x = " << i << endl;
		cout << "expTaylor: " << expTaylor(i, eps) << endl;
		cout << "expCorr: " << expCorr(i, eps) << endl;
		cout << "cmath exp: " << exp(i) << endl << endl;
	}

}


