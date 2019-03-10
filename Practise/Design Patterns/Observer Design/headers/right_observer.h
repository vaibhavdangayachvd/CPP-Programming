#ifndef RIGHT_OBSERVER
#define RIGHT_OBSERVER
#include "..\\abstract\\observer.h"
class right_observer:public observer
{
public:
    right_observer(car *ca);
    void update();
};
#endif // RIGHT_OBSERVER
