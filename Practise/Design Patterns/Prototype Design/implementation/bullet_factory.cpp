#include "..\\headers\\bullet_factory.h"
#include "..\\headers\\simple_bullet.h"
#include "..\\headers\\great_bullet.h"
bullet_factory::bullet_factory(void)
{
    bullet_list[SIMPLE]=std::make_unique<simple_bullet>(100,10);
    bullet_list[GREAT]=std::make_unique<great_bullet>(20,20);
}
std::unique_ptr<bullet>bullet_factory::create_bullet(bullet_type t)
{
    return bullet_list[t]->clone();
}
