#include <iostream>
#pragma comment(lib, "..\\Debug\\SE_asm01a.lib")
using namespace std;

extern "C" 
{
    int __stdcall getmin(int*, int);
    int __stdcall getmax(int*, int);
}

int main()
{
    int intArray[10] = { 9, 6, 5, 8, 3, 4, 1, -8, 2, 12 };
    int min = getmin(intArray, sizeof(intArray) / sizeof(int));
    int max = getmax(intArray, sizeof(intArray) / sizeof(int));

    cout << "getmin + getmax = " << min + max << endl;
}

