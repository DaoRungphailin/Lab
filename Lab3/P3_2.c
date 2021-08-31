#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    int count = 2*a-1;
    for (int y = 1; y <= count; y++)
    {
        for (int x = 1; x <= count; x++)
        {
            if ((x <= y || x >= count-y+1) && !(x < y && x > count-y+1))
            {
                printf("* ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    
    return 0;
}
