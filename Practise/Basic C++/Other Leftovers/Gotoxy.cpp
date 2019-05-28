#include<iostream>
#include "windows.h"
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
int main()
{
    for(int i=0;i<4;++i)
    {for(int j=0;j<4;++j)
            std::cout<<"-";
    std::cout<<std::endl;
    }
    gotoxy(1,1);
    std::cout<<"a";
    return 0;
}
