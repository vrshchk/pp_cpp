#include "ArraySorting.h"
#include <cassert>
#include <algorithm>
#include <iostream>
#include <time.h>
using namespace std;

void selectionSort(int a[], unsigned int n) {
    int i, j, min, temp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i + 1; j < n; j++)
            if (a[j] < a[min])
                min = j;
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void bubbleSort(int arr[], unsigned int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}


void insertionSort(int arr[], unsigned int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

bool sorted(int arr[], unsigned int n)
{
    for (unsigned int i = 1; i < n; ++i)
    {
        if (arr[i - 1] > arr[i])
            return false;
    }
    return true;
}


bool check_equalty(int a[], unsigned int a_n, int b[], unsigned int b_n)
{
    assert(a_n == b_n);
    sort(a, a + a_n);
    sort(b, b + b_n);
    for (unsigned int i = 0; i < a_n; ++i)
    {
        if (a[i] != b[i])
            return false;
    }
    return true;
}

void copy(int a[], unsigned int a_n, int b[], unsigned int b_n)
{
    if (a_n != b_n)
    {
        throw "lengths are not equal";
    }
    for (unsigned int i = 0; i < a_n; ++i)
    {
        b[i] = a[i];
    }
}

void print(int arr[], unsigned int n)
{
    for (unsigned int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void fill(int arr[], unsigned int n)
{
    srand(time(NULL));
    int m = 0;
    for (int i = 0; i < n; ++i) {
        m = (rand() % 100);
        arr[i] = m;
    }
}

void test(unsigned int n)
{
    if (n <= 0)
        throw "length <= 0\n";
    int* arr = new int[n];
    int* arr_new = new int[n];

    fill(arr, n);
    copy(arr, n, arr_new, n);

    cout << "Given array:\n";
    print(arr_new, n);

    cout << "\nSorted ";

    //cout << "(bubble sort)\n";
    //bubbleSort(arr, n);

    //cout << "(selection sort)\n";
    //selectionSort(arr, n);

    cout << "(insertion sort)\n";
    insertionSort(arr, n);

    print(arr, n);

    assert(sorted(arr, n));
    cout << "\nAssertion complete: sorted." << endl;

    assert(check_equalty(arr, n, arr_new, n));
    cout << "Assertion complete: equal.\n\n";

    cout << "Test completed successfully.\n\n\n";
    delete[] arr;
    delete[] arr_new;
}