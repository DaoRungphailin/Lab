#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include<time.h>
#define Left 1
#define Right 2
#define Stop 3
#define on 4
#define off 5
//function//
void gotoxy(int x, int y)
{
    COORD c = { x, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
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
char cursor(int x, int y) //tell char at x,y
{
    HANDLE hStd = GetStdHandle(STD_OUTPUT_HANDLE);
    char buf[2]; COORD c = { x,y }; DWORD num_read;
    if (!ReadConsoleOutputCharacter(hStd, (LPTSTR)buf, 1, c, (LPDWORD)&num_read))
        return '\0';//nothing at x,y
    else
        return buf[0];//return ascii code
}
void draw_ship(int x, int y)
{
    gotoxy(x, y);
    setcolor(2, 4);
    printf("<-0->");
}
void draw_bullet(int x, int y)
{
    gotoxy(x, y);
    setcolor(12, 0);
    printf("^");
}
void draw_star(int x, int y)
{
    gotoxy(x, y);
    setcolor(7, 0);
    printf("*");
}
void erase_ship(int x, int y)
{
    gotoxy(x, y);
    setcolor(0, 0);
    printf("     ");
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
    int bx[5], by[5], i = 0, status[5] = { 0,0,0,0,0 };
    int sx, sy, n=1;
    int score = 0;
    srand(time(NULL));
    setcursor(0);
    draw_ship(x, y);
    do
    {
        //score
        gotoxy(75, 0);
        setcolor(7, 0);
        printf("score = %d", score);
        
        //draw ship & check key pressed
        if (_kbhit())
        {
            ch = _getch();
            if (ch == 'a')
            {
                direction = Left;
            }
            if (ch == 'd')
            {
                direction = Right;
            }
            if (ch == 's')
            {
                direction = Stop;
            }
            if (ch == ' ' && status[i] == 0)
            {
                //status = on
                status[i] = 1; //status of each bullet
                bx[i] = x + 2;
                by[i] = y;
                i++;
                if (i > 4) { i = 0; } //set bullet 5 above to 0-4 only
            }
            fflush(stdin);
        }

        //check bulllet status
        for (int i = 0; i < 5; i++)
        {
            if (status[i] == 1 && by[i] > 0)//status = on
            {
                Beep(700, 100);
                erase_bullet(bx[i], by[i]);
                if (cursor(bx[i], by[i] - 1) == '*')//bullet crash star
                {
                    Beep(700, 300);
                    erase_bullet(bx[i], --by[i]);
                    status[i] = 0; //delete bullet
                    score += 1;
                    n--;
                }
                else
                {
                    draw_bullet(bx[i], --by[i]); //bullet go up
                }
            }
            else if (by[i] <= 0)
            {
                status[i] = 0;//status = off
                erase_bullet(bx[i], by[i]);
            }
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

        //random star
            sx = 10 + rand() % 61;
            sy = 2 + rand() % 4;
            if (n <= 20 && cursor(sx, sy) != '*')
            {
                draw_star(sx, sy);
                n++;
            } 
        Sleep(100);
    } while (ch != 'x');
    return 0;
}
