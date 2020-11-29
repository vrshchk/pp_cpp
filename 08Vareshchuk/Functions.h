void zet(double& y, double& x, unsigned int& k, int& count);
double power(double x, unsigned int n);
void fib(double& f1, double& f2, unsigned int n, int& count);
double Fibonaci(unsigned int n);
struct Matrix2x2
{
	int _11, _12, _21, _22;
};

struct Vector2
{
	int _1, _2;
};

void matrix_p(Matrix2x2& y, Matrix2x2& x, int& k, int& count);
Matrix2x2 matrix_to_power(Matrix2x2 m, int p);
Matrix2x2 matrix_mult(Matrix2x2 m1, Matrix2x2 m2);
Vector2 matrix_x_vect(Matrix2x2 m, Vector2 v);
double Matrix_Fibonaci(unsigned int n);
