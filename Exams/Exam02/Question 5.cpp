size_t MostSignificant(const vector<size_t>& A)
{
    if (A.empty())
        return 0;

    size_t largest = A[0];

   
    for (size_t i = 1; i < A.size(); i++)
    {
        if (A[i] > largest)
            largest = A[i];
    }

  
    size_t digits = 0;

    do
    {
        digits++;
        largest /= 10;
    }
    while (largest > 0);

    return digits;
}