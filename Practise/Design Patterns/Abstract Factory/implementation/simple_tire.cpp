#include "..\\headers\\simple_tire.h"
simple_tire::simple_tire()
{
    name="Simple Tire";
    pressure=75;
}
std::string simple_tire::get_name(void)
{
    return name;
}
int simple_tire::get_pressure(void)
{
    return pressure;
}
