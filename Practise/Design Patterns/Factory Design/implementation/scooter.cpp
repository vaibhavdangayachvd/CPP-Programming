#include "..\\headers\\scooter.h"
void scooter::bring_parts()
{
    std::cout<<"Bringing Scooter Parts\n";
}
void scooter::assemble()
{
    std::cout<<"Assembling Scooter Parts\n";
}
void scooter::paint()
{
    std::cout<<"Painting Scooter Parts\n";
}
void scooter::apply_lable()
{
    name=std::string("Scooter");
    price=50000;
}
void scooter::show_product()
{
    std::cout<<"Name : "<<name<<'\n'<<"Price : "<<price<<'\n';
}
