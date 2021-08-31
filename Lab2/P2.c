#include <stdio.h>
int main()
{
    int a, b ,min,j=0;
    printf("Enter first number : ");
    scanf("%d", &a);
    printf("Enter second number : ");
    scanf("%d" ,&b);
    printf("Greatest common divisor = ");
    if(a<b)
    {
       min = a ;
    }
    else
    {
        min = b ;
    }
    for (int i = min; i >= 1 && j==0; i--)
    {
        if (a % i == 0 && b % i == 0)
        {
            j = 1 ;
            printf("%d", i);
        }
    }
    return 0;
}