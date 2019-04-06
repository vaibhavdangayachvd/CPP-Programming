#include "..\\abstract\\bullet.h"
#include<iostream>
bullet::bullet(int s,int w)
{
    speed=s;
    weight=w;
}
void bullet::fire(int d)
{
    direction=d;
    std::cout<<"Bullet Speed : "<<speed<<std::endl;
    std::cout<<"Bullet Weight : "<<weight<<std::endl;
    std::cout<<"Bullet Direction : "<<direction<<std::endl<<std::endl;
}
