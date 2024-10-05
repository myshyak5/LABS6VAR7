#include <iostream>

int sumDigits(int s)
{
    int sum_digits = 0;

    while (s > 0)
    {
        sum_digits += s % 10;
        s /= 10;
    }

    return sum_digits;
}

int maxDigit(int m)
{
    int max_digit = 0;

    while (m > 0)
    {
        int digit_now = m % 10;
        if (digit_now > max_digit)
        {
            max_digit = digit_now;
        }
        m /= 10;
    }

    return max_digit;
}

int main()
{
    int A[10000];
    int j;
    std::cin >> j;

    if (j <= 10000)
    {
        for (int i = 0; i < j; i++)
        {
            A[i] = i + 1;
        }
        for (int k = 0; k < j - 1; k++)
        {
            for (int kk = k + 1; kk < j; kk++)
            {
                if (sumDigits(A[k]) > sumDigits(A[kk]))
                {
                    std::swap(A[k], A[kk]);
                }
                else if (sumDigits(A[k]) == sumDigits(A[kk]))
                {
                    if (maxDigit(A[k]) > maxDigit(A[kk]))
                    {
                        std::swap(A[k], A[kk]);
                    }
                    else if ((maxDigit(A[k]) == maxDigit(A[kk])) && (A[k] > A[kk]))
                    {
                        std::swap(A[k], A[kk]);
                    }
                }
            }
        }
    }

    return 0;
}