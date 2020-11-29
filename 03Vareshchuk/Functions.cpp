#include "Header.h"
#include <math.h>
#include <cmath>

double gauss(double x, double eps) {
	double first = x;
	double result = x;
	int k = 1;
	double cur = 0;
	while (true) {
		cur = first * -1 * x * x * (2.0*k -1.0)  / (2.0*k + 1.0) / k;
		if (abs(first) < eps)
			break;
		result += cur;
		k += 1;
		first = cur;
	}
	return result;

}

double expTaylor(double x, double eps) {
	double first = 1;
	double result = 1;
	int k = 1;
	double cur = 0;
	while (true) {
		cur = first * x / k;
		if (abs(first) < eps)
			break;
		result += cur;
		k += 1;
		first = cur;
	}
	return result;
}


double expCorr(double x) {
	double e = 2.71828;
	if (x >= 0) 
	{
		int whole = (long)x;
		double fract = x - whole;
		double first = pow(e, whole);
		double second = pow(e, fract);
		return first*second;
	}
	else
	{
		double val = pow(e, -x);
		return 1 / val;
	}
}