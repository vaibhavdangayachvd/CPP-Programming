#ifndef GREAT_BULLET_H
#define GREAT_BULLET_H
#include "..\\abstract\\bullet.h"
#include<memory>
class great_bullet:public bullet
{
public:
    great_bullet(int s,int w);
    std::unique_ptr<bullet>clone(void);
};
#endif // GREAT_BULLET_H
