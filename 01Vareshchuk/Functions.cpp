#include "Header.h"

double sin(double e, double x) {
	double first = x;
	double result = x;
	int k = 1;
	double cur = 0;
	while (true) {
		cur = first * -1 * x * x / (2 * k * (2 * k + 1));
		if (first >= 0 && first < e)
			break;
		else if (first < 0 && first * -1 < e)
			break;
		result += cur;
		k += 1;
		first = cur;
	}
	return result;
}

double cos(double e, double x)
{
	double first = 1;
	double result = 1;
	int k = 1;
	double cur = 0;
	while (true) {
		cur = first * -1 * x * x / (2 * k * (2 * k - 1));
		if (first >= 0 && first < e)
			break;
		else if (first < 0 && first * -1 < e)
			break;
		result += cur;
		k += 1;
		first = cur;
	}
	return result;
}

double power(int a, int x)
{
	if (x != 0)
		return (a * power(a, x - 1));
	else
		return 1;
}
