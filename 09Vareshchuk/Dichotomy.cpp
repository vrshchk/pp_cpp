#include "Dichotomy.h"
#include <math.h>

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
	if (fabs(f(a)) < eps)
		return a;
	else if (fabs(f(b)) < eps)
		return b;

	while (fabs(b - a) > eps) {
		if (f(a) * f((a + b) / 2) <= 0)
		{
			b =(a + b) / 2;
		}
		else
		{
			a = (a + b) / 2;
		}
	}
	return a;
}
