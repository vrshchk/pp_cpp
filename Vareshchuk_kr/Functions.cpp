#include "Header.h"
#include <cassert>
#include <cctype>
#include <cstring>
#include <algorithm>

/* task1:
Check if simplfied version of x = x = 0 ? 1 : 0 is equal to x = 0
*/
bool task1(int x) {
	return ((x = x = 0 ? 1 : 0) == (x = 0));
}

/*task2:
creating arrays of x and y values and recurrently calculate these values. 
Then looping through arrays, multiply x and y and add result to final sum.
I haven`t implemented basic reccurent function, because in that case we have to calculate square root of the number and it would not work efficiently.
That`s why I use two arrays to store our values.
*/
int task2(int x, int y, unsigned int n) {
	int* x_arr = new int[n + 1];
	int* y_arr = new int[n + 1];
	int first_x = x;
	int first_y = y;
	x_arr[0] = first_x;
	y_arr[n] = first_y;
	for (int i = 1; i <= n; i++) {
		x_arr[i] = x_arr[i-1] * x_arr[i-1];
		y_arr[n - i] = y_arr[n - i + 1] * y_arr[n - i + 1];
	}
	int res = 0;
	for (int i = 0; i <= n; i++) {
		res += x_arr[i] * y_arr[i];
	}
	return res;
}


/*task3:
Using bitwise logic operator ~ to change 0 bits to 1 and 1 to 0
*/
unsigned int task3(unsigned int x) {
    unsigned int res = ~x;
    assert((res + 1 + x) == 0);
    return res;
}




/*task4:
For lowercase letters are 97-122 and for uppercase - 65-92.
So looping through characters, we check whether its >= 97 and <= 122.
If this gives us true - it means that we have lowercase letter and if false - uppersase.
If we want the letter to be in lowercase - we add to it 32, and if we want it to be uppercase - we subtract 32.

Moreover, I`ve implemented checking the correctness of the result by comparing it to result of tolower()/toupper() functions taken from <cctype>
*/
char* task4_toLowerCase(const char* str, int length) {
	char* res = new char[length + 1];
	for (int i = 0; i < length; i++) {
		if (str[i] >= 97 && str[i] <= 122) {
			res[i] = str[i];
		}
		else {
			res[i] = str[i] + 32;
		}
	}
	res[length] = '\0';
	assert(strcmp(res, check_toLower(str, length)) == 0);
	return res;
}

char* task4_toUpperCase(const char* str, int length) {
	char* res = new char[length + 1];
	for (int i = 0; i < length; i++) {
		if (str[i] >= 97 && str[i] <= 122) {
			res[i] = str[i] - 32;
		}
		else {
			res[i] = str[i];
		}
	}
	res[length] = '\0';
	assert(strcmp(res, check_toUpper(str, length)) == 0);
	return res;
}

char* check_toLower(const char* str, int length) {
	char* res = new char[length + 1];
	for (int i = 0; i < length; i++) {
		res[i] = tolower(str[i]);
	}
	res[length] = '\0';
	return res;
}

char* check_toUpper(const char* str, int length) {
	char* res = new char[length + 1];
	for (int i = 0; i < length; i++) {
		res[i] = toupper(str[i]);
	}
	res[length] = '\0';
	return res;
}



/*task 5:
Firstly compare lengths and if lengths are not equal  - return false, else
looping through characters and comparing them.
*/

bool operator== (myString& str1, myString& str2) {
	if (str1._length != str2._length)
		return false;
	for (int i = 0; i < str1._length; ++i)
		if (str1._ch[i] != str2._ch[i])
			return false;
	return true;
}
//Checking correctness of result using strcmp() function implemented in cstring. if strings are equal, strcmp() should return 0.
bool check_task5(myString& str1, myString& str2) {
	return ((strcmp(str1._ch, str2._ch) == 0) == (str1 == str2));
}


/*task 6:
Firstly compare lengths and if length of first string is 0 - return true, if length of second is 0 - return false.
In other case looping through characters (number of loops is minimum length of given strings), and comparing symbols.
And if we still haven`t returned anything, we check if length of the first string is minimum and if it`s true, returning true.
If not return false.
*/
bool operator< (myString& str1, myString& str2) {
	if (str1._length == 0) {
		return true;
	}
	if (str2._length == 0) {
		return false;
	}
	for (int i = 0; i < std::min(str1._length, str2._length); ++i) {
		if (tolower(str1._ch[i]) > tolower(str2._ch[i]))
			return false;
		if (tolower(str1._ch[i]) < tolower(str2._ch[i]))
			return true;
	}
	if (str1._length == std::min(str1._length, str2._length)) {
		return true;
	}
	return false;
}
//Checking correctness of result using strcmp() function implemented in cstring. strcmp() should return value < 0 if first string is < than second.
bool check_task6(myString& str1, myString& str2) {
	return ((strcmp(str1._ch, str2._ch) < 0) == (str1 < str2));
}


/*task 7:
In loop we take first character on which indicates the pointer,
and after that step by step increasing the pointer by 1, until reach 0.
*/
unsigned int task7(const char* ch) {
	unsigned int n;
	for (n = 0; *ch++; n++);
	return n;
}
//Checking correctness of result using strlen() function.
bool check_task7(const char* ch) {
	return (strlen(ch) == task7(ch));
}


/*task 8:
bubble sorting strings given by their lengths
*/
void task8_less(myString** strs, int length) {
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - 1 - i; j++) {
			if ((*strs[j])._length > (*strs[j + 1])._length) {
				myString* k = strs[j];
				strs[j] = strs[j + 1];
				strs[j + 1] = k;
			}
		}
	}
}


/*task 9:
bubble sorting strings in lexicographic order and by length
*/
void task9_sortLexicographic(myString** strs, int length) {
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - 1 - i; j++) {
			if (*strs[j+1] < *strs[j]) {
				myString* k = strs[j];
				strs[j] = strs[j + 1];
				strs[j + 1] = k;
			}
		}
	}
}

void task9_sortByLength(myString** strs, int length) {
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - 1 - i; j++) {
			if ((*strs[j])._length > (*strs[j + 1])._length) {
				myString* k = strs[j];
				strs[j] = strs[j + 1];
				strs[j + 1] = k;
			}
		}
	}
}
