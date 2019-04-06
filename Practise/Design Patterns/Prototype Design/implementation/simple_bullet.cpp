#include "..\\headers\\simple_bullet.h"
#include<iostream>
simple_bullet::simple_bullet(int s,int w):bullet(s,w){}
std::unique_ptr<bullet>simple_bullet::clone(void)
{
    return std::make_unique<simple_bullet>(*this);
}
