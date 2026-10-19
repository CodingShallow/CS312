#ifndef QUICK_H
#define QUICK_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

namespace aan
{
    //last element as the pivot
    template <typename T>
    void Partition(std::vector<T>& A,int lo, int hi)
    {
        T p = A[hi];
        int j = lo - 1;

        for(int i = lo;i < hi; i += 1)
        {
            if(A[i] < p)
            {
                j += 1;
                T t = A[j];
                A[j] = A[i];
                A[i] = t;
            }
        }
        A[hi] = A[j+1];
        A[j+1] = p;
        return (j+1);
    }

    /*
    A = [36,8,42,27,14,29], lo = 0, hi = 5, p = 29
    1. A = [36,8,42,27,14,29], j = -1 , i = 0
    2. A = [36,8,42,27,14,29], j = -1 , i = 1
    3. A = [8,36,42,27,14,29], j = 0 , i = 2
    4. A = [8,36,42,27,14,29], j = 0 , i = 3
    5. A = [8,27,42,36,14,29], j = 1 , i = 4
    6. A = [8,27,14,36,42,29], j = 2 , i = 5
    7. A = [8,27,14,29,42,36]
    */

    template <typename T>
    void QuickSort(std::vector<T>& A, int lo, int hi)
    {
        if(lo < hi)
        {
            int r = Partition(A,lo,hi);
            QuickSort(A,lo,r-1);
            QuickSort(A,r+1,hi);
        }
    }
    /*
    A = [36,8,42,27,14,29]
    1. r = 3, A = [8,27,14,29,42,36]
    2. r = 1, A = [8,14,27,29,42,36]
    3. r = 4, A = [8,14,27,29,36,42]
    */

    template <typename T>
    int RandomizePartition(std::vector<T>& A, int lo,int hi)
    {
        int p = lo + (rand() % (hi - lo + 1)); // 0 .. (hi - lo) => lo .. hi
        T t = A[p];
        A[p] = A[hi];
        A[hi] = t;
        return Partition(A,lo,hi); 
    }

    template <typename T>
    void RandomizeQuickSort(std::vector<T>& A, int lo, int hi)
    {
        if(lo < hi)
        {
            int r = RandomizePartition(A,lo,hi);
            RandomizeQuickSort(A,lo,r-1);
            RandomizeQuickSort(A,r+1,hi);
        }
    }
}

#endif