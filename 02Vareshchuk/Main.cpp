#include "Header.h"

#include <iostream>
#include <chrono> 

using namespace std;

int main()
{
	using namespace std::chrono;

	time_point<system_clock> start, end;
	start = system_clock::now();
	cout << "Result for iterative power(30,431): " << power(30, 83) << endl;
	end = system_clock::now();
	duration<double> elapsed_seconds = end - start;
	time_t end_time = system_clock::to_time_t(end);
	cout << "time needed: " << elapsed_seconds.count() << "s\n\n";

	start = system_clock::now();
	cout << "Result for recursive power(30,431): " << recPower(30, 83) << endl;
	end = system_clock::now();
	elapsed_seconds = end - start;
	end_time = system_clock::to_time_t(end);
	cout << "time needed: " << elapsed_seconds.count() << "s\n\n";

	cout << "(iterative) 20 in power 51: " << power(20, 51) << "\n";

	cout << "(quick) 20 in power 51: " << quickPower(2, 51) << "\n";

	return 0;
}