#include "..\\headers\\great_bullet.h"
#include<iostream>
great_bullet::great_bullet(int s,int w):bullet(s,w){}
std::unique_ptr<bullet>great_bullet::clone(void)
{
    return std::make_unique<great_bullet>(*this);
}
