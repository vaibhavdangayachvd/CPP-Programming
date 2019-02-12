#include "..\\headers\\car.h"
#include<iostream>
void car::set_name(std::string s)
{
    name=s;
}
void car::set_tire(tire *t)
{
    tr=t;
}
void car::set_body(body *b)
{
    bd=b;
}
void car::show_details()
{
    std::cout<<"Name : "<<name<<std::endl;
    std::cout<<"Tire : "<<tr->get_name()<<" Presure : "<<tr->get_pressure()<<std::endl;
    std::cout<<"Body : "<<bd->get_name()<<" Strength : "<<bd->get_strength()<<std::endl;
}
car::~car()
{
    delete tr;
    delete bd;
}
