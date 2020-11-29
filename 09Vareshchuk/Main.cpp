#include <iostream>
#include "Dichotomy.h"
using namespace std;


int main()
{
	double eps = 1e-15;
	double pi = 3.14159265359;
	cout << "Solution of the sin(x)=x in the interval [-1, 1]: " << dichotomy(sin_func, - 1, 1, eps) << endl;
	cout << "Solution of the sin(x)=0 in the interval [pi-1, pi]: " << dichotomy(sin_func2, pi - 1, pi, eps) << endl;
	cout << "Solution of the ln(x)=1 in the interval [2, 3]: " << dichotomy(ln_func, 2, 3, eps) << endl;
	cout << "Solution of the exp(x)=2-x in the interval [0, 2]: " << dichotomy(exp_func, 0, 2, eps) << endl;
}
