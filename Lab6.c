#include <stdio.h>
#include <windows.h>
#include <conio.h>
#define Left 1
#define Right 2
#define Stop 3
#define on 4
#define off 5
//function//
void gotoxy(int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void setcursor(boolean visible)
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);//set console
    CONSOLE_CURSOR_INFO lpCursor;//like define variable
    lpCursor.bVisible = visible;
    lpCursor.dwSize = 20;//text size
    SetConsoleCursorInfo(console, &lpCursor);//put the setting in 2 line above
}
void setcolor(int fg, int bg)//use set color before printf
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, bg * 16 + fg); //Attribute=Background,Foreground
}
void draw_ship(int x, int y)
{
    gotoxy(x, y);
    setcolor(2, 4);
    printf(" <-0->");
}
void draw_bullet(int x, int y)
{
    gotoxy(x, y);
    setcolor(12,0);
    printf("*");
}
void erase_ship(int x, int y)
{
    gotoxy(x, y);
    setcolor(0, 0);
    printf("      ");
}
void erase_bullet(int x, int y)
{
    gotoxy(x, y);
    setcolor(0, 0);
    printf(" ");
}
//!main//
int main()
{
    char ch = ' ';
    int x = 38, y = 20, direction = Stop;
    int bx[5], by[5], i = 0, status[5] = {0,0,0,0,0};
    setcursor(0);
    draw_ship(x, y);
    do
    {
        //draw ship & check key pressed
        if (_kbhit())
        {
            ch = _getch();
            if (ch == 'a')
            {
                direction = Left ;
            }
            if (ch == 'd')
            {
                direction = Right ;
            }
            if (ch == 's')
            {
                direction = Stop;
            }
            if (ch == ' ' && status[i]==0)
            {
                //status = on;
                status[i] = 1 ; //status of each bullet
                bx[i] = x+2;
                by[i] = y-1;
                i++;
                if (i > 4) { i = 0; } //set bullet 5 above to 0-4 only
            }
            fflush(stdin);
        }

        //check ship direction
        if (direction == Left && x != 0)
        {
            erase_ship(x, y); draw_ship(--x, y);
        }
        else if (direction == Right && x != 72)
        {
            erase_ship(x, y); draw_ship(++x, y);
        }
        else if (direction == Stop)
        {
            draw_ship(x, y);
        }

        //check bulllet status
        for(int i=0 ; i<5 ; i++)
        {
            if (status[i]==1 && by[i]>0)//status = on
            {
                erase_bullet(bx[i], by[i]);
                draw_bullet(bx[i], --by[i]); //bullet go up
            }
            else if(by[i]<=0)
            {
                status[i] = 0;//status = off
                erase_bullet(bx[i], by[i]);
            }
        }
        Sleep(200);
    } while (ch != 'x');
    return 0;
}
