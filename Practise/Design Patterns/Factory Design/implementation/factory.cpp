#include "..\\headers\\factory.h"
#include "car.cpp"
#include "bike.cpp"
#include "scooter.cpp"
toy * factory::create_toy()
{
    std::cout<<"Choose Option :-\n\n1 - Create Car\n2 - Create Bike\n3 - Create Scooter\n\tBackspace - Exit\n";
    char option=getch();
    if(option==8)
        exit(0);
    system("cls");
    toy *ptr;
    switch(option-'0')
    {
    case 1:
        ptr=new car;
        break;
    case 2:
        ptr=new bike;
        break;
    case 3:
        ptr=new scooter;
        break;
    default:
        ptr=NULL;
        return ptr;
    }
    ptr->bring_parts();
    ptr->assemble();
    ptr->paint();
    ptr->apply_lable();
    return ptr;
}
