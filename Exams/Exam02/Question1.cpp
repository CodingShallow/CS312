
/*
CS 312 - Running-Time Analysis

Input size:
    n = A.size(), the number of elements in array/vector A.

Worst-case running-time table:

Let S = n + (n-1) + ... + 1 = n(n+1)/2.

Operation                       Cost    Frequency

m = A[0]                         1       1
i = 0                            1       1
while (i < A.size())             1       n + 1
s = 0                            1       n
j = i                            1       n
while (j < A.size())             1       S + n
s = s + A[j]                     1       S
if (s > m)                       1       S
m = s                            1       S   (worst case)
j = j + 1                        1       S
i = i + 1                        1       n
return m                         1       1

Running-time function:

T(n) = 1 + 1 + (n+1) + n + n + (S+n)
       + S + S + S + S + n + 1

T(n) = 5S + 5n + 4

Since S = n(n+1)/2:

T(n) = 5[n(n+1)/2] + 5n + 4
     = (5/2)n^2 + (15/2)n + 4

Therefore:

    T(n) = Theta(n^2)
*/
