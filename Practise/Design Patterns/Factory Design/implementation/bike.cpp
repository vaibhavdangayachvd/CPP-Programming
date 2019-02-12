#include "..\\headers\\bike.h"
void bike::bring_parts()
{
    std::cout<<"Bringing Bike Parts\n";
}
void bike::assemble()
{
    std::cout<<"Assembling Bike Parts\n";
}
void bike::paint()
{
    std::cout<<"Painting Bike Parts\n";
}
void bike::apply_lable()
{
    name="Bike";
    price=100000;
}
void bike::show_product()
{
    std::cout<<"Name : "<<name<<'\n'<<"Price : "<<price<<'\n';
}
