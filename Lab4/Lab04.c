#include<stdio.h>
#include<math.h>
int main()
{
    float side1 , side2 , side3 , s , area ;
    scanf("%f %f %f" ,&side1 , &side2 , &side3);
    s = (side1+side2+side3)/2 ;
    area = sqrt((s*(s-side1))*(s-side2)*(s-side3)) ;
    if((side1+side2>side3) && (side1+side3>side2) && (side2+side3>side1))
    {
        printf("%f" , area);
    }
    else
    {
        printf("0");
    }
    return 0 ;
}