#ifndef CENTER_OBSERVER
#define CENTER_OBSERVER
#include "..\\abstract\\observer.h"
class center_observer:public observer
{
public:
    center_observer(car *ca);
    void update();
};
#endif // CENTER_OBSERVER
