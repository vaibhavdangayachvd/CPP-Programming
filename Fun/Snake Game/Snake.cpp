#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<cmath>
#include <windows.h>
bool is_over;
int max_x=30,max_y=20;
int pos_x,pos_y;
int fruit_x,fruit_y;
enum{LEFT,RIGHT,UP,DOWN};
int curr_direction=LEFT;
int score=3;
int prev_x[100],prev_y[100];
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}
int octalToDecimal(int octalNumber)
{
    int decimalNumber = 0, i = 0, rem;
    while (octalNumber != 0)
    {
        rem = octalNumber % 10;
        octalNumber /= 10;
        decimalNumber += rem * pow(8, i);
        ++i;
    }
    return decimalNumber;
}
void start()
{
    is_over=false;
    pos_x=max_x/2;
    pos_y=max_y/2;
    fruit_x=octalToDecimal(rand())%(max_x-1);
    fruit_y=octalToDecimal(rand())%(max_y-1);

}
void draw()
{
    gotoxy(pos_x,pos_y);
    switch(curr_direction)
    {
    case LEFT:
        std::cout<<"<";
        break;
    case RIGHT:
        std::cout<<">";
        break;
    case UP:
        std::cout<<"^";
        break;
    case DOWN:
        std::cout<<"V";
        break;
    }
    for(int i=0;i<score;++i)
    {
        gotoxy(prev_x[i],prev_y[i]);
        std::cout<<"o";
    }
    gotoxy(fruit_x,fruit_y);
    std::cout<<"F";
}
void logic()
{
    for(int i=3;i<score;++i)
            if(prev_x[i]==pos_x && prev_y[i]==pos_y)
                is_over=true;
    gotoxy(prev_x[score-1],prev_y[score-1]);
    std::cout<<" ";
    for(int i=score-1;i>=0;--i)
    {
        if(i==0)
        {
            prev_x[i]=pos_x;
            prev_y[i]=pos_y;
            break;
        }
        prev_x[i]=prev_x[i-1];
        prev_y[i]=prev_y[i-1];
    }
    if(pos_x==max_x-1)
        is_over=true;
    else if(pos_x==1)
        is_over=true;
    else if(pos_y==max_y-1)
        is_over=true;
    else if(pos_y==0)
        is_over=true;
    switch(curr_direction)
    {
    case UP:
        pos_y--;
        break;
    case DOWN:
        pos_y++;
        break;
    case RIGHT:
        pos_x++;
        break;
    case LEFT:
        pos_x--;
        break;
    }
    if(pos_x==fruit_x && pos_y==fruit_y)
    {

        while(pos_x==fruit_x && pos_y==fruit_y || !fruit_x || !fruit_y)
        {
            fruit_x=octalToDecimal(rand())%(max_x-1);
            fruit_y=octalToDecimal(rand())%(max_y-1);
            for(int i=0;i<score;++i)
                if(fruit_x==prev_x[i] && fruit_y==prev_y[i])
                    fruit_x=pos_x,fruit_y=pos_y;
        }
        score++;
        gotoxy(8,20);
        std::cout<<score;
        if(score==(max_x-1)*(max_y-1)-1)
        {
            gotoxy(8,21);
            std::cout<<"You Win !!";
            is_over=true;
        }
    }
}
void input()
{
    if(kbhit())
    {
        char ch=getch();
        switch(ch)
        {
        case 'a':
            if(curr_direction!=RIGHT)
                curr_direction=LEFT;
            break;
        case 's':
            if(curr_direction!=UP)
            curr_direction=DOWN;
            break;
        case 'w':
            if(curr_direction!=DOWN)
                curr_direction=UP;
            break;
        case 'd':
            if(curr_direction!=LEFT)
                curr_direction=RIGHT;
            break;
        }
    }
}
void sleep(void)
{
    if(curr_direction==LEFT || curr_direction==RIGHT)
        for(long i=0;i<50000000;++i);
    else
        for(long i=0;i<80000000;++i);
}
void draw_field(void)
{
    for(int i=0;i<max_y;++i)
    {
        for(int j=0;j<max_x;++j)
        {
            if(!i || i==max_y-1 || !j || j==max_x-1)
                std::cout<<"#";
            else
                std::cout<<" ";
        }
        std::cout<<std::endl;
    }
    std::cout<<"Score : "<<score;
}
int main()
{
    gotoxy(30,10);
    std::cout<<"Press Enter to Play";
    getch();
    system("cls");
    start();
    draw_field();
    while(!is_over)
    {
        draw();
        input();
        logic();
        sleep();
    }
    gotoxy(0,22);
    return 0;
}
