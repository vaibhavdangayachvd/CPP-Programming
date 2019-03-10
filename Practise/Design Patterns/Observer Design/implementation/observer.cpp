#include "..\\abstract\\observer.h"
observer::observer(car *c)
{
    ca=c;
    ca->attach(this);
}
observer::~observer()
{
    ca->detach(this);
}
car *observer::get_car()
{
    return ca;
}
