#include <iostream>

bool checkDigits(int n)
{
    int digit = n % 10;

    while (n > 0)
    {
        int current_digit = n % 10;

        n /= 10;
        if (current_digit != digit)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int a[10000];
    bool sort = false;
    int j;
    std::cin >> j;

    if (j <= 10000)
    {
        for (int i = 0; i < j; i++)
        {
            a[i] = i + 1;
            if (a[i] > 9 && !checkDigits(a[i]))
            {
                sort = true;
            }
        }
        if (sort)
        {
            for (int i = 0; i < j - 1; i++)
            {
                for (int ii = i + 1; ii < j; ii++)
                {
                    if (a[ii] > a[i])
                    {
                        std::swap(a[i], a[ii]);
                    }
                }
            }
        }
    }

    return 0;
}