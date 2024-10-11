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
    int A[1000];
    int k;
    std::cin >> k;

    if (k <= 1000)
    {
        for (int i = 0; i < k; i++)
        {
            std::cin >> A[i];
        }
        for (int i = 0; i < k - 1; i++)
        {
            for (int j = i + 1; j < k; j++)
            {
                if (sumDigits(A[i]) > sumDigits(A[j]))
                {
                    std::swap(A[i], A[j]);
                }
                else if (sumDigits(A[i]) == sumDigits(A[j]))
                {
                    if (maxDigit(A[i]) > maxDigit(A[j]))
                    {
                        std::swap(A[i], A[j]);
                    }
                    else if ((maxDigit(A[i]) == maxDigit(A[j])) && (A[i] > A[j]))
                    {
                        std::swap(A[i], A[j]);
                    }
                }
            }
        }
        for (int i = 0; i < k; i++)
        {
            std::cout << A[i] << " ";
        }
    }
    
    return 0;
}