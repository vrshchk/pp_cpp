#include "FunctionsHeaders.h"
#include <iostream>

double func1(int n, double x) {
	int first = 1;
	int result = 1;
	if (n == 0)
		return first;
	else {
		for (int k = 0; k < n; k++) {
			int next = first * ( -1 * x / (k+1));
			result += next;
			first = next;
		}
		return result;
	}
}


double func2(double e, double x) {
	double first = x;
	double result = x;
	int k = 1;
	double cur = 0;
	while (true) {
		cur = first * -1 * x * x / (2 * k * (2 * k + 1));
		if (abs(first) < e)
			break;
		result += cur;
		k += 1;
		first = cur;
	}
	return result;
}


double func3(int a, int b) {
	int first = a;
	int q = 0;
	while (a - b >= 0) {
		a = a - b;
		q += 1;
	}
	int m = a;
	std::cout << "result of " << first << "/" << b << " is " << q << " and " << m << "\n";
	return 0;
}

double func4(double a, double b) {
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}

double func5(int n, double x) {
	double first = 1;
	double second = x;
	double next = 0;
	if (n == 0) {
		return first;
	}
	else if (n == 1) {
		return second;
	}
	else {
		for (int i = 0; i < n; i++) {
			next = 2 * x * second - first;
			first = second;
			second = next;
		}
		return next;
	}
}


