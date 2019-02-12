#include "..\\headers\\simple_body.h"
simple_body::simple_body(void)
{
    name="Simple Body";
    strength=75;
}
std::string simple_body::get_name(void)
{
    return name;
}
int simple_body::get_strength(void)
{
    return strength;
}
