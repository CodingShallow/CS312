#include <iostream>
#include <vector>
using namespace std;

void NegativeCountSort(const vector<int>& A, vector<int>& B, size_t k)
{
    
    vector<int> C(k + 1, 0);

    // Count each value
    for (size_t i = 0; i < A.size(); i++)
    {
        C[-A[i]]++;
    }

  
    B.resize(A.size());

    size_t index = 0;

    for (int value = static_cast<int>(k); value >= 1; value--)
    {
        while (C[value] > 0)
        {
            B[index] = -value;
            index++;
            C[value]--;
        }
    }
}

int main()
{
    vector<int> A = {-1, -4, -2, -1, -3, -4, -2};
    vector<int> B;

    NegativeCountSort(A, B, 4);

    cout << "Sorted: ";

    for (size_t i = 0; i < B.size(); i++)
    {
        cout << B[i] << " ";
    }

    cout << endl;

    return 0;
}