#include <stdio.h>
int main()
{
    int a, b = 2, i = 1;
    printf("Enter number : ");
    scanf("%d", &a);
    printf("Factoring Result : ");
    while (a > 1)
    {   
        while (a % b == 0)
        {
            if (i == 1)
            {
                printf("%d", b);
            }
            else
            {
                printf(" x %d", b);
            }
            a = a / b;
            b=2;
            i++;
        } 
        b++; 
    } 
    return 0;
}