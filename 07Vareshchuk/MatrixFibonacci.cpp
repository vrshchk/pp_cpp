#include "MatrixFibonacci.h"

Matrix2x2 matrix_mult(Matrix2x2 m1, Matrix2x2 m2) {
	Matrix2x2 res = { m1._11 * m2._11 + m1._12 * m2._21 , m1._11 * m2._12 + m1._12 * m2._22,
					 m1._21 * m2._11 + m1._22 * m2._21 , m1._21 * m2._12 + m1._22 * m2._22 };
	return res;
}

Matrix2x2 matrix_to_power(Matrix2x2 m, int p) {
	Matrix2x2 res = { 1, 0, 0, 1 };
	while (p > 0) {
		if (p % 2==0) {
			m = matrix_mult(m, m);
			p /= 2;
		}
		else {
			res = matrix_mult(res, m);
			p -= 1;
		}
	}
	return res;
}

Vector2 matrix_x_vect(Matrix2x2 m, Vector2 v) {
	Vector2 res = { m._11 * v._1 + m._12 * v._2 , m._21 * v._1 + m._22 * v._2 };
	return res;
}

int matrix_fib(int n) {
	if (n == 0 || n == 1) {
		return n;
	}
	Matrix2x2 m = { 1, 1, 1, 0 };
	m = matrix_to_power(m, n);
	Vector2 v = { 1, 0 };
	v = matrix_x_vect(m, v);
	return v._2;
}

