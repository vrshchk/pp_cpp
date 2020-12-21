using namespace std;
#include <iostream>
#include <cassert>
#include "Header.h"

int main()
{
    double eps = 1.0e-12;

    cout << "Testing task 1: " << endl;
    /*These tests are enough to check the correctness of the simplification,
    because we can see it`s working on negative, positive numbers and 0.*/
    cout << "If everything works correctly, 1 is expected." << endl;
    for (int i = -3; i < 3; i++) {
        cout << "for x = " << i << ": " << task1(i) << endl; //expected output is 1 for every test
    }

    cout << "\n------------------------------------------------------------------------------------\n";

    cout << "Testing task 2:" << endl;
    cout << "Square root of 3 using chain fraction = " << task2(eps);

    cout << "\n------------------------------------------------------------------------------------\n";

    cout << "Testing task 3:" << endl;
    cout << "Square root of 3 using chain fraction (recursive) = " << task3(eps);

    cout << "\n------------------------------------------------------------------------------------\n";

    cout << "Testing task 4:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "n(" << i << "): " << task4(i) << endl;
    }

    cout << "\n------------------------------------------------------------------------------------\n";

    cout << "Testing task 5:" << endl;
    for (int i = 0; i < 10; i++) {
        double res = task5(i);
        assert(fabs(res - task4(i)) < eps);
        cout << "n(" << i << "): " << res << endl;

    }

    cout << "\n------------------------------------------------------------------------------------\n";

    cout << "Testing task 6:" << endl;
    for (int i = 0; i < 10; i++) {
        double res = task6(i);
        assert(fabs(res - task4(i)) < eps);
        cout << "n(" << i << "): " << res << endl;
    }
    
    cout << "\n------------------------------------------------------------------------------------\n";

    cout << "Testing task 8:" << endl;
    Matrix a = { 3, 3, new double* [3] };
    a._mat[0] = new double[3];
    a._mat[1] = new double[3];
    a._mat[2] = new double[3];
    a._mat[0][0] = 1;
    a._mat[0][1] = 2;
    a._mat[0][2] = 3;
    a._mat[1][0] = 4;
    a._mat[1][1] = 5;
    a._mat[1][2] = 6;
    a._mat[2][0] = 7;
    a._mat[2][1] = 8;
    a._mat[2][2] = 9;

    cout << "Given matrix:\n";
    print_matrix(a);
    Matrix c = a * 3;
    cout << "\nResult of multiplication this matrix by 3:\n";
    print_matrix(c);

    c = a * (-6);
    cout << "\nResult of multiplication this matrix by -6:\n";
    print_matrix(c);

    cout << "\n------------------------------------------------------------------------------------\n";

    cout << "Testing task 9:" << endl;
    Matrix a1 = { 3, 3, new double* [3] };
    a1._mat[0] = new double[3];
    a1._mat[1] = new double[3];
    a1._mat[2] = new double[3];
    a1._mat[0][0] = 2;
    a1._mat[0][1] = -3;
    a1._mat[0][2] = 1;
    a1._mat[1][0] = 0;
    a1._mat[1][1] = 7;
    a1._mat[1][2] = 2;
    a1._mat[2][0] = 1;
    a1._mat[2][1] = 0;
    a1._mat[2][2] = 2;

    c = a * a1;
    cout << "\nFirst given matrix:\n";
    print_matrix(a);
    cout << "\nSecond given matrix:\n";
    print_matrix(a1);
    cout << "\nResult of multiplication:\n";
    print_matrix(c);


    Matrix b = { 3, 2, new double* [3] };
    b._mat[0] = new double[2];
    b._mat[1] = new double[2];
    b._mat[2] = new double[2];
    b._mat[0][0] = 1;
    b._mat[0][1] = 0;
    b._mat[1][0] = 1;
    b._mat[1][1] = 0;
    b._mat[2][0] = 1;
    b._mat[2][1] = 0;

    c = a * b;
    cout << "\n\nFirst given matrix:\n";
    print_matrix(a);
    cout << "\nSecond given matrix:\n";
    print_matrix(b);
    cout << "\nResult of multiplication:\n";
    print_matrix(c);

    cout << "\n------------------------------------------------------------------------------------\n";

    cout << "Testing task 10:" << endl;
    cout << "Given matrix:\n";
    print_matrix(a1);
    cout << "\nThis matrix in power of 2:\n";
    c = my_pow(a1, 2);
    print_matrix(c);
    cout << "\nThis matrix in power of 5:\n";
    c = my_pow(a1, 5);
    print_matrix(c);

    // tasks 8, 9, 10 were checked using http://ua.onlinemschool.com/math/assistance/matrix/ website.
}
