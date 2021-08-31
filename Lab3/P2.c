#include <stdio.h>
int main()
{
    int n, m = 0;
    for (n = 1; n <= 10000; n++)
    {
        for (int i = 1; i <= (n - 1); i++)
        {
            if (n % i == 0)
            {
                m += i;
            }
        }

        if (n == m)
        {
            printf("%d ", m);
        }
        m = 0;
    }

    return 0;
}