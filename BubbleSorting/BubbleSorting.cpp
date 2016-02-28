// BubbleSorting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <memory>
#include <algorithm>
#include <vector>
#include <iterator>
#include <windows.h>

using namespace std;

void swap(int* const a, int i1, int i2)
{
    int tmp = a[i1];
    a[i1] = a[i2];
    a[i2] = tmp;
}

void BubbleSort(int* const a, int size)
{
    for (int j = size; j > 0; j--)
    {
        for (int k = 1; k < j; k++)
        {
            if (a[k] < a[k - 1])
            {
                swap(a, k, k - 1);
            }
        }
    }
}

void IsertionSort(int* const a, int size)
{
    for (int j = 1; j < size; j++)
    {
        for (int k = j; k > 0; k--)
        {
            if (a[k] <
                a[k - 1])
            {
                a[k] = a[k] + a[k - 1];
                a[k - 1] = a[k] - a[k - 1];
                a[k] = a[k] - a[k - 1];
            }
        }

    }
}


using container = vector<int>;
using const_iterator = container::const_iterator;

template <class output_iterator>
void generator(output_iterator bi, int size)
{
    for (int i = 0; i < size; ++i)
    {
        *bi++ = rand() % 100;
    }
}

void PrintArray(const_iterator b, const_iterator e)
{
    for (const_iterator i = b; i < e; ++i)
    {
        cout << *i << " ";
    }
    cout << endl;
}

bool Test_BubbleSort_Single(vector<int>& v)
{
    cout << "Input: ";
    PrintArray(v.cbegin(), v.cend());

    vector<int> v_tmp;
    v_tmp = v;

    BubbleSort(v.data(), v.size());
    sort(v_tmp.begin(), v_tmp.end());

    cout << "Output:";
    PrintArray(v.cbegin(), v.cend());

    HANDLE  hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if (v != v_tmp)
    {
        SetConsoleTextAttribute(hConsole, 12);
        cout << "Test failed.\n" << endl;
    }
    else
    {
        SetConsoleTextAttribute(hConsole, 10);
        cout << "Test passed.\n" << endl;
    }

    SetConsoleTextAttribute(hConsole, 7);
    return true;
}

void Test_BubbleSort()
{
    for (int i = 4; i < 20; ++i)
    {
        vector<int> v;
        generator(back_inserter(v), i);
        Test_BubbleSort_Single(v);
        cout << endl;
    }

    vector<int> v_sorted{ 0,1,2,3,4,5,6,7,8,9 };
    Test_BubbleSort_Single(v_sorted);
    cout << endl;

    vector<int> v_back_sorted{ 9,8,7,6,5,4,3,2,1,0 };
    Test_BubbleSort_Single(v_back_sorted);
    cout << endl;
}

int main()
{
    Test_BubbleSort();

    return 0;
}

