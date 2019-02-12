#include "..\\headers\\simple_car_factory.h"
#include "..\\headers\\simple_body.h"
#include "..\\headers\\simple_tire.h"
tire* simple_car_factory::build_tire(void)
{
    return new simple_tire;
}
body* simple_car_factory::build_body(void)
{
    return new simple_body;
}
car* simple_car_factory::build_whole_car(void)
{
    car *ca=new car;
    ca->set_name("Simple Car");
    ca->set_tire(build_tire());
    ca->set_body(build_body());
    return ca;
}
