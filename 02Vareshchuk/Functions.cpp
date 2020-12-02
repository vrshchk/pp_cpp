#include "Header.h"

#include <iostream>
using namespace std;

double power(double a, int b) {
	double res = a;
	int steps = 0;
	if (b == 0)
		res = 1;
	else {
		for (int i = 1; i < b; i++) {
			res *= a;
			steps += 1;
		}
	}
	cout << "Steps needed: " << steps << "\n";
	return res;
}

double quickPower(double a, int b) {
	int steps = 0;
	double res = 1;
	while (b > 0) {
		if (b % 2 == 1) {
			res = res * a;
		}
		a = a*a;
		b = b / 2;
		steps += 1;
	}
	cout << "Steps needed: " << steps << "\n";
	return res;
}

double recPower(double a, int b) {
	double res = 0;
	if (b != 0) 
		res = (a * recPower(a, b - 1));
	else
		res = 1;
	return res;
}