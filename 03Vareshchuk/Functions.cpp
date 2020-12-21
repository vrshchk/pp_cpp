#include "Header.h"
#include <math.h>
#include <cmath>


double gauss(double x, double eps) {
	double first = x;
	double result = x;
	int k = 1;
	double cur = 0;
	while (true) {
		cur = first * -1 * x * x * (2.0 * k - 1.0) / (2.0 * k + 1.0) / k;
		if (abs(first) < eps)
			break;
		result += cur;
		k += 1;
		first = cur;
	}
	return result;
}

double expTaylor(double x, double eps) {
	double result = 1.0;
	double first = 1.0;
	int k = 1;
	while (first >= eps)
	{
		first = first * x / k++;
		result += first;
	}
	return result;
}

double my_pow(double x, int n)
{
	double res = 1;
	double curr = x;
	while (n != 0)
	{
		if (n % 2 == 0)
		{
			curr *= curr;
			n /= 2;
		}
		else
		{
			res *= curr;
			curr *= curr;
			n = (n - 1) / 2;
		}
	}
	return res;
}

double expCorr(double x, double eps) {
	const double e = 2.71828182845904;
	double whole = 0;
	double fract = 0;
	bool negative = false;
	if (x < 0)
	{
		x *= -1;
		negative = true;
	}
	whole = (int)x;
	fract = x - whole;
	double exp = my_pow(e, whole) * expTaylor(fract, eps);
	if (negative)
		exp = 1 / exp;
	return exp;
}