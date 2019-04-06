#ifndef PLANE_H
#define PLANE_H
#include<string>
class plane
{
    std::string name;
    std::string body;
    std::string engine;
public:
    plane(std::string p);
    std::string get_body(void);
    std::string get_engine(void);
    void set_engine(std::string e);
    void set_body(std::string b);
    void show(void);
};
#endif // PLANE_H
