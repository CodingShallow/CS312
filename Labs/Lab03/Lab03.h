#ifndef LAB03_H
#define LAB03_H

#include <vector>
#include <cstdlib>

using namespace std;

namespace aal
{
    

template <class T>
int BinarySearch(const vector<T>& v, int s, int e, const T& target)
{
    if (s <= e)
    {
        int m = (s + e) / 2;

        if (v[m] == target)
        {
            return m;
        }

        if (v[m] < target)
        {
            return BinarySearch(v, m + 1, e, target);
        }
        else
        {
            return BinarySearch(v, s, m - 1, target);
        }
    }

    return -1;
}


/*
Binary Search Runtime 

T(n) = T(n/2) + Theta(1)

a = 1
b = 2
f(n) = Theta(1)

n^(log_b(a))
= n^(log_2(1))
= n^0
= 1

T(n) = Theta(log n)
*/


template <class T>
void Shuffle(vector<T>& v)
{
    for (int i = v.size() - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);

        T temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
}

template <class T>
void Merge(vector<T>& v, int i, int m, int j)
{
    vector<T> temp;

    int left = i;
    int right = m + 1;

    while (left <= m && right <= j)
    {
        if (v[left] <= v[right])
        {
            temp.push_back(v[left]);
            left++;
        }
        else
        {
            temp.push_back(v[right]);
            right++;
        }
    }

    while (left <= m)
    {
        temp.push_back(v[left]);
        left++;
    }

    while (right <= j)
    {
        temp.push_back(v[right]);
        right++;
    }

    for (int k = 0; k < temp.size(); k++)
    {
        v[i + k] = temp[k];
    }
    /*
Merge Runtime Analysis

Input size:

n = j - i + 1

This is the total number of elements being merged.

Runtime table:

Statement                                      Cost     Frequency
-----------------------------------------------------------------
vector<T> temp                                 1        1
int left = i                                   1        1
int right = m + 1                              1        1

while(left <= m && right <= j)                 1        at most n + 1
comparison v[left] <= v[right]                 1        at most n - 1
temp.push_back(...)                            1        at most n - 1
increment left or right                        1        at most n - 1

while(left <= m)                               1        at most n + 1
temp.push_back(v[left])                        1        at most n
left++                                         1        at most n

while(right <= j)                              1        at most n + 1
temp.push_back(v[right])                       1        at most n
right++                                        1        at most n

for loop copying temp back into v              1        n + 1
v[i + k] = temp[k]                             1        n
k++                                            1        n

All loops together process at most a constant multiple of n elements.

Therefore:

T(n) = c1 + c2n

for constants c1 and c2.

Ignoring constants:

T(n) = Theta(n)
*/
}
template <class T>
void MergeSort(vector<T>& v, int i, int j)
{
    if (i < j)
    {
        int m = (i + j) / 2;

        MergeSort(v, i, m);
        MergeSort(v, m + 1, j);

        Merge(v, i, m, j);
    }
}
/*
Merge Sort Runtime Analysis

The recurrence relation is:

T(n) = 2T(n/2) + Theta(n)

Using the Master Theorem:

T(n) = aT(n/b) + f(n)

For MergeSort:

a = 2

There are two recursive calls.

b = 2

Each recursive call receives approximately half of the original input.

f(n) = Theta(n)

The Merge() operation processes all n elements.

Therefore:

T(n) = 2T(n/2) + Theta(n)

Master Theorem:

a = 2
b = 2

n^(log_b(a))

= n^(log_2(2))

= n^1

= n

Since:

f(n) = Theta(n)

and

n^(log_b(a)) = n

this is Case 2 of the Master Theorem.

Therefore:

T(n) = Theta(n log n)
*/

} 

#endif