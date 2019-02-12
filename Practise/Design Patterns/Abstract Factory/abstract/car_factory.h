#ifndef CAR_FACTORY
#define CAR_FACTORY
#include "..\\headers\\car.h"
class car_factory
{
protected:
    virtual tire* build_tire()=0;
    virtual body* build_body()=0;
public:
    virtual car* build_whole_car()=0;
};
#endif // CAR_FACTORY
