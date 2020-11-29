#include <iostream>
#include "ArraySorting.h"
#include <time.h>
using namespace std;
#include <algorithm>

int main()
{
	srand(time(NULL));
	int n = 0;
	for (int i = 0; i < 10; i++) {
		int size = (rand() % 100 + 0);
		int* arr = new int[size];
		int* selectionArr = arr;
		int* bubbleArr = arr;
		int* insertionArr = arr;

		for (int j = 0; j < size; ++j) {
			n = (rand() % 100 + 0);
			arr[j] = n;
		}
		cout << "Given array: ";
		for (int k = 0; k < size; k++) {
			cout << arr[k] << " ";
		}
		cout << "\n";

		sort(arr, arr+size);
		selectionSort(selectionArr, size);
		bubbleSort(bubbleArr, size);
		insertionSort(insertionArr, size);

		cout << "Default sorting: ";
		for (int k = 0; k < size; k++) {
			cout << arr[k] << " ";
		}
		cout << "\n";

		cout << "Selection sorting: ";
		for (int k = 0; k < size; k++) {
			cout << selectionArr[k] << " ";
		}
		cout << "\n";

		cout << "Bubble sorting: ";
		for (int k = 0; k < size; k++) {
			cout << bubbleArr[k] << " ";
		}
		cout << "\n";

		cout << "Insertion sorting: ";
		for (int k = 0; k < size; k++) {
			cout << insertionArr[k] << " ";
		}
		cout << "\n\n";
	}

}