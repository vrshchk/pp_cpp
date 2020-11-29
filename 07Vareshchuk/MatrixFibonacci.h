struct Matrix2x2
{
	int _11, _12, _21, _22;
};

struct Vector2
{
	int _1, _2;
};

Matrix2x2 matrix_to_power(Matrix2x2 m, int p);
Matrix2x2 matrix_mult(Matrix2x2 m1, Matrix2x2 m2);
Vector2 matrix_x_vect(Matrix2x2 m, Vector2 v);
int matrix_fib(int n);