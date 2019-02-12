#ifndef FACTORY_H
#define FACTORY_H
#include "..\\abstract\\toy.h"
class factory
{
public:
    static toy * create_toy();
};

#endif // FACTORY_H
