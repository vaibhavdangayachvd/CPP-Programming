#include<iostream>
#include<conio.h>
#include "implementation\\car.cpp"
#include "implementation\\observer.cpp"
#include "implementation\\left_observer.cpp"
#include "implementation\\right_observer.cpp"
#include "implementation\\center_observer.cpp"
int main()
{
    car *ca=new car;
    left_observer lo(ca);
    right_observer ro(ca);
    center_observer co(ca);
    std::cout<<"Choose Option\n1 - Left\n2 - Center\n3 - Right\n\tBackspace - Exit\n";
    while(1)
    {
        char option=getch();
        switch(option)
        {
        case '1':
            ca->set_position(-1);
            break;
        case '2':
            ca->set_position(0);
            break;
        case '3':
            ca->set_position(1);
            break;
        case 8:
            return 0;
        default:
            std::cout<<"Drive Carefully\n";
            break;
        }
    }
}
