#include "MatrixFibonacci.h"
#include <iostream>
using namespace std;

int main() {
	
	for (int i = 0; i < 30; i++) {
		cout << "fib (" << i << ") : " << matrix_fib(i) << endl;
	}
	
	return 0;
}