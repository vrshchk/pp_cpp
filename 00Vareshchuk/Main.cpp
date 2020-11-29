#include <iostream>
#include "FunctionsHeaders.h"
using namespace std;


int main() {
    cout << "function 1 for n = 2, x = 2: " << func1(2, 2) << "\n";
    cout << "function 1 for n = 3, x = 1: " << func1(3, 1) << "\n";;
    cout << "function 1 for n = 0, x = 4: " << func1(0, 4) << "\n";
    cout << "function 1 for n = 1, x = 8: " << func1(1, 8) << "\n";;
    cout << "function 1 for n = 6, x = 2: " << func1(6, 2) << "\n";;

    cout << "function 2 for e = 2, x = 2: " << func2(2, 2) << "\n";
    cout << "function 2 for e = 19 x = 0: " << func2(3,3) << "\n";
    cout << "function 2 for e = 3, x = 5: " << func2(3, 5) << "\n";
    cout << "function 2 for e = 4, x = 1: " << func2(4, 9) << "\n";
    cout << "function 2 for e = 3, x = 6: " << func2(3, 6) << "\n";
    
    func3(5, 2);
    func3(1, 6);
    func3(12, 8);
    func3(125, 7);
    func3(4, 1);

    cout << "gcd 12 and 6 = " << func4(12, 6) << "\n";
    cout << "gcd 2 and 8 = " << func4(2, 8) << "\n";
    cout << "gcd 12 and 1 = " << func4(3, 0) << "\n";
    cout << "gcd 0 and 5 = " << func4(0, 5) << "\n";
    cout << "gcd 1 and 3 = " << func4(1, 3) << "\n";

    cout << "function 5 for n = 0, x = 6: " << func5(0, 6) << "\n";
    cout << "function 5 for n = 5, x = 2: " << func5(5, 2) << "\n";
    cout << "function 5 for n = 1, x = 2: " << func5(1, 2) << "\n";
    cout << "function 5 for n = 6, x = 3: " << func5(6, 3) << "\n";
    cout << "function 5 for n = 4, x = 5: " << func5(4, 5) << "\n";

    return 0;
}