// Tariq Shallow
// October 28, 2026

#ifndef LAB04_H
#define LAB04_H

#include <iostream>
#include <vector>

using namespace std;

namespace aal
{

void Range(const vector<int>& v, int& lo, int& hi)
{
    lo = v[0];
    hi = v[0];

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] < lo)
        {
            lo = v[i];
        }

        if (v[i] > hi)
        {
            hi = v[i];
        }
    }
}

void RangedSort(const vector<int>& A, vector<int>& B)
{
    int lo;
    int hi;

    Range(A, lo, hi);

    int n = A.size();
    int range = hi - lo + 1;

    B.resize(n);

    if (range <= 2 * n)
    {
        vector<int> C(range, 0);

        for (int i = 0; i < n; i++)
        {
            C[A[i] - lo]++;
        }

        for (int i = 1; i < range; i++)
        {
            C[i] = C[i] + C[i - 1];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            int shifted = A[i] - lo;
            C[shifted]--;
            B[C[shifted]] = A[i];
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            B[i] = A[i];
        }
    }
}

void Print(const vector<int>& v)
{
    cout << "[";

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];

        if (i < v.size() - 1)
        {
            cout << ", ";
        }
    }

    cout << "]" << endl;
}

}

#endif
