
using namespace std;
#include <iostream>
#include <iomanip>
#include "Header.h"

int main()
{
    while (true)
    {
        double a;
        double b;
        double precision;
        char cont;

        cout << "Enter a: ";
        cin >> a;
        cout << "Enter b: ";
        cin >> b;
        cout << "Enter precision: ";
        cin >> precision;
        double res = agmean(a, b);
        cout << "agm of " << a << " and " << b << " = " << setprecision(precision) << res << "\n\n";

        cout << "To continue using this program enter 'c': ";
        cin >> cont;
        if (cont != 'c')
            break;
    }
    return 0;
}
