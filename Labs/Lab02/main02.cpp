#include <iostream>
#include <string>
#include <vector>

#include "SelectionSort.h"

using namespace std;


int main()
{
    int n = 10;

    vector<int> v = WorstCase(n);


    cout << "Worst-case array:" << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    cout << endl;


    if (IsSorted(v, true))
    {
        cout << "Array is already sorted in ascending order." << endl;
    }
    else
    {
        cout << "Array is not sorted in ascending order." << endl;
    }


    SelectionSort(v);


    cout << endl;
    cout << "After Selection Sort:" << endl;

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }

    cout << endl;


    if (IsSorted(v, true))
    {
        cout << "Array is sorted correctly." << endl;
    }
    else
    {
        cout << "Array is NOT sorted correctly." << endl;
    }


    cout << endl;
    cout << "Runtime verification:" << endl;

    cout << "n = " << n << endl;

    cout << "Number of Selection Sort comparisons: "
         << ComparisonCount(n) << endl;

    cout << "Simplified runtime n^2: "
         << Runtime(n) << endl;


    cout << endl;
    cout << "Quadratic growth:" << endl;

    cout << "n = 10: " << Runtime(10) << endl;
    cout << "n = 20: " << Runtime(20) << endl;
    cout << "n = 40: " << Runtime(40) << endl;


    return 0;
}