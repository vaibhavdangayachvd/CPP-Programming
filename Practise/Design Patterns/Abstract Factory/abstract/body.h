#ifndef BODY_H
#define BODY_H
#include<string>
class body
{
protected:
    std::string name;
    int strength;
public:
    virtual std::string get_name(void)=0;
    virtual int get_strength(void)=0;
};
#endif // BODY_H
