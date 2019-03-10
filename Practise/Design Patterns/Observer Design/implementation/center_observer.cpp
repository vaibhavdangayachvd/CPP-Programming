#include "..\\headers\\center_observer.h"
#include<iostream>
center_observer::center_observer(car *ca):observer(ca){}
void center_observer::update()
{
    int pos=get_car()->get_position();
    if(pos==0)
        std::cout<<"Moving in center lane !!\n";
}
