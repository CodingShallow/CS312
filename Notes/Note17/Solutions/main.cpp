#include <iostream>
#include <string>
#include "Radix.h"

int main()
{
    std::vector<size_t> A = {415,743,747,893,706,537};
    std::vector<size_t> B = {912,758,654,499,877,636,655,301};
    std::vector<size_t> C = {597,979,476,543,245};
    std::vector<size_t> D = {486,239,403,797,790,178,129};
    std::vector<size_t> E = {601,276,211,366,922,617};
    std::vector<size_t> F = {100,200,7,88,4,64};

    std::cout << aan::print(A) << "\n";
    aan::radixSort(A,3);
    std::cout << "\n";
    
    std::cout << aan::print(B) << "\n";
    aan::radixSort(B,3);
    std::cout << "\n";    
    
    std::cout << aan::print(C) << "\n";
    aan::radixSort(C,3);
    std::cout << "\n";    
    
    std::cout << aan::print(D) << "\n";
    aan::radixSort(D,3);
    std::cout << "\n";    
    
    std::cout << aan::print(E) << "\n";
    aan::radixSort(E,3);
    std::cout << "\n";    
    
    std::cout << aan::print(F) << "\n";
    aan::radixSort(F,3);
    std::cout << "\n";
    return 0;
}