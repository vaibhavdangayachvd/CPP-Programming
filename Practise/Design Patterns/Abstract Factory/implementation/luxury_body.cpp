#include "..\\headers\\luxury_body.h"
luxury_body::luxury_body(void)
{
    name="Luxury Body";
    strength=100;
}
std::string luxury_body::get_name(void)
{
    return name;
}
int luxury_body::get_strength(void)
{
    return strength;
}
