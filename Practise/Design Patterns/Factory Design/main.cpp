#include<iostream>
#include<cstdlib>
#include<conio.h>
#include "implementation\\factory.cpp"
int main()
{
    toy *ptr;
    while(true)
    {
        system("cls");
        ptr=factory::create_toy();
        if(ptr)
            ptr->show_product();
        else
            std::cout<<"\nProduct not found !!";
        getch();
    }
    return 0;
}
