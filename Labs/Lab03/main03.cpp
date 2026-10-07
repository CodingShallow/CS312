// Tariq Shallow
// October 7, 2026

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

#include "Lab03.h"

using namespace std;

int main()
{
    srand(time(0));

    vector<int> sorted;
    vector<int> shuffled;

    for (int i = 1; i <= 40; i++)
    {
        sorted.push_back(i);
        shuffled.push_back(i);
    }

    aal::Shuffle(shuffled);

    int target;

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter a value to search for: ";
        cin >> target;

        int resultSorted =
            aal::BinarySearch(sorted, 0, 39, target);

        int resultShuffled =
            aal::BinarySearch(shuffled, 0, 39, target);

        cout << "Sorted result: "
             << resultSorted << endl;

        cout << "Shuffled result: "
             << resultShuffled << endl;

        cout << endl;
    }

    return 0;
}