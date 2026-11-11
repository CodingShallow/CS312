#ifndef RADIX_H
#define RADIX_H

#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <vector>

namespace aan
{
    std::string print(const std::vector<size_t>& A)
    {
        std::stringstream out;

        out << "[";

        for(size_t i = 0;i < A.size();i += 1)
        {
            out << A[i];

            if(i + 1 < A.size()) {out << ",";}
        }
        out << "]";
        return out.str();
    }

    size_t hash(size_t x, size_t i)
    {
        return (x / ((size_t)pow(10,i))) % 10;
    }

    void countSort(std::vector<size_t>& A, size_t i)
    {
        std::vector<size_t> B(A.size());
        std::vector<size_t> C(10);

        for(size_t j = 0;j < 10;j += 1)
        {
            C[j] = 0;
        }

        for(size_t j = 0;j < A.size();j += 1)
        {
            C[hash(A[j],i)] += 1;
        }

        for(size_t j = 1;j < 10;j += 1) 
        {
            C[j] += C[j-1];
        }

        for(size_t j = A.size();j > 0;j -= 1)
        {
            C[hash(A[j-1],i)] -= 1;
            B[C[hash(A[j-1],i)]] = A[j-1];
        }

        for(size_t j = 0;j < A.size();j += 1)
        {
            A[j] = B[j];
        }
    }

    void radixSort(std::vector<size_t>& A,size_t d)
    {
        for(size_t i = 0;i < d;i += 1)
        {
            countSort(A,i);
            std::cout << "i = " << i << ": " << print(A) << "\n";
        }
    }
}

#endif