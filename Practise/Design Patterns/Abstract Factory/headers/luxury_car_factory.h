#ifndef LUXURY_CAR_FACTORY
#define LUXURY_CAR_FACTORY
#include "..\\abstract\\car_factory.h"
class luxury_car_factory:public car_factory
{
    tire *build_tire(void);
    body *build_body(void);
public:
    car *build_whole_car(void);
};
#endif // LUXURY_CAR_FACTORY
