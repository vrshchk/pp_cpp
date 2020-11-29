#include <iostream>
#include <math.h> 
using namespace std;
#include "Functions.h"

int main()
{

    for (int i = 0; i < 20; i++) {
        cout << "Fibonaci (" << i << "):" << endl;
        cout << "recursive: " << Fibonaci(i) << "\n";
        cout << "matrix: " << Matrix_Fibonaci(i) << "\n\n";
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 15; j++) {
            cout << i << " in power " << j << ": " << power(i, j) << "\n";
            cout << "                                expected: " << pow(i, j) << "\n\n";
        }
    }
}

