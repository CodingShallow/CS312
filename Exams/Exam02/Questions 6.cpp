#include <iostream>
#include <vector>
using namespace std;

/*
CS 312 - Quicksort Trace

Caller:
Quicksort([87,99,23,76,85,98,40,46,61,27,52], 0, 10)

Last-element pivot version of Partition().
Only one step is recorded after each Partition() call that
changes the array.

Trace:

a) [23,40,46,27,52,98,99,87,61,76,85]
b) [23,27,46,40,52,98,99,87,61,76,85]
c) [23,27,40,46,52,98,99,87,61,76,85]
d) [23,27,40,46,52,61,76,85,98,99,87]
e) [23,27,40,46,52,61,76,85,87,99,98]
f) [23,27,40,46,52,61,76,85,87,98,99]

Final sorted array:
[23,27,40,46,52,61,76,85,87,98,99]
*/

void PrintArray(const vector<int>& A)
{
    cout << "[";

    for (size_t i = 0; i < A.size(); i++)
    {
        cout << A[i];

        if (i + 1 < A.size())
            cout << ",";
    }

    cout << "]" << endl;
}

int Partition(vector<int>& A, int p, int r)
{
    int pivot = A[r];
    int i = p - 1;

    for (int j = p; j < r; j++)
    {
        if (A[j] <= pivot)
        {
            i++;
            swap(A[i], A[j]);
        }
    }

    swap(A[i + 1], A[r]);

    return i + 1;
}

void Quicksort(vector<int>& A, int p, int r)
{
    if (p < r)
    {
        vector<int> before = A;

        int q = Partition(A, p, r);

        if (A != before)
            PrintArray(A);

        Quicksort(A, p, q - 1);
        Quicksort(A, q + 1, r);
    }
}

int main()
{
    vector<int> A = {87,99,23,76,85,98,40,46,61,27,52};

    cout << "Quicksort trace:" << endl;

    Quicksort(A, 0, 10);

    cout << "\nFinal sorted array:" << endl;
    PrintArray(A);

    return 0;
}
