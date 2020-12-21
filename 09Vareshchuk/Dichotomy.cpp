#include "Dichotomy.h"
#include <math.h>
#include <cassert>

double sin_func(double x)
{
	return sin(x) - x;
}
double sin_func2(double x)
{
	return sin(x);
}
double ln_func(double x)
{
	return log(x) - 1;
}
double exp_func(double x)
{
	return exp(x) - 2 + x;
}

double dichotomy(double (*f)(double), double a, double b, double eps)
{
	double res = a;
	while (f(res) > eps || f(res) < -eps)
	{
		if (f(a) < f(b))
		{
			if (f(res) > eps)
			{
				b = res;
				res -= (res - a) / 2;
			}
			else {
				a = res;
				res += (b - res) / 2;
			}
		}
		else
		{
			if (f(res) > eps)
			{
				a = res;
				res += (b - res) / 2;
			}
			else
			{
				b = res;
				res -= (res - a) / 2;
			}
		}
	}
	return res;
}