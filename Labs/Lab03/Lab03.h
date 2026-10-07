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

} 

#endif