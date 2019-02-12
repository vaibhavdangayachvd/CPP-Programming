#ifndef SCOOTER_H
#define SCOOTER_H
#include "..\\abstract\\toy.h"
class scooter:public toy
{
public:
    void bring_parts();
    void assemble();
    void paint();
    void apply_lable();
    void show_product();
};
#endif // SCOOTER_H
