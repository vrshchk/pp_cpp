#include "Horner.h"
#include <cassert>
#include <cmath>
#include <time.h>


void fillArray(double* coeff, size_t size)
{
    double n = 0;
    srand(time(NULL));
    for (int i = 0; i < size; ++i) {
        n = (rand() % 100 + 0);
        coeff[i] = n;
    }
    return;
}

double sum(double* coeff, size_t size, int sign)
{
    double result = 0;
    for (int i = 0; i < size; i++) {
        if (sign == 1) {
            result += coeff[i];
        }
        else {
            if (i % 2 == 0) {
                result += coeff[i];
            }
            else {
                result -= coeff[i];
            }
        }

    }
    return result;
}

double Horner(double* coeff, size_t size, double x)
{
    double result = coeff[size - 1];
    for (int i = size - 2; i >= 0; --i) {
        result *= x;
        result += coeff[i];
    }
    assert(((x == 1) || (x == -1)) ? (result == sum(coeff, size, x)) : true);
    return result;
}


double check(double* coeff, size_t size, int x)
{
    double result = coeff[0];
    for (int i = 1; i < size; ++i) {
        result += coeff[i] * pow(x, i);
    }
    return result;
}
