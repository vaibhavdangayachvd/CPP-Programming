#include<iostream>
#include<conio.h>
#include<cstdlib>
#include<cmath>
bool is_over;
int max_x=30,max_y=20;
int pos_x,pos_y;
int fruit_x,fruit_y;
enum{LEFT,RIGHT,UP,DOWN};
int curr_direction=LEFT;
int score;
int prev_x[100],prev_y[100];
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
    system("cls");
    for(int i=0;i<max_y;++i)
    {
        for(int j=0;j<max_x;++j)
        {
            if(!i || i==max_y-1 || !j || j==max_x-1)
                std::cout<<"# ";
            else if(pos_y==i && pos_x==j)
                std::cout<<"O ";
            else if(fruit_y==i && fruit_x==j)
                std::cout<<"F ";
            else if(score)
            {
                bool found=false;
                for(int k=0;k<score;++k)
                {
                    if(prev_y[k]==i && prev_x[k]==j)
                    {
                        std::cout<<"o ";
                        found=true;
                        break;
                    }
                }
                if(!found)
                    std::cout<<"  ";
            }
            else
                std::cout<<"  ";
        }
        std::cout<<std::endl;
    }
    std::cout<<"Score : "<<score;
}
void logic()
{
    if(score>3)
    {
        for(int i=3;i<score;++i)
            if(prev_x[i]==pos_x && prev_y[i]==pos_y)
                is_over=true;
    }
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
    else if(pos_x==0)
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
        }
        score++;
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
    for(long i=0;i<1000000;++i);
}
int main()
{
    start();
    while(!is_over)
    {
        draw();
        input();
        logic();
        sleep();
    }
    return 0;
}
