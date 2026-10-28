// Tariq Shallow
// October 28, 2026

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "Lab04.h"

using namespace std;

int main()
{
    srand(time(0));

    vector<int> A(20);
    vector<int> B(20);

    // Random values in [10, 39]:
    // lower bound is not 0 and the interval contains 30 values.
    for (int i = 0; i < A.size(); i++)
    {
        A[i] = 10 + rand() % 30;
    }

    cout << "Original vector:" << endl;
    aal::Print(A);

    aal::RangedSort(A, B);

    bool sorted = true;

    for (int i = 0; i < B.size() - 1; i++)
    {
        if (B[i] > B[i + 1])
        {
            sorted = false;
        }
    }

    if (sorted)
    {
        cout << "Sorted vector:" << endl;
        aal::Print(B);
    }
    else
    {
        cout << "Error: the sort was unsuccessful." << endl;
    }

    return 0;
}
