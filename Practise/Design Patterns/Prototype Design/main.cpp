#include<iostream>
#include<memory>
#include "implementation\\bullet.cpp"
#include "implementation\\simple_bullet.cpp"
#include "implementation\\great_bullet.cpp"
#include "implementation\\bullet_factory.cpp"
int main()
{
    std::unique_ptr<bullet_factory> bfact=std::make_unique<bullet_factory>();
    std::unique_ptr<bullet>bptr1=bfact->create_bullet(SIMPLE);
    bptr1->fire(100);
    std::unique_ptr<bullet>bptr2=bfact->create_bullet(GREAT);
    bptr2->fire(120);
    std::unique_ptr<bullet>bptr3=bfact->create_bullet(SIMPLE);
    bptr3->fire(1000);
    return 0;
}
