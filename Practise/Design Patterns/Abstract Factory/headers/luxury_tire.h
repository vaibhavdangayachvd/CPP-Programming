#ifndef LUXURY_TIRE
#define LUXURY_TIRE
#include "..\\abstract\\tire.h"
class luxury_tire:public tire
{
public:
    luxury_tire();
    std::string get_name(void);
    int get_pressure(void);
};
#endif // LUXURY_TIRE
