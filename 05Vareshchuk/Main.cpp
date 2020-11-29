#include <iostream>
#include <time.h>
#include "Horner.h"
using namespace std;

int main() {

    double x = 0;
    size_t size = 0;
    srand(time(NULL));

    for (int t = 0; t < 100; t++) {
        x = (rand() % 100 + 0);
        size = (rand() % 20 + 1);
        double* coeff = new double[size];
        fillArray(coeff, size);
        cout << "Horner for x = " << x << "; size = " << size << "; coeff = ";
        for (int i = 0; i < size; i++) {
            cout << coeff[i] << " ";
        }
        cout << "\n Result = " << Horner(coeff, size, x);
        cout << "\n Expected = " << check(coeff, size, x);
        cout << "\n\n";
    }
    return 0;
}
