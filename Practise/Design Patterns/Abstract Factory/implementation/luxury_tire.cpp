#include "..\\headers\\luxury_tire.h"
luxury_tire::luxury_tire(void)
{
    name="Luxury Tire";
    pressure=100;
}
std::string luxury_tire::get_name(void)
{
    return name;
}
int luxury_tire::get_pressure(void)
{
    return pressure;
}
