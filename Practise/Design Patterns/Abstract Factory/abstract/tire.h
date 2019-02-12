#ifndef TIRE_H
#define TIRE_H
#include<string>
class tire
{
protected:
    std::string name;
    int pressure;
public:
    virtual std::string get_name(void)=0;
    virtual int get_pressure(void)=0;
};
#endif // TIRE_H
