#ifndef BULLET_FACTORY_H
#define BULLET_FACTORY_H
#include<map>
#include<memory>
#include "..\\abstract\\bullet.h"
enum bullet_type{SIMPLE,GREAT};
class bullet_factory
{
    std::map<bullet_type,std::unique_ptr<bullet>>bullet_list;
public:
    bullet_factory(void);
    std::unique_ptr<bullet>create_bullet(bullet_type t);
};
#endif // BULLET_FACTORY_H
