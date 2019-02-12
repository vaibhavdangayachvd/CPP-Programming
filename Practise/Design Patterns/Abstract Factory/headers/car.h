#ifndef CAR_H
#define CAR_H
#include "..\\abstract\\tire.h"
#include "..\\abstract\\body.h"
class car
{
    std::string name;
    tire *tr;
    body *bd;
public:
    void set_name(std::string s);
    void set_tire(tire *t);
    void set_body(body *b);
    void show_details();
    ~car();
};
#endif // CAR_H
