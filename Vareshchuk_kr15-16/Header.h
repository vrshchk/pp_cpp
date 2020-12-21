bool task1(int x);

double task2(double eps);

double task3(double eps);

double task3_help(double prev, double curr, double eps);

double task4(unsigned int n, double a0 = 2, double a1 = -3, double a2 = 7, double k0 = -2, double k1 = 0, double k2 = 3);

double task5(unsigned int n, double a0 = 2, double a1 = -3, double a2 = 7, double k0 = -2, double k1 = 0, double k2 = 3);

double task6(unsigned int n, double a0 = 2, double a1 = -3, double a2 = 7, double k0 = -2, double k1 = 0, double k2 = 3);

long task7(long n, int num);


struct Matrix
{
	size_t _n;
	size_t _m;
	double** _mat;
};

void print_matrix(Matrix a);
Matrix& init_matrix(const size_t& n, const size_t& m);

const Matrix& operator*(const Matrix& m, double n);
const Matrix& operator*(const Matrix& m1, const Matrix& m2);

template <typename T>
T my_pow(T arg, unsigned int pow) {
	T res = arg;
	pow--;
	while (pow > 0)
	{
		if (pow % 2 == 0)
		{
			pow /= 2;
			arg = arg * arg;
		}
		else
		{
			res = res * arg;
			pow--;
		}
	}
	return res;
}


template <typename T>
T my_pow_rec(T arg, unsigned int pow) {
	T res = arg;
	pow--;
	return my_pow_help(arg, pow, res);
}


template <typename T>
T my_pow_help(T arg, unsigned int pow, T res) {
	if (pow == 0) {
		return res;
	}
	if (pow % 2 == 0)
	{
		return my_pow_help(arg * arg, pow / 2, res);
	}
	else
	{
		return my_pow_help(arg, pow-1, res*arg);
	}
}

