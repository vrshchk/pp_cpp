#include "Header.h"
#include "Task10.h"
#include <iostream>
#include <bitset>
using namespace std;

int main()
{

    cout << "Testing task 1: " << endl;
    /*These tests are enough to check the correctness of the simplification, 
    because we can see it`s working on negative, positive numbers and 0.*/
    cout << "If everything works correctly, 1 is expected." << endl;
    for (int i = -3; i < 3; i++) {
        cout << "for x = " << i << ": " << task1(i) << endl; //expected output is 1 for every test
    }

    cout << "\n\n";


    cout << "Testing task 2: " << endl;
    int x = 2, y = 2, n = 3;
    cout << "Result for x = " << x << ", y = " << y << ", n = " << n << ": " << task2(x, y, n);
    cout << "\n\n";


    cout << "Testing task 3: " << endl;
    /*
    Testing for different numbers and outputing it in binary form to see how bits have changed
    */
    for (unsigned int i = 0; i < 30; i+=6) {
        cout << hex << "Before: " << bitset<8>(i) << " ; After: " << bitset<8>(task3(i)) << endl;
    }
    cout << "\n\n";


    cout << "Testing task 4: " << endl;
    const char* task4_case1 = "SMALL";
    const char* task4_case2 = "bigger";
    const char* task4_case3 = "miXeDcASe";
    cout << "Before: " << task4_case1 << " ; After(to lower case): " << task4_toLowerCase(task4_case1, 5) << endl;
    cout << "Before: " << task4_case2 << " ; After(to upper case): " << task4_toUpperCase(task4_case2, 6) << endl;
    cout << "Before: " << task4_case3 << " ; After(to lower case): " << task4_toLowerCase(task4_case3, 9) << endl;
    cout << "Before: " << task4_case3 << " ; After(to upper case): " << task4_toUpperCase(task4_case3, 9) << endl;
    cout << "\n\n";

    cout << "Testing task 5: " << endl;
    myString task5_str1;
    task5_str1._ch = "testing";
    task5_str1._length = 7;
    myString task5_str2;
    task5_str2._ch = "tefting";
    task5_str2._length = 7;
    myString task5_str3;
    task5_str3._ch = "testing";
    task5_str3._length = 7;
    cout << "String1=" << task5_str1._ch << " ; string2=" << task5_str2._ch << " ; compare equality using implemented operator==: " << (task5_str1 == task5_str2 ? "true" : "false") << endl;
    cout << "Check correctness of result(1 expected): " << check_task5(task5_str1, task5_str2) << endl;
    cout << "String1=" << task5_str1._ch << " ; string2=" << task5_str3._ch << " ; compare equality using implemented operator==: " << (task5_str1 == task5_str3 ? "true" : "false") << endl;
    cout << "Check correctness of result(1 expected): " << check_task5(task5_str1, task5_str3) << endl;
    cout << "\n\n";


    cout << "Testing task 6: " << endl;
    myString task6_s1;
    task6_s1._ch = "abcdeh";
    task6_s1._length = 6;
    myString task6_s2;
    task6_s2._ch = "afcdeh";
    task6_s2._length = 5;
    myString task6_s3;
    task6_s3._ch = "abcdef";
    task6_s3._length = 6;
    myString task6_s4;
    task6_s4._ch = "";
    task6_s4._length = 0;
    cout << "String1=" << task6_s1._ch << " ; string2=" << task6_s2._ch << " ; compare them using implemented operator<: " << (task6_s1 < task6_s2 ? "true" : "false") << endl;
    cout << "Check correctness of result(1 expected): " << check_task6(task6_s1, task6_s2) << endl;
    cout << "String1=" << task6_s1._ch << " ; string2=" << task6_s3._ch << " ; compare them using implemented operator<: " << (task6_s1 < task6_s3 ? "true" : "false") << endl;
    cout << "Check correctness of result(1 expected): " << check_task6(task6_s1, task6_s3) << endl;
    cout << "String1=" << task6_s1._ch << " ; string2=" << task6_s4._ch << " ; compare them using implemented operator<: " << (task6_s1 < task6_s4 ? "true" : "false") << endl;
    cout << "Check correctness of result(1 expected): " << check_task6(task6_s1, task6_s4) << endl;
    cout << "String1=" << task6_s4._ch << " ; string2=" << task6_s3._ch << " ; compare them using implemented operator<: " << (task6_s4 < task6_s3 ? "true" : "false") << endl;
    cout << "Check correctness of result(1 expected): " << check_task6(task6_s4, task6_s3) << endl;
    cout << "\n\n";


    cout << "Testing task 7: " << endl;
    const char* task7_str1 = "abcdef";
    const char* task7_str2 = "abc";
    const char* task7_str3 = "";
    cout << "String=" << task7_str1 << " ; length = " << task7(task7_str1) << endl;
    cout << "Check correctness of result(1 expected): " << check_task7(task7_str1) << endl;
    cout << "String=" << task7_str2 << " ; length = " << task7(task7_str2) << endl;
    cout << "Check correctness of result(1 expected): " << check_task7(task7_str2) << endl;
    cout << "String=" << task7_str3<< " ; length = " << task7(task7_str3) << endl;
    cout << "Check correctness of result(1 expected): " << check_task7(task7_str3) << endl;
    cout << "\n\n";


    cout << "Testing task 8: " << endl;
    myString* strs[5];
    strs[0] = new myString{"abcdefgh", 8};
    strs[1] = new myString{ "abcdef", 6 };
    strs[2] = new myString{ "abc", 3 };
    strs[3] = new myString{ "a", 0 };
    strs[4] = new myString{ "abcd", 4 };
    cout << "Before: ";
    for (int i = 0; i < 5; i++) {
        cout << strs[i]->_ch << " ";
    }
    task8_less(strs, 5);
    cout << "\nSorted: ";
    for (int i = 0; i < 5; i++) {
        cout << strs[i]->_ch << " ";
    }
    cout << "\n\n";


    cout << "Testing task 9: " << endl;
    myString* strings[7];
    strings[0] = new myString{ "abcdefgh", 8 };
    strings[1] = new myString{ "abcdef", 6 };
    strings[2] = new myString{ "lbc", 3 };
    strings[3] = new myString{ "a", 0 };
    strings[4] = new myString{ "abcdpoder", 9 };
    strings[5] = new myString{ "abcdm", 5 };
    strings[6] = new myString{ "nbcd", 4 };
    cout << "Before: ";
    for (int i = 0; i < 7; i++) {
        cout << strings[i]->_ch << " ";
    }
    task9_sortLexicographic(strings, 7);
    cout << "\nSorted in lexicographic order: ";
    for (int i = 0; i < 7; i++) {
        cout << strings[i]->_ch << " ";
    }
    task9_sortByLength(strings, 7);
    cout << "\nSorted by length: ";
    for (int i = 0; i < 7; i++) {
        cout << strings[i]->_ch << " ";
    }
    cout << "\n\n";


    cout << "Testing task 10: " << endl;
    myString* str[7];
    str[0] = new myString{ "testing", 7 };
    str[1] = new myString{ "function", 8 };
    str[2] = new myString{ "in", 2 };
    str[3] = new myString{ "exam", 4 };
    str[4] = new myString{ "hope", 4 };
    str[5] = new myString{ "it", 2 };
    str[6] = new myString{ "works", 5 };
    cout << "Before: ";
    for (int i = 0; i < 7; i++) {
        cout << str[i]->_ch << " ";
    }
    task10_sort(str, 7);
    cout << "\nAfter sorting: ";
    for (int i = 0; i < 7; i++) {
        cout << str[i]->_ch << " ";
    }
    cout << "\n\n";
}