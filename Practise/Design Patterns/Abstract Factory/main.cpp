#include<iostream>
#include<cstdlib>
#include<conio.h>
//Implementation Files
#include "implementation\\simple_car_factory.cpp"
#include "implementation\\luxury_car_factory.cpp"
#include "implementation\\car.cpp"
#include "implementation\\simple_tire.cpp"
#include "implementation\\luxury_tire.cpp"
#include "implementation\\simple_body.cpp"
#include "implementation\\luxury_body.cpp"
int main()
{
    car_factory *ptr;
    car *p;
    while(true)
    {
        system("cls");
        std::cout<<"Choose Option :-\n\n1 - Simple Car\n2 - Luxury Car\n\tBackspace - Exit\n";
        char option=getch();
        system("cls");
        switch(option)
        {
        case '1':
            ptr=new simple_car_factory();
            p=ptr->build_whole_car();
            p->show_details();
            delete p,ptr;
            getch();
            break;
        case '2':
            ptr=new luxury_car_factory();
            p=ptr->build_whole_car();
            p->show_details();
            delete p,ptr;
            getch();
            break;
        case 8:
            return 0;
        }
    }
}
