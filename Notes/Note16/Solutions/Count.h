#ifndef COUNT_H
#define COUNT_H

#include <vector>

namespace aan
{
    void CountingSort(const std::vector<int>& A,std::vector<int>& B, size_t k)
    {
        std::vector<int> C(k);

        for(int i = 0;i < k;i += 1) {[i] = 0;}
        for(int i = 0;i < A.size();i += 1) {C[A[i]] += 1;}
        for(int i = 1;i < k;i += 1) {C[i] += C[i-1];}
        
        for(int i = A.size();i > 0;i -= 1)
        {
            C[A[i-1]] -= 1;
            B[C[A[i-1]]] = A[i-1];
        }
    }
}
#endif