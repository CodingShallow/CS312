#include <iostream>
#include <string>
#include <cstdlib> //srand(), rand()
#include <ctime> //time(), difftime()
#include <vector>

//Bubble Sort
void bubble(std::vector<int>& v)
{
    int t;

    for(int i = v.size();i > 0;i -= 1)
    {
        for(int j = 1;j < i;j += 1)
        {
            if(v[j-1] > v[j])
            {
                t = v[j-1];
                v[j-1] = v[j];
                v[j] = t;
            }
        }
    }
}
/*
n = size of v
01. (10,1)
02. (12i,1)
03. (12c,n+1)
04. (14i,n)
05. (14c,sum(t=0,n-1,n-t))
06. (16,sum(t=0,n-1,n-t-1))
07. (18,sum(t=0,n-1,n-t-1))
08. (19,sum(t=0,n-1,n-t-1))
09. (20,sum(t=0,n-1,n-t-1))
10. (14m,sum(t=0,n-1,n-t-1))
11. (12m,n)

T(n) = 3n + 3 + sum(t=0,n-1,n-t) + 5sum(t=0,n-1,n-t-1)
= 3n + 3 + 6sum(t=0,n-1,n-t) - 5sum(t=0,n-1,1)
= 3n + 3 + 6sum(t=0,n-1,n) - 6sum(t=0,n-1,t) - 5sum(t=0,n-1,1)
= 3n + 3 6nsum(t=0,n-1,1) - 6sum(t=0,n-1,t) - 5sum(t=0,n-1,1)
= 3n + 3 + (6n - 5)sum(t=0,n-1,1) - 6sum(t=0,n-1,t)
= 3n + 3 + (6n - 5)n - 6[(n - 1)(n)]/2
= 3n + 3 + 6n^2 - 5n - 3n^2 + 3n 
= 3n^2 + n + 3
*/

//Insertion Sort
void insertion(std::vector<int>& v)
{
    int k;
    int j;

    for(int i = 1;i < v.size();i += 1)
    {
        k = v[i];
        j = i - 1;

        while(j >= 0 && v[j] > k)
        {
            v[j+1] = v[j];
            j -= 1;
        }
        v[j+1] = k;
    }
}
/*
n = size of v
01. (52,1)
02. (54i,1)
03. (54c,n)
04. (56,n-1)
05. (57,n-1)
06. (59,sum(t=1,n-1,t+1))
07. (61,sum(t=1,n-1,t))
08. (62,sum(t=1,n-1,t))
09. (64,n-1)

T(n) = 4n - 1 + sum(t=1,n-1,t+1) + 2sum(t=1,n-1,t)
= 4n - 1 + 3sum(t=1,n-1,t) + sum(t=1,n-1,1)
= 4n - 1 + 3[(n-1)(n)]/2 + n - 1
= (3/2)n^2 + (7/2)n - 1
*/

int main()
{
    return 0;
}