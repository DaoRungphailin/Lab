#include <stdio.h>

// เอาไว้พิมพ์ตัวอักษร n ครั้ง
//        "สิ่งที่จะพิมพ์" ↴        ⤺ จำนวนครั้งที่พิมพ์
void printNtimes(char *s, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%s", s);
    }
}

int main()
{
    int i, j, x;

    printf("Enter number >> ");
    scanf("%d", &x);
    // เราจะแบ่งเป็น 3 ส่วนแทน
    // อันนี้ส่วนบน
    for (i = 1; i < x; i++)
    {
        // ในแต่ละบรรทัด * ทั้งสองฝั่งเพิ่มทีละตัวเลยใช้ i เป็นจำนวนครั้ง
        printNtimes("* ", i);

        // พิมพ์เว้นวรรคคั่นกลาง
        printNtimes("  ", x-i); // พิมพ์เว้นวรรคถึงตรงกลาง
        printNtimes("  ", x-i-1); // พิมพ์เว้นวรรคของอีกฝั่ง

        printNtimes("* ", i); // พิมพ์ * ปิดท้าย
        printf("\n");
    }

    // ส่วนกลาง
    printNtimes("* ", x); // พิมพ์ * ของฝั่งซ้าย
    printNtimes("* ", x-1); // พิมพ์ * ของฝั่งขวา
    printf("\n");

    // ส่วนล่าง
    //        ⤺ เปลี่ยนจาก x เป็น x-1
    for (i = x-1; i >= 1; i--)
    {
        printNtimes("* ", i); // พิมพ์ i ครั้งเหมือนเดิม ให้ * ลดลงเรื่อยๆ

        printNtimes("  ", x-i); // พิมพ์เว้นวรรคถึงตรงกลาง
        printNtimes("  ", x-i-1); // พิมพ์เว้นวรรคของอีกฝั่ง

        printNtimes("* ", i);
        printf("\n");
    }
    return 0;
}