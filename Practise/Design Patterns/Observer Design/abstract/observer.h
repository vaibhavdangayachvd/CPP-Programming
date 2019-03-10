#ifndef OBSERVER_H
#define OBSERVER_H
class observer;
#include "..\\headers\\car.h"
class observer
{
    car* ca;
protected:
    car *get_car();
public:
    observer(car *c);
    virtual void update()=0;
    ~observer();
};
#endif // OBSERVER_H
