#include "..\\headers\\left_observer.h"
#include<iostream>
left_observer::left_observer(car *ca):observer(ca){}
void left_observer::update()
{
    int pos=get_car()->get_position();
    if(pos<0)
        std::cout<<"Moving in left lane !!\n";
}
