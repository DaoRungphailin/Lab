#include <stdio.h>
int main()
{
    int input, change, total = 0;
    scanf("%d", &input);
    for (int i = input; i >= 1; i /= 10)
    {
        change = i % 10;
        total += change;
        if (total >= 10 && i < 10)
        {
            i = total * 10;
            total = 0;
        }
    }
    printf("%d ", total);
    return 0;
}