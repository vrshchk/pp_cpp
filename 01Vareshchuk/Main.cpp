#include <iostream>
#include <cmath>
using namespace std;

#include "Header.h"

int main()
{
	double pi = 3.1415;

	cout << "my power: " << power(5, 2) << " ; cmath: " << pow(5, 2) << "\n";
	cout << "my power: " << power(3, 4) << " ; cmath: " << pow(3, 4) << "\n";
	cout << "my power: " << power(1, 2) << " ; cmath: " << pow(1, 2) << "\n";
	cout << "my power: " << power(4, 2) << " ; cmath: " << pow(4, 2) << "\n";

	cout << "my sin: " << sin(0.00001, 2*pi/3) << " ; cmath: " << sin(2*pi/3) << "\n";
	cout << "my sin: " << sin(0.00001, pi) << " ; cmath: " << sin(pi) << "\n";
	cout << "my sin: " << sin(0.00001, pi /2) << " ; cmath: " << sin(pi / 2) << "\n";
	cout << "my sin: " << sin(0.00001, 2*pi) << " ; cmath: " << sin(2 * pi) << "\n";

	cout << "my cos: " << cos(0.00001, 2* pi / 3) << " ; cmath: " << cos(2* pi / 3) << "\n";
	cout << "my cos: " << cos(0.00001, pi) << " ; cmath: " << cos(pi) << "\n";
	cout << "my cos: " << cos(0.00001, pi / 2) << " ; cmath: " << cos(pi / 2) << "\n";
	cout << "my cos: " << cos(0.00001, pi*2) << " ; cmath: " << cos(pi*2) << "\n";

}