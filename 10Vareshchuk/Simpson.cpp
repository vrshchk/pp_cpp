#include <cmath>
#include <cassert>
#include "Simpson.h"
using namespace std;


double globalA = 0;
double globalB = 0;


double Simpson(double a, double b, double(*f)(double), double eps)
{
	int n = 2;
	double h = (b - a) / 2;
	double pr = 0;
	double s1 = h * (f(a) + f(b));
	double s2 = 0;
	double s4 = 4 * h * f(a + h);
	double s = s1 + s2 + s4;

	do {
		pr = s;
		n *= 2;
		h /= 2;
		s1 /= 2;
		s2 = s2 / 2 + s4 / 4;
		s4 = 0;
		int i = 1;
		do {
			s4 = s4 + f(a + i * h);
			i += 2;
		} while (i <= n);
		s4 = 4 * h * s4;
		s = s1 + s2 + s4;
	} while (abs(s - pr) > eps);
	return s / 3;
}

double elipticIntegral(double x)
{
	double res = 1 / sqrt(globalA * globalA * sin(x) * sin(x) + globalB * globalB * cos(x) * cos(x));
	return res;
}

double limit(double a, double b)
{
	double nA = sqrt(a * b);
	double nB = (a + b) / 2.0;
	do
	{
		a = nA;
		b = nB;
		nA = sqrt(a * b);
		nB = (a + b) / 2.0;
	} while (nA > a && nB < b && nA < nB);
	return (a + b) / 2;
}


double simpsonTest(double a, double b)
{
	globalA = a;
	globalB = b;
	double integralRes = Simpson(0, PI / 2, elipticIntegral, eps);
	double limitRes = limit(a, b);
	assert(abs(1 / limitRes - 2 / PI * integralRes) < eps);
	return limitRes;
}

