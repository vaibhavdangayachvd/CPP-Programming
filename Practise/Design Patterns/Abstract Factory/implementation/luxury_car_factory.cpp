#include "..\\headers\\luxury_car_factory.h"
#include "..\\headers\\luxury_body.h"
#include "..\\headers\\luxury_tire.h"
tire *luxury_car_factory::build_tire(void)
{
    return new luxury_tire;
}
body *luxury_car_factory::build_body(void)
{
    return new luxury_body;
}
car *luxury_car_factory::build_whole_car(void)
{
    car *ca=new car;
    ca->set_name("Luxury Car");
    ca->set_tire(build_tire());
    ca->set_body(build_body());
    return ca;
}
