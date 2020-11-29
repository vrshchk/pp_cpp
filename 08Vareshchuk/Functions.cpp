#include "Functions.h"
#include <iostream>
using namespace std;


void zet(double& y, double& x, unsigned int& k, int& count)
{
	++count;
	if (k > 0)
	{
		if (k % 2 == 1)
		{
			y *= x; k--;
		}
		else
		{
			x *= x; k /= 2;
		};
		zet(y, x, k, count);
	}
}

double power(double x, unsigned int n)
{
	double y = 1;
	int count = 0;
	zet(y, x, n, count);
	cout << "Function called : " << count << "		";
	return y;
}



void fib(double& f1, double& f2, unsigned int n, int& count)
{
	++count;
	if (n >= 2)
	{
		double f = f2; f2 += f1; f1 = f;
		fib(f1, f2, n - 1, count);
	}
};

double Fibonaci(unsigned int n)
{
	int count = 0;
	double f0 = 0, f1 = 1;
	switch (n)
	{
	case 0:
		cout << "Function called : " << count << "		";
		return f0; break;
	case 1:
		cout << "Function called : " << count << "		";
		return f1; break;
	default:
		fib(f0, f1, n, count);
		cout << "Function called : " << count << "		";
		return f1;
	}
};



Matrix2x2 matrix_mult(Matrix2x2 m1, Matrix2x2 m2) {
	Matrix2x2 res = { m1._11 * m2._11 + m1._12 * m2._21 , m1._11 * m2._12 + m1._12 * m2._22,
					 m1._21 * m2._11 + m1._22 * m2._21 , m1._21 * m2._12 + m1._22 * m2._22 };
	return res;
}

Vector2 matrix_x_vect(Matrix2x2 m, Vector2 v) {
	Vector2 res = { m._11 * v._1 + m._12 * v._2 , m._21 * v._1 + m._22 * v._2 };
	return res;
}


void matrix_p(Matrix2x2& y, Matrix2x2& x, int& k, int& count) {
	++count;
	if (k > 0) {
		if (k % 2 == 1) {
			y = matrix_mult(y, x);
			k -= 1;
		}
		else {
			x = matrix_mult(x, x);
			k /= 2;
		}
		matrix_p(y, x, k, count);
	}
}

Matrix2x2 matrix_to_power(Matrix2x2 x, int n) {
	int count = 0;
	Matrix2x2 y = { 1, 0, 0, 1 };
	matrix_p(y, x, n, count);
	cout << "Function called : " << count << "		";
	return y;
}


double Matrix_Fibonaci(unsigned int n)
{
	Matrix2x2 m = { 1, 1, 1, 0 };
	Vector2 v = { 1, 0 };
	switch (n)
	{
	case 0:
		cout << "Function called : " << 0 << "		";
		return 0; break;
	case 1:
		cout << "Function called : " << 0 << "		";
		return 1; break;
	default:
		m = matrix_to_power(m, n);
		v = matrix_x_vect(m, v);
		return v._2;
	}
};

