#include <iostream>
#include "Header.h"
using namespace std;


int main()
{
    double eps = 0.0000001;

    for (int i = 1; i <= 10; i++) {
        cout << "gaussian integral for x = " << i << ": " << gauss(i, eps) << "\n";
    }

   
    cout << "\n";
    for (int i = -5; i < 5; i++) {
        cout << "e^" << i << " taylor: " << expTaylor(i, eps) << "\n";
    }

    cout << "\n";
    for (int i = -5; i < 5; i++) {
        cout << "e^" << i << " correlation: " << expCorr(i) << "\n";
    }

}
