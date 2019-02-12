#include "..\\headers\\car.h"
void car::bring_parts()
{
    std::cout<<"Bringing Car Parts\n";
}
void car::assemble()
{
    std::cout<<"Assembling Car Parts\n";
}
void car::paint()
{
    std::cout<<"Painting Car Parts\n";
}
void car::apply_lable()
{
    name=std::string("Car");
    price=7000000;
}
void car::show_product()
{
    std::cout<<"Name : "<<name<<'\n'<<"Price : "<<price<<'\n';
}
