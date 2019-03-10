#ifndef LEFT_OBSERVER
#define LEFT_OBSERVER
#include "..\\abstract\\observer.h"
class left_observer:public observer
{
public:
    left_observer(car *ca);
    void update();
};
#endif // LEFT_OBSERVER
