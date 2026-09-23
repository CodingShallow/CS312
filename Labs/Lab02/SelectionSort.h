#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <vector>

using namespace std;


void SelectionSort(vector<int>& v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        int m = i;

Labs        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[m])
            {
                m = j;
            }
        }

        if (i != m)
        {
            int temp = v[i];
            v[i] = v[m];
            v[m] = temp;
        }
    }
}

bool IsSorted(const vector<int>& v, bool d)
{
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] != v[i - 1] &&
            d != (v[i - 1] < v[i]))
        {
            return false;
        }
    }

    return true;
}

vector<int> WorstCase(int n)
{
    vector<int> v;

    for (int i = n; i >= 1; i--)
    {
        v.push_back(i);
    }

    return v;
}


long long Runtime(int n)
{
    return n * n;
}

long long ComparisonCount(int n)
{
    return (n * (n - 1)) / 2;
}

#endif