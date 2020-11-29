#include "Header.h"
using namespace std;
#include <iostream>
#include <cmath>

double agmean(double a, double b) {
    if (a > b || a<=0 || b <=0) {
        cout << "Invalid input\n";
        return 0;
    }
    else {
        double aCurr = a;
        double bCurr = b;
        double aNext = 0;
        double bNext = 0;

        while (aNext < aCurr){
            aNext = sqrt(aCurr * bCurr);
            bNext = (aCurr + bCurr) / 2;
            aCurr = aNext;
            bCurr = bNext;
        }
        return bNext;
    }
}