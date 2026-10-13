// Tariq Shallow
// October 13, 2026

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "Lab03.h"

using namespace std;

int main()
{
    srand(time(0));

    vector<int> v;

    for (int i = 1; i <= 40; i++)
    {
        v.push_back(i);
    }

    aal::Shuffle(v);

    cout << "Shuffled vector:" << endl;
    cout << "{";

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];

        if (i < v.size() - 1)
        {
            cout << ", ";
        }
    }

    cout << "}" << endl;

    aal::MergeSort(v, 0, 39);

    bool sorted = true;

    for (int i = 0; i < v.size() - 1; i++)
    {
        if (v[i] > v[i + 1])
        {
            sorted = false;
        }
    }

    if (sorted)
    {
        cout << "Sorted vector:" << endl;
        cout << "{";

        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];

            if (i < v.size() - 1)
            {
                cout << ", ";
            }
        }

        cout << "}" << endl;
    }
    else
    {
        cout << "Error: vector was not sorted correctly." << endl;
    }

    return 0;
}