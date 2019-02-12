#ifndef CAR_H
#define CAR_H
#include "..\\abstract\\toy.h"
class car:public toy
{
public:
    void bring_parts();
    void assemble();
    void paint();
    void apply_lable();
    void show_product();
};
#endif // CAR_H
