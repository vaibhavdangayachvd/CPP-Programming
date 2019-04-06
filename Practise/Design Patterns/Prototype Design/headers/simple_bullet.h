#ifndef SIMPLE_BULLET_H
#define SIMPLE_BULLET_H
#include "..\\abstract\\bullet.h"
#include<memory>
class simple_bullet:public bullet
{
public:
    simple_bullet(int s,int w);
    std::unique_ptr<bullet>clone(void);
};
#endif // SIMPLE_BULLET_H
