struct myString {
	const char* _ch;
	int _length;
};

bool task1(int x);

int task2(int x, int y, unsigned int n);

unsigned int task3(unsigned int x);

char* task4_toLowerCase(const char* str, int length);
char* task4_toUpperCase(const char* str, int length);
char* check_toLower(const char* str, int length);
char* check_toUpper(const char* str, int length);

bool operator== (myString& str1, myString& str2);
bool check_task5(myString& str1, myString& str2);

bool operator< (myString& str1, myString& str2);
bool check_task6(myString& str1, myString& str2);

unsigned int task7(const char* ch);
bool check_task7(const char* ch);

void task8_less(myString** strs, int length);

void task9_sortLexicographic(myString** strs, int length);
void task9_sortByLength(myString** strs, int length);

