// Tariq Shallow 9/16/25
#include <iostream>
#include <string>
#include <vector>

using namespace std;


void SelectionSort(vector<int>& v)
{
    for (int i = 0; i < v.size() - 1; i++)
    {
        int m = i;

        for (int j = i + 1; j < v.size(); j++)
        {
            if (v[j] < v[m])
            {
                m = j;
            }
        }

        if (i != m)
        {
            int temp = v[i];
            v[i] = v[m];
            v[m] = temp;
        }
    }
}

int main()
{
    vector<int> v = {9, 4, 7, 2, 8, 1, 6};

    SelectionSort(v);

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
        cout << "SUCCCESSSFULLLLLL" << endl;
    }

    return 0;
}
/*

Worst Case:

Line                                     Cost        Frequency
----------------------------------------------------------------
for (int i = 0; i < v.size()-1; i++)     c1          n
int m = i;                               c2          n - 1
for (int j = i+1; j < v.size(); j++)     c3          n(n-1)/2
if (v[j] < v[m])                         c4          n(n-1)/2
m = j;                                   c5          n(n-1)/2
if (i != m)                              c6          n - 1
int temp = v[i];                         c7          n - 1
v[i] = v[m];                             c8          n - 1
v[m] = temp;                             c9          n - 1


Runtime Function:

T(n) =
c1(n)
+ c2(n - 1)
+ c3[n(n - 1)/2]
+ c4[n(n - 1)/2]
+ c5[n(n - 1)/2]
+ c6(n - 1)
+ c7(n - 1)
+ c8(n - 1)
+ c9(n - 1)

largest term n^2.

T(n) = O(n^2)

*/
