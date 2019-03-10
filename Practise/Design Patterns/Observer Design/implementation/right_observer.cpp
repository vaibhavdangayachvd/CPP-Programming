#include "..\\headers\\right_observer.h"
#include<iostream>
right_observer::right_observer(car *ca):observer(ca){}
void right_observer::update()
{
    int pos=get_car()->get_position();
    if(pos>0)
        std::cout<<"Moving in right lane !!\n";
}
