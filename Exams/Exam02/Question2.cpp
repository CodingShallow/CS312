/*

Master Theorem:
    T(n) = aT(n/b) + f(n)

Compare f(n) with:
    n^(log_b(a))



T(n) = 32T(n/4) + n^2


a = 32
b = 4
f(n) = n^2

n^(log_b(a))
= n^(log_4(32))

Since:
    4^(5/2) = 32

log_4(32) = 5/2

Therefore:
    n^(log_4(32)) = n^(5/2)

    f(n) = n^2
    n^(log_b(a)) = n^(5/2)

this is Master Theorem Case 1.

Therefore:

    T(n) = Theta(n^(5/2))



T(n) = 3T(n/8) + n


a = 3
b = 8
f(n) = n

n^(log_b(a))
= n^(log_8(3))



    f(n) = n
    n^(log_b(a)) = n^0.5

Since n grows polynomially faster than n^0.5,
this is Master Theorem Case 3.


    a f(n/b)
    = 3(n/8)
    = 3n/8

Since:
    3/8 < 1

the regularity condition is satisfied.

Therefore:

    T(n) = Theta(n)


 T(n) = 27T(n/3) + 20n^3


a = 27
b = 3
f(n) = 20n^3

n^(log_b(a))
= n^(log_3(27))
= n^3

Compare:
    f(n) = 20n^3
    n^(log_b(a)) = n^3

 f(n)
has the same asymptotic growth as n^3.

 Master Theorem Case 2.


    T(n) = Theta(n^3 log n)



4. T(n) = T(n/4) + 9sqrt(n)


a = 1
b = 4
f(n) = 9sqrt(n)

n^(log_b(a))
= n^(log_4(1))
= n^0
= 1

    f(n) = 9sqrt(n)
    n^(log_b(a)) = 1

this is Master Theorem Case 3.

regularity condition

    a f(n/b)
    = 1 * 9sqrt(n/4)
    = 9sqrt(n)/2


    a f(n/b) = (1/2)f(n)

Since:
    1/2 < 1

the regularity condition is satisfied.

Therefore:

    T(n) = Theta(sqrt(n))
