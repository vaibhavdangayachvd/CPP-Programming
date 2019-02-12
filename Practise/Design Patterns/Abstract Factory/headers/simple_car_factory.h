#ifndef SIMPLE_CAR_FACTORY_H
#define SIMPLE_CAR_FACTORY_H
#include "..\\abstract\\car_factory.h"
class simple_car_factory:public car_factory
{
    tire *build_tire(void);
    body *build_body(void);
public:
    car *build_whole_car(void);
};
#endif // SIMPLE_CAR_FACTORY_H
