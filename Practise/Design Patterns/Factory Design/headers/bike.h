#ifndef BIKE_H
#define BIKE_H
#include "..\\abstract\\toy.h"
class bike:public toy
{
public:
    void bring_parts();
    void assemble();
    void paint();
    void apply_lable();
    void show_product();
};
#endif // BIKE_H
