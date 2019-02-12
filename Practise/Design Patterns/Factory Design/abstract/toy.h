#ifndef TOY_H
#define TOY_H
class toy
{
protected:
    std::string name;
    int price;
public:
    virtual void bring_parts()=0;
    virtual void assemble()=0;
    virtual void paint()=0;
    virtual void apply_lable()=0;
    virtual void show_product()=0;
};
#endif // TOY_H
