#include <iostream>
using namespace std;
#include "ArraySorting.h"

int main()
{
    for (int i = 0; i < 15; ++i)
    {
        try
        {
            cout << "   Testing on array of length " << i << ":\n\n";
            test(i);
        }
        catch (char const* err)
        {
            cout << err << endl;
        }
    }
}
