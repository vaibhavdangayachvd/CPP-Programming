#ifndef SIMPLE_TIRE_H
#define SIMPLE_TIRE_H
#include "..\\abstract\\tire.h"
class simple_tire:public tire
{
public:
    simple_tire();
	std::string get_name(void);
    int get_pressure(void);
};
#endif // SIMPLE_TIRE_H
