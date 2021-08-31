#include <stdio.h>
int main()
{
    int a;
    scanf("%d", &a);
    for (int i = 1; i <= a; i++)
    {

        for (int j = 1; j <= 2*a-1 ; j++)
        {
            if (j <= i || (j>2*a-1-i)) 
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
    for(int i=a-1 ; i>=1 ; i-- )
    {
        for(int j = 1; j <= 2*a-1 ; j++)
        {
            if(i>=j || j>2*a-1-i )
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
