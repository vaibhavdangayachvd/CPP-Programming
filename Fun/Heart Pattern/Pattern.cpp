#include<iostream>
#include<conio.h>
void delay(void)
{
    for(long i=0;i<30000000;++i);
}
int main()
{
    for(int i=0;i<3;++i)
    {
        for(int j=0;j<2-i;++j)
        {
            std::cout<<"  ";
            delay();
        }
        for(int j=0;j<4+2*i;++j)
        {
            std::cout<<"* ";
            delay();
        }
        for(int j=0;j<5-2*i;++j)
        {
            std::cout<<"  ";
            delay();
        }
        for(int j=0;j<4+2*i;++j)
        {
            std::cout<<"* ";
            delay();
        }
        std::cout<<std::endl;
    }
    for(int i=0;i<9;++i)
    {
        for(int j=0;j<i;++j)
        {
            std::cout<<"  ";
            delay();
        }
        if(i==1)
        {
            std::cout<<"L O V E  Y O U  M U S K A N\n";
            continue;
        }
        for(int j=0;j<17-2*i;++j)
        {
            std::cout<<"* ";
            delay();
        }
        std::cout<<std::endl;
    }
    getch();
    return 0;
}
