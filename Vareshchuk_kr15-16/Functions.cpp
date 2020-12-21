#include "Header.h"
#include <cmath>
#include <cassert>
#include <iostream>
using namespace std;


/* task1:
x + 1 will return true when x+1 != 0, so for all numbers except when x = -1 
*/
bool task1(int x) {
	return ((x = x + 1 ? 1 : 0) == (x = -1));
}


/*
Calculate the square root of 3 using chain fraction.
*/
double task2(double eps) {
	double prev = 0.0;
	double curr = 1.0;
	while (fabs(curr - prev) > eps) {
		prev = curr;
		curr = 2 + (1 / curr);
		curr = 1 + (1 / curr);
	}
	curr = 1 + (1 / curr);
	assert(fabs(curr - sqrt(3)) < eps); // using sqrt() function from cmath to check correctness of the result
	return curr;
}

/*
Calculate the square root of 3 recursively
*/
double task3(double eps) {
	double prev = 0.0;
	double curr = 1.0;
	double res = task3_help(prev, curr, eps);
	res = 1 + (1 / res);
	assert(fabs(res - sqrt(3)) < eps); // using sqrt() function from cmath to check correctness of the result
	return res;
}
double task3_help(double prev, double curr, double eps) {
	if (fabs(prev - curr) <= eps) {
		return curr;
	}
	return task3_help(curr, (1 + curr / (2 * curr + 1)), eps);
}

/*
Function to find members of the sequence a(n+3) = 3*a(n+2)-2*a(n)
a0=2
a1=-3
a2=7
Iterative method.
*/
double task4(unsigned int n, double a0, double a1, double a2, double k0, double k1, double k2) {
	if (n == 0)
		return a0;
	if (n == 1)
		return a1;
	if (n == 2)
		return a2;

	for (int i = 0; i <= n - 3; i++) {
		double curr = k2 * a2 + k1 * a1 + k0 * a0;
		a0 = a1;
		a1 = a2;
		a2 = curr;
	}
	return a2;
}

/*
Function to find members of the sequence a(n+3) = 3*a(n+2)-2*a(n)
a0=2
a1=-3
a2=7
Quick method using matrixes.
*/
double task5(unsigned int n, double a0 , double a1 , double a2 , double k0 , double k1 , double k2) {
	if (n == 0)
		return a0;
	if (n == 1)
		return a1;
	if (n == 2)
		return a2;
	Matrix t = init_matrix(3, 3);
	Matrix def = init_matrix(3, 1);
	def._mat[0][0] = a2;
	def._mat[1][0] = a1;
	def._mat[2][0] = a0;
	t._mat[0][0] = k2;
	t._mat[0][1] = k1;
	t._mat[0][2] = k0;
	t._mat[1][0] = 1;
	t._mat[1][1] = 0;
	t._mat[1][2] = 0;
	t._mat[2][0] = 0;
	t._mat[2][1] = 1;
	t._mat[2][2] = 0;
	t = my_pow(t, n-1);
	Matrix res = t * def;
	return res._mat[1][0];
}

/*
Function to find members of the sequence a(n+3) = 3*a(n+2)-2*a(n)
a0=2
a1=-3
a2=7
Quick recursive method using matrixes.
*/
double task6(unsigned int n, double a0, double a1, double a2, double k0, double k1, double k2) {
	if (n == 0)
		return a0;
	if (n == 1)
		return a1;
	if (n == 2)
		return a2;
	Matrix t = init_matrix(3, 3);
	Matrix def = init_matrix(3, 1);
	def._mat[0][0] = a2;
	def._mat[1][0] = a1;
	def._mat[2][0] = a0;
	t._mat[0][0] = k2;
	t._mat[0][1] = k1;
	t._mat[0][2] = k0;
	t._mat[1][0] = 1;
	t._mat[1][1] = 0;
	t._mat[1][2] = 0;
	t._mat[2][0] = 0;
	t._mat[2][1] = 1;
	t._mat[2][2] = 0;
	t = my_pow_rec(t, n - 1);
	Matrix res = t * def;
	return res._mat[1][0];
}


/*
Inverse bytes
--------------NOT IMPLEMENTED--------------
*/
long task7(long n, int num) {
	for (int i = (7 - num) * 8 - 1; i <= (8 - num) * 8; i++) {
		int k = (n >> i) & 0x01;
		if (k)
			n |= (k << i);
		else
			n &= (k << i);
		cout << k << endl;
	}
	return n;
}


// func to print out matrix
void print_matrix(Matrix a) {
	for (int i = 0; i < a._n; i++) {
		for (int j = 0; j < a._m; j++) {
			std::cout << a._mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

// func to init matrix with all 0
Matrix& init_matrix(const size_t& n, const size_t& m) {
	Matrix a{n, m,  new double* [n] };
	for (int i = 0; i < a._n; i++) {
		a._mat[i] = new double[m];
		for (int j = 0; j < a._m; j++) {
			a._mat[i][j] = 0;
		}
	}
	return a;
}


const Matrix& operator*(const Matrix& m, double n){
	Matrix res = init_matrix(m._n, m._m);
	for (int i = 0; i < res._n; i++) {
		for (int j = 0; j < res._m; j++) {
			res._mat[i][j] = m._mat[i][j] * n;
		}
	}
	return res;
}

const Matrix& operator*(const Matrix& m1, const Matrix& m2) {
	assert(m1._m == m2._n);
	Matrix res = init_matrix(m1._n, m2._m);
	for (int i = 0; i < res._n; i++)
		for (int j = 0; j < res._m; j++) {
			for (int k = 0; k < m2._n; k++) {
				res._mat[i][j] +=
					m1._mat[i][k] * m2._mat[k][j];
			}
		}
	return res;
}
