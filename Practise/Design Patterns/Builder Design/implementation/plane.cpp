#include "..\\headers\\plane.h"
#include<iostream>
plane::plane(std::string p)
{
    name=p;
}
std::string plane::get_body(void)
{
    return body;
}
std::string plane::get_engine(void)
{
    return engine;
}
void plane::set_engine(std::string e)
{
    engine=e;
}
void plane::set_body(std::string b)
{
    body=b;
}
void plane::show(void)
{
    std::cout<<"Plane name : "<<name<<std::endl;
    std::cout<<"Plane engine : "<<engine<<std::endl;
    std::cout<<"Plane body : "<<body<<std::endl<<std::endl;
}
